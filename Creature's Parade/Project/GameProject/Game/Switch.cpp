#include "Switch.h"

Switch::Switch(CVector2D pos):Base(eType_Obstacle){
	m_img = COPY_RESOURCE("Switch",CImage);
	m_img.SetSize(72, 72);
	m_pos = pos;
	m_rect = CRect(0,0,72,72);
	m_cnt = 0;
	move_flag = false;
}

void Switch::Update(){
	if (move_flag) {
		if (m_cnt-- < 0) {
			move_flag = false;
		}
	}
}

void Switch::Collision(Base* b) {
	switch (b->m_type) {
	case eType_Player_Attack:
		if (CollisionRect(this, b)) {
			move_flag = true;
			m_cnt = 4 * 60;
		}
		break;
	}
}

void Switch::Draw(){
	int t = move_flag ? 0 : 32;
	m_img.SetRect(t,0,t+32,32);
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}