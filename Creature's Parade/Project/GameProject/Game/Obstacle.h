#pragma once
#include"../Base/Base.h"

class Obstacle :public Base {
private:
	CImage m_img;
	CImage m_gauge;//‘Ï‹v—ÍƒQ[ƒW
public:
	Obstacle(CVector2D pos,int hp);
	~Obstacle();
	void Collision(Base* b);
	void Draw();
	int m_hp;//‘Ï‹v—Í
	int m_max_hp;
};
