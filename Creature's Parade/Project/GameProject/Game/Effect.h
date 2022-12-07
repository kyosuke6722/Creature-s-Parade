#pragma once
#include"../Base/Base.h"

class Effect :public Base {
private:
	CImage m_img;
	int m_bullet_ang;
public:
	Effect(const char* name,CVector2D pos,int ang);
	~Effect();
	void Update();
	void Draw();
};
