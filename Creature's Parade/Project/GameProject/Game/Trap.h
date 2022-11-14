#pragma once
#include"../Base/Base.h"

class Trap :public Base {
private:
	CImage m_img;
	int m_hp;//�ϋv��
	int m_cnt;//�N�[���^�C��
public:
	Trap(CVector2D pos);
	~Trap();
	void Update();
	void Collision(Base* b);
	void Draw();
};
