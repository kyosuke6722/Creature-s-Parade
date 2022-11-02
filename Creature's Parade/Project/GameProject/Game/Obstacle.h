#pragma once
#include"../Base/Base.h"

class Obstacle :public Base {
private:
	CImage m_img;
public:
	Obstacle(CVector2D pos,int hp);
	~Obstacle();
	void Collision(Base* b);
	void Draw();
	int m_hp;//‘Ï‹v—Í
};
