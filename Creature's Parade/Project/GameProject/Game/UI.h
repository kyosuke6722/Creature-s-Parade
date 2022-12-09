#pragma once
#include"../Base/Base.h"

class UI :public Base {
private:
	CImage m_img;
public:
	UI(CVector2D pos);
	void Update();
	void Draw();
	bool m_damage;
};
