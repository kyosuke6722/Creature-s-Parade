#include "Goal.h"

Goal::Goal(CVector2D pos):Base(eType_Goal) {
	m_img = COPY_RESOURCE("Goal", CImage);
	m_pos = pos;
}

Goal::~Goal(){
}

void Goal::Draw(){
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}