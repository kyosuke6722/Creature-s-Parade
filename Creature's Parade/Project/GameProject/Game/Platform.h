#pragma once
#include"../Base/Base.h"
class Platform :public Base {
private:
	CImage m_img;
public:
	Platform();
	void Update();
	void Collision();
	void Draw();
};
