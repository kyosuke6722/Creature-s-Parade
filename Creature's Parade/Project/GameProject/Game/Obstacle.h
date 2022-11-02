#pragma once
#include"../Base/Base.h"

class Obstacle :public Base {
private:
	CImage m_img;
public:
	Obstacle();
	~Obstacle();
	void Collision(Base* b);
	void Draw();
};
