#pragma once
#include"../Base/Base.h"

class Goal :public Base {
private:
	CImage m_img;
public:
	Goal(CVector2D pos);
	~Goal();
	void Draw();
};
