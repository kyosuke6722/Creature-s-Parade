#include "Switch.h"
#include"GameData.h"

Switch::Switch(CVector2D pos):Base(eType_Obstacle){
	m_img = COPY_RESOURCE("Switch",CImage);
	m_img.SetSize(72, 72);
	m_img.SetCenter(36, 36);
	m_pos =m_pos_old= pos + CVector2D(36, -36);;
	m_rect = CRect(-36,-36,36,36);
}

void Switch::Update(){
	if (GameData::s_flag) {
		if (GameData::s_cnt-- < 0) {
			GameData::s_flag = false;
		}
	}
}

void Switch::Collision(Base* b) {
	switch (b->m_type) {
	case eType_Player_Attack:
		if (CollisionRect(this, b)&&!GameData::s_flag) {
			GameData::s_cnt = 32 * 60;
			GameData::s_flag = true;
		}
		break;
	}
}

void Switch::Draw(){
	int t =GameData::s_flag? 0 : 32;
	m_img.SetRect(t,0,t+32,32);
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	//DrawRect();
}