#include "Platform.h"
#include"Switch.h"
#include"Player.h"
#include"Creature.h"
#include"GameData.h"

Platform::Platform(CVector2D pos):Base(eType_Platform){
	m_img = COPY_RESOURCE("Platform", CImage);
	m_img.SetCenter(180,18);
	m_rect = CRect(-180,-18,180,18);
	m_pos =m_pos_old= pos;
	m_move_speed = -1.2f;
	m_cnt = 4*60;
}

void Platform::Update() {
	if (GameData::s_flag) {
		if (m_cnt--<0) {
			m_move_speed *= -1;
			m_cnt = 4*60;
		}
		m_pos.y += m_move_speed;
	}
}

void Platform::Collision(Base* b) {
	switch (b->m_type) {
	case eType_Player:
		if (Player* p = dynamic_cast<Player*>(b)) {
			if (CollisionRect(this, b)) {
				//ã‰º‚Ì”»’è
				if (CollisionRectTB(this, b)) {
					p->OnPlatform(this);
				}
			}
			else
				p->m_on_platform = false;
		}
		break;
	case eType_Creature:
	case eType_Friend:
	case eType_Player_Attack:
		if (Creature* c = dynamic_cast<Creature*>(b)) {
			if (CollisionRect(this, b)) {
				//ã‰º‚Ì”»’è
				if (CollisionRectTB(this, b)) {
					c->OnPlatform(this);
				}
			}
			else
				c->m_on_platform = false;
		}
		break;
	}
}

void Platform::Draw(){
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	//DrawRect();
}