#pragma once
#include"../Base/Base.h"

class Trap :public Base {
	enum {
		Bullet_fire,
		Bullet_arrow,
	};
private:
	CImage m_img;
	int m_hp;//‘Ï‹v—Í
	int m_bullet_type;//’e‚ÌŽí—Þ
	bool m_fire;//Effect˜A”­–hŽ~
public:
	Trap(CVector2D pos,int bullet_type);
	~Trap();
	void Update();
	void Collision(Base* b);
	void Draw();
};
