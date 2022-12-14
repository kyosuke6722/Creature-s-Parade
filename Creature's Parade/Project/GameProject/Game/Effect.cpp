#include "Effect.h"

Effect::Effect(const char* name,CVector2D pos,int ang):Base(eType_Effect) {
	m_img = COPY_RESOURCE(name, CImage);
	SOUND("SE_Fire")->Play();
	m_img.ChangeAnimation(0,false);
	m_img.SetSize(24*6,32*10);
	m_img.SetCenter(12*6,32*10);
	m_ang = DtoR(ang*90);
	m_bullet_ang = ang;
	switch (m_bullet_ang) {
	case 0://ãŒü‚«
		m_rect = CRect(-6 * 6, -16 * 10, 6 * 6, 0);
		break;
	case 1://¶Œü‚«
		m_rect = CRect(-16 * 10, -6 * 6, 0, 6 * 6);
		break;
	case 2://‰ºŒü‚«
		m_rect = CRect(-6 * 6, 0, 6 * 6, 16 * 10);
		break;
	case 3://‰EŒü‚«
		m_rect = CRect(0, -6 * 6, 16 * 10, 6 * 6);
		break;
	}
	m_pos = pos;
}

Effect::~Effect(){
	SOUND("SE_Fire")->Pause();
}

void Effect::Update(){
	m_img.UpdateAnimation();
	if (m_img.CheckAnimationEnd()) {
		SetKill();
	}
}

void Effect::Draw(){
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetAng(m_ang);
	m_img.Draw();
	//DrawRect();
}