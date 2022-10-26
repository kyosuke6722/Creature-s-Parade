#pragma once
#include"../Base/Base.h"

class Player :public Base {
private:
	CImage m_img;
public:
	Player();
	void Update();
	void Draw();
};