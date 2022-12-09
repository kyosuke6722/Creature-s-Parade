#include "Switch.h"

Switch::Switch():Base(eType_Obstacle){
	//m_img = COPY_RESOURCE("",CImage);
	//m_rect = CRect();
	move_flag = false;
}

void Switch::Update(){
}

void Switch::Collision(Base* b) {
	switch (b->m_type) {
	case eType_Player_Attack:
		if (CollisionRect(this, b)) {
			move_flag = true;
		}
		break;
	}
}

void Switch::Draw(){
	//m_img.SetPos(m_pos);
	//m_img.Draw();
}