#include "Arrow.h"
#include"Map.h"

Arrow::Arrow(CVector2D pos,int ang):Base(eType_Enemy_Attack){
	m_img = COPY_RESOURCE("Arrow", CImage);
	SOUND("SE_Arrow")->Play();
	m_img.SetSize(7*10,11*10);
	m_img.SetCenter(3.5*10, 5.5*10);
	m_ang =DtoR(ang*90-180);
	m_bullet_ang=ang;
	switch (m_bullet_ang) {
	case 0:
	case 2:
		m_rect = CRect(-3.5 * 10, -5.5 * 10, 3.5 * 10, 5.5 * 10);
		break;
	case 1:
	case 3:
		m_rect = CRect(-5.5 * 10, -3.5 * 10, 5.5 * 10, 3.5 * 10);
		break;
	}
	m_pos = pos;
}

void Arrow::Update(){
	const int move_speed = 6;
	switch (m_bullet_ang) {
	case 0://上向き
		m_pos.y -= move_speed;
		break;
	case 1://左向き
		m_pos.x -= move_speed;
		break;
	case 2://下向き
		m_pos.y += move_speed;
		break;
	case 3://右向き
		m_pos.x += move_speed;
		break;
	}
}

void Arrow::Collision(Base* b) {
	switch (b->m_type) {
	case eType_Field:
		if (Map* m = dynamic_cast<Map*>(b)) {
			//マップチップの判定（横）
			int t = m->CollisionMap(CVector2D(m_pos.x, m_pos.y));
			//壁ならば
			if (t != 0)
				SetKill();
		}
			break;
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
	m_img.SetAng(m_ang);
	m_img.Draw();
	//DrawRect();
}
