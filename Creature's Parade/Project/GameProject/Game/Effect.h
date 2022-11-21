#pragma once
#include"../Base/Base.h"

class Effect :public Base {
private:
	CImage m_img;
public:
	Effect(const char* name,CVector2D pos);
	~Effect();
	void Update();
	void Draw();
};
