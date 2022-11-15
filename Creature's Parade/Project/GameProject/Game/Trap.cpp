#include "Trap.h"
#include"Effect.h"

Trap::Trap(CVector2D pos):Base(eType_Obstacle) {
	m_img = COPY_RESOURCE("LaunchPad", CImage);
	m_img.ChangeAnimation(0);
	m_pos = pos;
	m_img.SetSize(16*10,16*10);
	m_img.SetCenter(8*10,0);
	m_rect = CRect(-5*10,8*8,5*10,16*10);
	m_hp = 3;
	m_fire = true;
}

Trap::~Trap(){
}

void Trap::Update() {
	m_img.UpdateAnimation();
	if (m_img.GetIndex() == 3 && m_fire) {
		Base::Add(new Effect("Fire", m_pos + CVector2D(0, 32 * 2)));
		m_fire = false;
	}
	if (m_img.GetIndex() == 6) {
		m_fire = true;
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
