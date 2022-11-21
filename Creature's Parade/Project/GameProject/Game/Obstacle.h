#pragma once
#include"../Base/Base.h"

class Obstacle :public Base {
private:
	CImage m_img;
	CImage m_gauge;//�ϋv�̓Q�[�W
	float m_par;
	int m_gauge_cnt;//�ϋv�̓Q�[�W�\���t���O&�\���b��
public:
	Obstacle(CVector2D pos,int hp);
	~Obstacle();
	void Update();
	void Collision(Base* b);
	void Draw();
	int m_hp;//�ϋv��
	int m_max_hp;
	void SetValue(float par);
};
