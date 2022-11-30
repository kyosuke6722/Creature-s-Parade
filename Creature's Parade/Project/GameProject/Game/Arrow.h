#pragma once
#include"../Base/Base.h"

class Arrow :public Base {
private:
	CImage m_img;
public:
	Arrow(CVector2D pos,float ang);
	void Update();
	void Collision(Base* b);
	void Draw();
};
