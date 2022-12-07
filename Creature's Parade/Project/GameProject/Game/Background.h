#pragma once
#include"../Base/Base.h"

class Background :public Base {
private:
	CImage m_img;
public:
	Background();
	void Draw();
};
