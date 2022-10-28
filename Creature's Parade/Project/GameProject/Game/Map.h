#pragma once
#include"../Base/Base.h"

class Map :public Base {
private:
	CImage m_img;
public:
	Map();
	void Draw();
};
