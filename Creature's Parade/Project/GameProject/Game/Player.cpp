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
	m_hp = 3;//�̗�
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
	if (m_scroll.y > 72 * 9 - 600)
		m_scroll.y = 72 * 9 - 600;
}

void Player::Collision(Base* b) {
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
		}
		break;
	case eType_Effect:
	case eType_Enemy_Attack:
		if (CollisionRect(this, b)&&m_invincible<=0) {
			int r = rand() % 2;
			m_hp--;
			if (m_hp <= 0){
				m_state = eState_Down;
				if (r == 0)
					SOUND("Voice_Player_down1")->Play();
				else
					SOUND("Voice_Player_down2")->Play();
			}
			else {
				m_state = eState_Damage;
				if (r == 0)
					SOUND("Voice_Player_damage1")->Play();
				else
					SOUND("Voice_Player_damage2")->Play();
			}
			m_invincible = 2 * 60;
		}
		break;
	case eType_Creature:
	case eType_Friend:
			if (Base::CollisionRect(this, b)) {
				if (Creature* c = dynamic_cast<Creature*>(b)) {
					if (!c->m_player) {
						c->m_player = this;//�e��player�ɐݒ�
						c->m_friend = true;//���ԃt���OON
						m_creature.push_back(c);//list��creature��ǉ�
						c->m_column = ++m_bring;//�A��Ă��鐔���X�V
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
	if (PUSH(CInput::eDown))
		GatherCreature();
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
	//����
	if (PUSH(CInput::eMouseL)) {
		ThrowCreature();
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
	//if (m_img.CheckAnimationEnd()) {
	//}
}

void Player::EraseCreature(Creature* c){
	auto it = std::find(m_creature.begin(), m_creature.end(), c);//���X�g����q������
	(*it)->m_friend = false;//���ԃt���O������
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
		SOUND("SE_Throw")->Play();
		m_bring--;
		for (it; it != it2; it++) {
			(*it)->m_column--;
		}
	}
}

void Player::GatherCreature(){
	auto it = m_list.begin();
	auto last = m_list.end();
	while (it != last) {
		if ((*it)->m_type ==eType_Friend) {
			(*it)->m_vec = CVector2D(0, 0);
			(*it)->m_pos = m_pos + CVector2D(0, -72 * 2);
		}
		it++;
	}
}
