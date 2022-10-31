#include "Player.h"
#include"Creature.h"
#include"Map.h"

Player::Player(CVector2D pos,bool flip):Base(eType_Player) {
	//通常状態
	m_img = COPY_RESOURCE("Player", CImage);
	m_img.SetRect(69, 38, 519, 778);
	m_img.SetSize(45,74);
	m_img.SetCenter(45/2, 74);
	//投擲状態
	m_throw = COPY_RESOURCE("Player_throw", CImage);
	m_throw.SetRect(219, 52, 707, 795);
	m_throw.SetSize(45,74);
	m_throw.SetCenter(45 / 2, 74);

	m_rect = CRect(-45/2,-74,45/2,0);
	m_pos = m_pos_old = pos;
	m_flip = flip;
	m_cnt = 0;
	m_state = eState_Idle;
	m_is_ground = true;
}

void Player::Update(){
	m_pos_old = m_pos;
		StateIdle();
		switch (m_state)
		{
		case eState_Throw:
			StateThrow();
			break;
		}
		//落ちていたら落下状態へ移行
		if (m_is_ground && m_vec.y > GRAVITY * 4)
			m_is_ground = false;
		m_vec.y += GRAVITY;//重力による落下
		m_pos += m_vec;

		m_scroll.x = m_pos.x-1920 / 2;//スクロール設定
		m_scroll.y = m_pos.y - 600;
}

void Player::Collision(Base* b){
	switch (b->m_type) {
	case eType_Field:
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y));
			if (t != 0) {
				m_pos.x = m_pos_old.x;
			}
			t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y));
			if (t != 0) {
				m_pos.y = m_pos_old.y;//元の高さに戻す
				m_vec.y = 0;//落下速度リセット
				m_is_ground = true;//接地フラグON
			}
		}
		break;
	case eType_Creature:
		if (Base::CollisionRect(this, b)) {
			if (Creature* c = dynamic_cast<Creature*>(b)) {
				if (!c->m_player) {
					c->m_player = this;//親をplayerに設定
					m_creature.push_back(c);//listにcreatureを追加
				}
			}
		}
		break;
	}
}

void Player::Draw(){
	switch (m_state) {
	case eState_Idle:
		m_img.SetPos(GetScreenPos(m_pos));
		m_img.SetFlipH(m_flip);
		m_img.Draw();
		break;
	case eState_Throw:
		m_throw.SetPos(GetScreenPos(m_pos));
		m_throw.SetFlipH(m_flip);
		m_throw.Draw();
		break;
	}
}

void Player::StateIdle(){
	const float move_speed = 6;
	const float jump_pow = 15;
	//右移動
	if (HOLD(CInput::eRight)) {
		m_pos.x += move_speed;
		m_flip = true;
	}
	//左移動
	else if (HOLD(CInput::eLeft)) {
		m_pos.x -= move_speed;
		m_flip = false;
	}
	//ジャンプ
	if (m_is_ground && PUSH(CInput::eUp)) {
		m_vec.y =- jump_pow;
		m_is_ground = false;
	}
	//投げ
	if (PUSH(CInput::eMouseL)) {
		m_state = eState_Throw;
		ThrowCreature();
		m_cnt = 0.5 * 60;
	}
}

void Player::StateThrow(){
	if (m_cnt-- < 0) {
		m_state = eState_Idle;
	}
}

void Player::EraseCreature(Creature* c){
	auto it = std::find(m_creature.begin(), m_creature.end(), c);//リストから子を検索
	(*it)->m_player = nullptr;//子　親を解除
	m_creature.erase(it);//親　子をリストから外す
}

void Player::ThrowCreature() {
	auto it = m_creature.begin();
	auto it2 = m_creature.end();
	if (it != it2) {
		(*it)->m_vec = CVector2D(50, -15);
		(*it)->m_player = nullptr;
		it = m_creature.erase(it);
	}
}
