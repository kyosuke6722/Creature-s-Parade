#pragma once
#include"../Base/Base.h"

class Obstacle :public Base {
private:
	CImage m_img;
	CImage m_gauge;//‘Ï‹v—ÍƒQ[ƒW
	float m_par;
	int m_gauge_cnt;//‘Ï‹v—ÍƒQ[ƒW•\¦ƒtƒ‰ƒO&•\¦•b”
public:
	Obstacle(CVector2D pos,int hp);
	~Obstacle();
	void Update();
	void Collision(Base* b);
	void Draw();
	int m_hp;//‘Ï‹v—Í
	int m_max_hp;
	void SetValue(float par);
};
