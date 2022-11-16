#include "Player.h"
#include"AnimData.h"
#include"Creature.h"
#include"Map.h"

Player::Player(CVector2D pos,bool flip):Base(eType_Player) {
	m_img = COPY_RESOURCE("Player", CImage);
	m_img.ChangeAnimation(0);
	m_img.SetSize(32* 4, 32* 4);
	m_img.SetCenter(32*2, 32 * 4);
	m_rect = CRect(-7*4,-10*8,7*4,0);
	m_pos = m_pos_old = pos;
	m_flip = flip;
	m_state = eState_Idle;
	m_is_ground = true;
	m_hp = 2;//�̗�
	m_invincible=0;//���G����
	m_bring = 0;//�A��Ă��鐔
}

void Player::Update() {
	m_pos_old = m_pos;
	switch (m_state)
	{
	case eState_Idle:
		StateIdle();
		break;
	case eState_Throw:
		StateThrow();
		break;
	case eState_Damage:
		StateDamage();
		break;
	case eState_Down:
		StateDown();
		break;
	}
	//�����Ă����痎����Ԃֈڍs
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	m_vec.y += GRAVITY;//�d�͂ɂ�闎��
	m_pos += m_vec;

	if (m_invincible > 0)
		m_invincible--;

	m_img.UpdateAnimation();

	//�X�N���[���ݒ�
	m_scroll.x = m_pos.x - 1920 / 2;
	if (m_scroll.x < 14 * 72 - 1920 / 2)
		m_scroll.x = 14 * 72 - 1920 / 2;
	m_scroll.y = m_pos.y - 600;
	if (m_scroll.y > 72 * 16 - 600)
		m_scroll.y = 72 * 16 - 600;
}

void Player::Collision(Base* b) {
	switch (b->m_type) {
	case eType_Field:
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y));
			if (t != 0) {
				m_pos.x = m_pos_old.x;
			}
			t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y));
			if (t != 0) {
				m_pos.y = m_pos_old.y;//���̍����ɖ߂�
				m_vec.y = 0;//�������x���Z�b�g
				m_is_ground = true;//�ڒn�t���OON
			}
		}
		break;
	case eType_Obstacle:
		if (CollisionRect(this, b)) {
			m_pos.x = m_pos_old.x;
		}
		break;
	case eType_Effect:
		if (CollisionRect(this, b)&&m_invincible<=0) {
			m_hp--;
			if (m_hp <= 0)
				m_state = eState_Down;
			else
				m_state = eState_Damage;
			m_invincible = 3 * 60;
		}
		break;
	case eType_Creature:
		if (m_state != eState_Throw) {
			if (Base::CollisionRect(this, b)) {
				if (Creature* c = dynamic_cast<Creature*>(b)) {
					if (!c->m_player) {
						c->m_player = this;//�e��player�ɐݒ�
						m_creature.push_back(c);//list��creature��ǉ�
						c->m_column = ++m_bring;
					}
				}
			}
		}
		break;
	}
}

void Player::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
	//DrawRect();
}

void Player::StateIdle() {
	const float move_speed = 6;
	const float jump_pow = 15;
	//�E�ړ�
	if (HOLD(CInput::eRight)) {
		m_pos.x += move_speed;
		m_flip = true;
		m_img.ChangeAnimation(eAnimRun);
	}
	//���ړ�
	else if (HOLD(CInput::eLeft)) {
		m_pos.x -= move_speed;
		m_flip = false;
		m_img.ChangeAnimation(eAnimRun);
	}
	else {
			m_img.ChangeAnimation(eAnimIdle);
	}
	//�W�����v
	if (m_is_ground && PUSH(CInput::eUp)) {
		m_vec.y = -jump_pow;
		m_is_ground = false;
			m_img.ChangeAnimation(eAnimRun);
	}
	//����
	if (PUSH(CInput::eMouseL)) {
		m_state = eState_Throw;
		ThrowCreature();
	}
}

void Player::StateThrow(){
	const float move_speed = 6;
	const float jump_pow = 15;
	//�E�ړ�
	if (HOLD(CInput::eRight)) {
		m_pos.x += move_speed;
		m_flip = true;
	}
	//���ړ�
	else if (HOLD(CInput::eLeft)) {
		m_pos.x -= move_speed;
		m_flip = false;
	}
	m_img.ChangeAnimation(eAnimThrow,false);
	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;
	}
}

void Player::StateDamage(){
	m_img.ChangeAnimation(eAnimDamage, false);
	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;
	}
}

void Player::StateDown(){
	m_img.ChangeAnimation(eAnimDown, false);
	if (m_img.CheckAnimationEnd()) {
		SetKill();
	}
}

void Player::EraseCreature(Creature* c){
	auto it = std::find(m_creature.begin(), m_creature.end(), c);//���X�g����q������
	(*it)->m_player = nullptr;//�q�@�e������
	m_creature.erase(it);//�e�@�q�����X�g����O��
}

void Player::ThrowCreature() {
	auto it = m_creature.begin();
	auto it2 = m_creature.end();
	if (it != it2) {
		CVector2D vec = CInput::GetMousePoint() - GetScreenPos(m_pos);//(��ʏ�ł̖ړI�n)-(��ʏ�ł̌��ݒn)
		(*it)->m_vec = vec.GetNormalize()*20.0f;
		(*it)->m_type = eType_Player_Attack;
		(*it)->m_player = nullptr;
		it = m_creature.erase(it);
		m_bring--;
		for (it; it != it2; it++) {
			(*it)->m_column--;
		}
	}
}
