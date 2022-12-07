#pragma once
#include"../Base/Base.h"

class Arrow :public Base {
private:
	CImage m_img;
	int m_bullet_ang;
public:
	Arrow(CVector2D pos,int ang);
	void Update();
	void Collision(Base* b);
	void Draw();
};
