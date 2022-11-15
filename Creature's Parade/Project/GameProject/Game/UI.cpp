#include "UI.h"
#include"Player.h"

UI::UI():Base(eType_UI) {
	m_img = COPY_RESOURCE("Life", CImage);
	m_img.SetRect(0, 0,32,32);
	m_img.SetSize(48, 48);
}

void UI::Update(){
}

void UI::Draw(){
	Player* p = dynamic_cast<Player*>(Base::FindObject(eType_Player));
	if (p) {
		int hp = p->m_hp;
		for (int i = 1; i <= hp; i++) {
			m_img.SetPos(i * 48 - 16, 32);
			m_img.Draw();
		}
	}
}
