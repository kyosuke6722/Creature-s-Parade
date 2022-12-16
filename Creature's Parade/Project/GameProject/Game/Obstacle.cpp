#include "Obstacle.h"

Obstacle::Obstacle(CVector2D pos, int hp,float size) :Base(eType_Obstacle) {
	m_img = COPY_RESOURCE("Rock", CImage);
	m_rock_type = rand() % 13;
	m_img.SetRect(m_rock_type*18, 0, (m_rock_type+1)*18, 18);
	m_img.SetSize(72*size, 72 * size);
	m_img.SetCenter(72 * (size/2), 72 * size);
	m_rect = CRect(-72*(size/2), -56 * size, 72 * (size/2), 0);
	m_gauge = COPY_RESOURCE("Gauge", CImage);
	m_pos = m_pos_old = pos+CVector2D(72 * (size / 2), 0);
	m_hp = m_max_hp = hp;
	m_par = 0;
	m_gauge_cnt = 0;
	gauge_size = size;
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
	//DrawRect();
	
	if (m_gauge_cnt > 0) {
		//˜g‚Ì•\¦
		m_gauge.SetRect(0, 0, 256, 64);
		m_gauge.SetSize(32*gauge_size, 8*gauge_size);
		m_gauge.SetPos(GetScreenPos(m_pos+CVector2D(-16*gauge_size,-24*gauge_size)));
		m_gauge.Draw();

		//ƒQ[ƒW‚Ì•\¦
		//ƒQ[ƒW‚Ì’·‚³ 4‚Í˜g‚Ì‘¾‚³
		float border = 0.5*gauge_size;
		int width = (32*gauge_size - border - border) * m_par;
		int m_gauge_type = 0;
		if (m_par < 0.4)
			m_gauge_type = 1;
		int y = (m_gauge_type + 1);
		m_gauge.SetRect(border, (64 * y) + border, 4 + width, (64 * (y + 1)) - border);
		m_gauge.SetSize(width, 8*gauge_size - border - border);
		m_gauge.SetPos(GetScreenPos(m_pos + CVector2D(border-16*gauge_size, border-24*gauge_size)));
		m_gauge.Draw();
	}
}

void Obstacle::SetValue(float par){
	m_par = par;
}
