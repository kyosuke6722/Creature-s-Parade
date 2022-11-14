#include "Trap.h"
#include"Effect.h"

Trap::Trap(CVector2D pos):Base(eType_Obstacle) {
	m_img = COPY_RESOURCE("LaunchPad", CImage);
	m_img.ChangeAnimation(0,true);
	m_pos = pos;
	m_img.SetSize(16*5,16*5);
	m_img.SetCenter(8*5,0);
	m_rect = CRect(-5*5,8*4,5*5,16*5);
	m_hp = 5;
	m_cnt = 3 * 60;//クールタイム
}

Trap::~Trap(){
}

void Trap::Update(){
	if (m_cnt-- < 0) {
		m_img.UpdateAnimation();
		if (m_img.GetIndex() == 0) {
			Base::Add(new Effect("Fire", m_pos));
		}
		if (m_img.CheckAnimationEnd()) {
			m_cnt = 3 * 60;
		}
	}
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
	DrawRect();
}
