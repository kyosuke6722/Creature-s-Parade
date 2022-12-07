#pragma once
#include"../Base/Base.h"
class Switch :public Base {
private:
	CImage m_img;
public:
	Switch();
	void Update();
	void Collision();
	void Draw();
};