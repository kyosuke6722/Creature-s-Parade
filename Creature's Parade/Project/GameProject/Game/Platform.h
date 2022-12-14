#pragma once
#include"../Base/Base.h"
class Platform :public Base {
private:
	CImage m_img;
	float m_move_speed;
	float m_cnt;
public:
	Platform(CVector2D pos);
	void Update();
	void Collision(Base* b);
	void Draw();
};
