#include "Obstacle.h"

Obstacle::Obstacle(CVector2D pos, int hp) :Base(eType_Obstacle) {
	m_img = COPY_RESOURCE("Obstacle", CImage);
	m_gauge = COPY_RESOURCE("Gauge", CImage);
	m_img.SetRect(15, 32, 386, 323);
	m_img.SetSize(72 * 9, 72 * 7);
	m_rect = CRect(0, 0, 72 * 9, 72 * 7);
	m_pos = pos;
	m_hp = m_max_hp = hp;
	m_par = 0;
}

Obstacle::~Obstacle(){
}

void Obstacle::Update(){
	SetValue((float)m_hp/m_max_hp);
}

void Obstacle::Collision(Base* b){
	switch (b->m_type) {
	case eType_Player_Attack:
		if (CollisionRect(this, b)) {
			m_hp--;
			if (m_hp <= 0)
				SetKill();
		}
		break;
	}
	
}

void Obstacle::Draw(){
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	//DrawRect();
	
	//˜g‚Ì•\Ž¦
	m_gauge.SetRect(0, 0, 256, 64);
	m_gauge.SetSize(256, 64);
	m_gauge.SetPos(GetScreenPos(m_pos));
	m_gauge.Draw();

	//ƒQ[ƒW‚Ì•\Ž¦
	//ƒQ[ƒW‚Ì’·‚³ 4‚Í˜g‚Ì‘¾‚³
	int border=4;
	int width = (256 - border - border)*m_par;
	int m_gauge_type=0;
	if (m_par < 0.4)
		m_gauge_type = 1;
	int y = (m_gauge_type + 1);
	m_gauge.SetRect(border, (64*y) + border, 4+width, (64 * (y+1)) - border);
	m_gauge.SetSize(width, 64 - border - border);
	m_gauge.SetPos(GetScreenPos(m_pos+CVector2D(border, border)));
	m_gauge.Draw();
}

void Obstacle::SetValue(float par){
	m_par = par;
}
