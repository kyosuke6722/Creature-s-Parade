#include "Player.h"

Player::Player(CVector2D pos,bool flip):Base(eType_Player) {
	m_img = COPY_RESOURCE("Player", CImage);
	m_img.SetRect(69, 38, 519, 778);
	m_img.SetSize(45,74);
	m_throw = COPY_RESOURCE("Player_throw", CImage);
	m_throw.SetRect(219, 52, 707, 795);
	m_throw.SetSize(45,74);
	m_pos = pos;
	m_flip = flip;
	m_state = eState_Idle;
}

void Player::Update(){
	switch (m_state) {
	case eState_Idle:
		StateIdle();
		break;
	case eState_Throw:
		StateThrow();
		break;
	}
}

void Player::Draw(){
	switch (m_state) {
	case eState_Idle:
		m_img.SetPos(m_pos);
		m_img.SetFlipH(m_flip);
		m_img.Draw();
		break;
	case eState_Throw:
		m_throw.SetPos(m_pos);
		m_throw.SetFlipH(m_flip);
		m_throw.Draw();
		break;
	}
}

void Player::StateIdle(){
	const float move_speed = 6;
	if (HOLD(CInput::eRight)) {
		m_pos.x += move_speed;
		m_flip = true;
	}
	if (HOLD(CInput::eLeft)) {
		m_pos.x -= move_speed;
		m_flip = false;
	}
	if (PUSH(CInput::eMouseL)) {
		m_state = eState_Throw;
	}
}

void Player::StateThrow(){
	int m_cnt = 2 * 60;
	if (m_cnt-- < 0) {
		m_state = eState_Idle;
	}
}
