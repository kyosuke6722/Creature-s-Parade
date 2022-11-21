#include "Arrow.h"

Arrow::Arrow(CVector2D pos):Base(eType_Enemy_Attack){
	m_img = COPY_RESOURCE("Arrow", CImage);
	SOUND("SE_Arrow")->Play();
	m_img.SetSize(16*10,16*10);
	m_img.SetCenter(8*10, 3*10);
	m_rect = CRect(-4*10,0, 4*10,11*10);
	m_pos = pos;
}

void Arrow::Update(){
	const int move_speed = 6;
	m_pos.y -= move_speed;
}

void Arrow::Collision(Base* b){
	switch (b->m_type) {
	case eType_Field:
	case eType_Obstacle:
	case eType_Player:
	case eType_Player_Attack:
		if (CollisionRect(this, b)) {
			SetKill();
		}
		break;
	}
}

void Arrow::Draw(){
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	DrawRect();
}
