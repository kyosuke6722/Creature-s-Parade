#include "Obstacle.h"

Obstacle::Obstacle(CVector2D pos,int hp):Base(eType_Obstacle) {
	m_img = COPY_RESOURCE("Obstacle", CImage);
	m_img.SetRect(15, 32, 386, 323);
	m_img.SetSize(72*9, 72*7);
	m_rect = CRect(0,0,72*9,72*7);
	m_pos = pos;
	m_hp = hp;
}

Obstacle::~Obstacle(){
}

void Obstacle::Collision(Base* b){
	switch (b->m_type) {
	case eType_Creature:
		if (CollisionRect(this, b)) {
			m_hp--;
			if (m_hp <= 0)
				SetKill();
		}
		break;
	}
	
}

void Obstacle::Draw(){
	m_img.SetPos(m_pos);
	m_img.Draw();
	DrawRect();
}
