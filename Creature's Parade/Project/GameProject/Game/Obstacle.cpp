#include "Obstacle.h"

Obstacle::Obstacle(CVector2D pos, int hp) :Base(eType_Obstacle) {
	m_img = COPY_RESOURCE("Obstacle", CImage);
	m_img.SetRect(15, 32, 386, 323);
	m_img.SetSize(72 * 9, 72 * 7);
	m_img.SetCenter(36 * 9, 72 * 7);
	m_rect = CRect(-36*9, -72*7, 36 * 9,0);
	m_gauge = COPY_RESOURCE("Gauge", CImage);
	m_pos = pos;
	m_hp = m_max_hp = hp;
	m_par = 0;
	m_gauge_cnt = 0;
}

Obstacle::~Obstacle(){
}

void Obstacle::Update(){
	SetValue((float)m_hp/m_max_hp);
	if (m_gauge_cnt > 0) {
		m_gauge_cnt--;
	}
}

void Obstacle::Collision(Base* b){
	switch (b->m_type) {
	case eType_Player_Attack:
		if (CollisionRect(this, b)) {
			m_hp--;
			SOUND("SE_Obstacle_damage")->Play();
			if (m_hp <= 0) {
				SOUND("SE_Obstacle_broken")->Play();
				SetKill();
			}
			m_gauge_cnt = 2 * 60;
		}
		break;
	}
	
}

void Obstacle::Draw(){
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	DrawRect();
	
	if (m_gauge_cnt > 0) {
		//˜g‚Ì•\¦
		m_gauge.SetRect(0, 0, 256, 64);
		m_gauge.SetSize(256, 64);
		m_gauge.SetPos(GetScreenPos(m_pos + CVector2D(-18 * 9, -36 * 9)));
		m_gauge.Draw();

		//ƒQ[ƒW‚Ì•\¦
		//ƒQ[ƒW‚Ì’·‚³ 4‚Í˜g‚Ì‘¾‚³
		int border = 4;
		int width = (256 - border - border) * m_par;
		int m_gauge_type = 0;
		if (m_par < 0.4)
			m_gauge_type = 1;
		int y = (m_gauge_type + 1);
		m_gauge.SetRect(border, (64 * y) + border, 4 + width, (64 * (y + 1)) - border);
		m_gauge.SetSize(width, 64 - border - border);
		m_gauge.SetPos(GetScreenPos(m_pos + CVector2D(border - 18 * 9, border - 36 * 9)));
		m_gauge.Draw();
	}
}

void Obstacle::SetValue(float par){
	m_par = par;
}
