#include "Trap.h"
#include"Effect.h"
#include"Arrow.h"

Trap::Trap(CVector2D pos,int bullet_type):Base(eType_Obstacle) {
	m_img = COPY_RESOURCE("LaunchPad", CImage);
	m_img.ChangeAnimation(0);
	m_pos =m_pos_old= pos;
	m_bullet_type = bullet_type;
	m_img.SetSize(16*7.2,16*7.2);
	m_img.SetCenter(8*7.2,16*7.2);
	m_rect = CRect(-36,-72,36,0);
	m_hp = 5;
	m_fire = true;
}

Trap::~Trap(){
}

void Trap::Update() {
	m_img.UpdateAnimation();
		if (m_img.GetIndex() == 3 && m_fire) {
			switch (m_bullet_type) {
			case Bullet_fire:
				Base::Add(new Effect("Fire", m_pos + CVector2D(0, -10*7.2)));
				break;
			case Bullet_arrow:
				Base::Add(new Arrow(m_pos + CVector2D(0, -25 * 10)));
				break;
			}
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
	//m_img.SetAng(m_ang);
	m_img.Draw();
	DrawRect();
}
