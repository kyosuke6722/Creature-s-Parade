#pragma once
#include"../Base/Base.h"

class Trap :public Base {
private:
	CImage m_img;
	int m_hp;//�ϋv��
	bool m_fire;//Effect�A���h�~
public:
	Trap(CVector2D pos);
	~Trap();
	void Update();
	void Collision(Base* b);
	void Draw();
};
