#include "Trap.h"
#include"Effect.h"
#include"Arrow.h"

Trap::Trap(CVector2D pos,int bullet_type,int ang):Base(eType_Obstacle) {
	m_img = COPY_RESOURCE("LaunchPad", CImage);
	m_img.ChangeAnimation(0);
	m_pos = m_pos_old = pos+CVector2D(36,36);
	m_bullet_type = bullet_type;
	m_img.SetSize(72,72);
	m_img.SetCenter(36,36);
	m_bullet_ang = ang;
	m_ang = DtoR(90 * ang);
	m_rect = CRect(-36,-36,36,36);
	m_gauge = COPY_RESOURCE("Gauge", CImage);
	m_hp =m_max_hp= 5;
	m_par = 0;
	m_gauge_cnt = 0;
	m_fire = true;
}

Trap::~Trap(){
}

void Trap::Update() {
	m_img.UpdateAnimation();
	if (m_img.GetIndex() == 3 && m_fire) {
		switch (m_bullet_type) {
		case Bullet_fire:
			switch (m_bullet_ang) {
			case 0://上向き
				Base::Add(new Effect("Fire", m_pos + CVector2D(0, -36), m_bullet_ang));
				break;
			case 1://左向き
				Base::Add(new Effect("Fire", m_pos + CVector2D(-36, 0), m_bullet_ang));
				break;
			case 2://下向き
				Base::Add(new Effect("Fire", m_pos + CVector2D(0, 36), m_bullet_ang));
				break;
			case 3://右向き
				Base::Add(new Effect("Fire", m_pos + CVector2D(36, 0), m_bullet_ang));
				break;
			}
			break;
		case Bullet_arrow:
			switch (m_bullet_ang) {
			case 0://上向き
				Base::Add(new Arrow(m_pos + CVector2D(0, -36 - 55), m_bullet_ang));
				break;
			case 1://左向き
				Base::Add(new Arrow(m_pos + CVector2D(-36 - 55, 0), m_bullet_ang));
				break;
			case 2://下向き
				Base::Add(new Arrow(m_pos + CVector2D(0, 36 + 55), m_bullet_ang));
				break;
			case 3://右向き
				Base::Add(new Arrow(m_pos + CVector2D(36 + 55, 0), m_bullet_ang));
				break;
			}
			break;
		}
		m_fire = false;
	}
	if (m_img.GetIndex() == 6) {
		m_fire = true;
	}

	SetValue((float)m_hp / m_max_hp);
	if (m_gauge_cnt > 0) {
		m_gauge_cnt--;
	}
}

void Trap::Collision(Base* b){
	switch (b->m_type) {
	case eType_Player_Attack:
		if (CollisionRect(this, b)) {
			m_hp--;
			if (m_hp <= 0)
				SetKill();
			m_gauge_cnt = 1 * 60;
		}
		break;
	}
}

void Trap::Draw(){
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetAng(m_ang);
	m_img.Draw();
	//DrawRect();

	if (m_gauge_cnt > 0) {
		//枠の表示
		m_gauge.SetRect(0, 0, 256, 64);
		m_gauge.SetSize(32, 8);
		m_gauge.SetPos(GetScreenPos(m_pos + CVector2D(-16,0)));
		m_gauge.Draw();

		//ゲージの表示
		//ゲージの長さ 4は枠の太さ
		float border = 0.5;
		int width = (32- border - border) * m_par;
		int m_gauge_type = 0;
		if (m_par < 0.4)
			m_gauge_type = 1;
		int y = (m_gauge_type + 1);
		m_gauge.SetRect(border, (64 * y) + border, 4 + width, (64 * (y + 1)) - border);
		m_gauge.SetSize(width, 8- border - border);
		m_gauge.SetPos(GetScreenPos(m_pos + CVector2D(border - 16, border)));
		m_gauge.Draw();
	}
}

void Trap::SetValue(float par){
	m_par = par;
}
