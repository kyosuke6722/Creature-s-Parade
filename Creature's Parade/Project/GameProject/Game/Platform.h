#pragma once
#include"../Base/Base.h"
class Platform :public Base {
private:
	CImage m_img;
public:
	Platform(CVector2D pos);
	void Update();
	void Draw();
};
