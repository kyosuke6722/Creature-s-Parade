#pragma once
#include"../Base/Base.h"

class Trap :public Base {
private:
	CImage m_img;
	int m_hp;//�ϋv��
public:
	Trap();
	~Trap();
	void Update();
	void Collision(Base* b);
	void Draw();
};
