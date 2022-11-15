#pragma once
#include"../Base/Base.h"

class UI :public Base {
private:
	CImage m_img;
public:
	UI();
	void Update();
	void Draw();
};
