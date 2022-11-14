#include "Effect.h"

Effect::Effect(const char* name, CVector2D pos):Base(eType_Effect) {
	m_img = COPY_RESOURCE(name, CImage);
	m_img.ChangeAnimation(0,false);
	m_img.SetSize(24*3,32*3);
	m_img.SetCenter(12*3,32*3);
	m_rect = CRect(-6*3,-16*3,6*3,0);
}

void Effect::Update(){
	m_img.UpdateAnimation();
	if (m_img.CheckAnimationEnd()) {
		SetKill();
	}
}

void Effect::Draw(){
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	DrawRect();
}