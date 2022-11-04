#include "Trap.h"

Trap::Trap():Base(eType_Obstacle) {
	//m_img = COPY_RESOURCE("", CImage);
	m_hp = 5;
}

Trap::~Trap(){
}

void Trap::Update(){
}

void Trap::Collision(Base* b){
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

void Trap::Draw(){
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}
