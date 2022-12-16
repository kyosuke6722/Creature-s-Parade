#pragma once
#include"../Base/Base.h"

class Trap :public Base {
	enum {
		Bullet_fire,
		Bullet_arrow,
	};
private:
	CImage m_img;
	CImage m_gauge;
	int m_hp;//‘Ï‹v—Í
	int m_max_hp;
	float m_par;
	int m_gauge_cnt;
	int m_bullet_type;//’e‚ÌŽí—Þ
	int m_bullet_ang;//’e‚Ì‰ñ“]
	bool m_fire;//Effect˜A”­–hŽ~
public:
	Trap(CVector2D pos,int bullet_type,int ang);
	~Trap();
	void Update();
	void Collision(Base* b);
	void Draw();
	void SetValue(float par);
};
