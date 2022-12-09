#include "UI.h"
#include"Player.h"

UI::UI(CVector2D pos):Base(eType_UI) {
	m_img = COPY_RESOURCE("Life", CImage);
	m_img.SetRect(0, 0,32,32);
	m_img.SetSize(48, 48);
	m_img.ChangeAnimation(0,false);
	m_pos = pos;
	m_damage = false;
}

void UI::Update(){
	if (m_damage) {
		m_img.UpdateAnimation();
		if (m_img.CheckAnimationEnd())
			SetKill();
	}
}

void UI::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}
