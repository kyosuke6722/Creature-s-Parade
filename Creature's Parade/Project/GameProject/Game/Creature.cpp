#include "Creature.h"
#include"Player.h"
#include"Map.h"

Creature::Creature(CVector2D pos,bool flip):Base(eType_Creature) {
	m_img = COPY_RESOURCE("Creature", CImage);
	m_img.SetRect(62, 35, 688, 755);
	m_img.SetSize(45, 74);
	m_img.SetCenter(45 / 2, 74);
	m_rect = CRect(-45/2,-74,45/2,0);
	m_pos = pos;
	m_flip = flip;
	m_state = eState_Idle;
	m_is_ground = true;
	m_player = nullptr;
	m_column = 0;//0—ñ–Ú(Player‚É‚Â‚¢‚Ä‚¢‚È‚¢)
}

Creature::~Creature(){
	if (m_player)
		m_player->EraseCreature(this);
}

void Creature::Update() {
	m_pos_old = m_pos;
	switch (m_state) {
	case eState_Idle:
		StateIdle();
		break;
		/*
	case eState_Throw:
		StateThrow();
		break;
		*/
	}
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	m_vec.y += GRAVITY;
	m_pos += m_vec;
}

void Creature::Collision(Base* b) {
	switch (b->m_type) {
	case eType_Field:
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y));
			if (t != 0) {
				m_pos.x = m_pos_old.x;
				m_vec.x = 0;
				m_type = eType_Creature;
			}
			t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y));
			if (t != 0) {
				m_pos.y = m_pos_old.y;
				m_vec.y = 0;
				m_is_ground = true;
				m_vec.x *= 0.8;//–€C
				m_type = eType_Creature;
			}
		}
		break;
	case eType_Obstacle:
		if (CollisionRect(this, b)) {
			m_pos.x = m_pos_old.x;
			m_vec.x = 0;
		}
		break;
		/*
	case eType_Player:
		if (CollisionRect(this, b)) {
			m_state=eState_Throw;
		}
		break;
		*/
	}
}

void Creature::Draw(){
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
}

void Creature::StateIdle(){
	const float move_speed = 6;
	const float jump_pow = 15;
	if (m_player) {
		if (Player* p = dynamic_cast<Player*>(Base::FindObject(eType_Player))) {
			//ƒWƒƒƒ“ƒv
			if (m_is_ground && PUSH(CInput::eUp)) {
				m_vec.y = -jump_pow;
				m_is_ground = false;
			}
			CVector2D vec = CVector2D(0, 0);
			if (HOLD(CInput::eRight))
				vec = m_player->m_pos - m_pos - CVector2D(m_column * 30, 0);
			else if(HOLD(CInput::eLeft))
				vec = m_player->m_pos - m_pos + CVector2D(m_column * 30, 0);
			m_ang = atan2(vec.x, vec.y);
			CVector2D dir(sin(m_ang),0);
			//e‚Ì•ûŒü‚ÖˆÚ“®
			m_pos += dir * move_speed;
		}
	}
}

/*
void Creature::StateThrow(){
	Player* p = dynamic_cast<Player*>(Base::FindObject(eType_Player));
	m_flip = p->m_flip;
	if (p) {
		if (m_flip)
			m_pos.x = p->m_pos.x - 45;
		else
			m_pos.x = p->m_pos.x + 45;
		const float jump_pow = 15;
		if (m_is_ground && PUSH(CInput::eButton5)) {
			m_vec.y = -jump_pow;
			m_is_ground = false;
		}
	}
}
*/
