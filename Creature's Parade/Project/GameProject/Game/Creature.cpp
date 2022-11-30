#include "Creature.h"
#include"Player.h"
#include"Map.h"
#include"AnimData.h"

Creature::Creature(const char* name, CVector2D pos, bool flip) :Base(eType_Creature) {
	m_img = COPY_RESOURCE(name, CImage);
	m_img.ChangeAnimation(eAnimIdle);
	m_img.SetSize(32 * 4, 32 * 4);
	m_img.SetCenter(16 * 4, 32 * 4);
	m_rect = CRect(-7 * 4, -10 * 8, 7 * 4, 0);
	m_pos = m_pos_old = pos;
	m_flip = flip;
	m_state = eState_Idle;
	m_is_ground = true;
	m_player = nullptr;
	m_friend = false;
	m_column = 0;//0���(Player�ɂ��Ă��Ȃ�)
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
	m_img.UpdateAnimation();
}

void Creature::Collision(Base* b) {
	switch (b->m_type) {
	case eType_Field:
		//�}�b�v�Ƃ̔���
		if (Map* m = dynamic_cast<Map*>(b)) {
			CVector2D pos;
			//�}�b�v�`�b�v�̔���i���j
			int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y), m_rect, &pos);
			//�ǂȂ��
			if (t != 0) {
				//�Ǎۂ܂Ŗ߂�
				m_pos.x = pos.x;
			}
			//�}�b�v�`�b�v�̔���i�㉺�j
			t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y), m_rect, &pos);
			//�ǂȂ��
			if (t != 0) {
				//�n�ʂɐڐG
				if (pos.y < m_pos.y) {
					//�W�����v�񐔃��Z�b�g
					m_is_ground = true;
					m_vec.x *= 0.8;//���C
					ChangeType();
				}
				//���̈ʒu�ɖ߂�
				m_pos.y = pos.y;
				//�������x���Z�b�g
				m_vec.y = 0;

			}
		}
		break;
	case eType_Obstacle:
		if (CollisionRect(this, b)) {
			//�㉺�̔���
			if (CollisionRectTB(this, b)) {
				//�n�ʂɐڐG
				if (b->m_pos.y > m_pos.y) {
					//�W�����v�񐔃��Z�b�g
					m_is_ground = true;
				}
				//���̈ʒu�ɖ߂�
				m_pos.y = m_pos_old.y;
				//�������x���Z�b�g
				m_vec.y = 0;
			}
			//���̔���
			else
				m_pos.x = m_pos_old.x;
			m_vec.x = 0;
			ChangeType();
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
	//DrawRect();
}

void Creature::StateIdle() {
	if (m_player) {
		if (Player* p = dynamic_cast<Player*>(Base::FindObject(eType_Player))) {
			const float move_speed = 6;
			const float jump_pow = 15;
			//�W�����v
			if (m_is_ground && PUSH(CInput::eUp)) {
				m_vec.y = -jump_pow;
				m_is_ground = false;
			}
			CVector2D vec;
			if (m_player->m_flip) {
				vec = m_player->m_pos - m_pos -CVector2D(m_column * 64, 0);
				m_flip = true;
			}
			else {
				vec = m_player->m_pos - m_pos + CVector2D(m_column * 64, 0);
				m_flip = false;
			}
			if (vec.Length() > m_column*64*0.1) {
				m_ang = atan2(vec.x, vec.y);
				CVector2D dir(sin(m_ang), 0);
				//�e�̕����ֈړ�
				m_pos += dir * move_speed;
			}
		}
	}
	if (m_pos != m_pos_old)
		m_img.ChangeAnimation(eAnimRun);
	else
		m_img.ChangeAnimation(eAnimIdle);

}

void Creature::ChangeType(){
	if (m_friend)
		m_type = eType_Friend;
	else
		m_type = eType_Creature;
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
