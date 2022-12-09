#include "Platform.h"
#include"Switch.h"

Platform::Platform(CVector2D pos):Base(eType_Platform){
	m_img = COPY_RESOURCE("Platform", CImage);
	m_img.SetCenter(180,18);
	m_rect = CRect(-180,-18,180,18);
	m_pos =m_pos_old= pos;
}

void Platform::Update(){
	if (Switch* s = dynamic_cast<Switch*>(Base::FindObject(eType_Obstacle))) {
		if (s->move_flag) {
			m_pos.y -=0.6;
		}
	}
}

void Platform::Draw(){
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	DrawRect();
}