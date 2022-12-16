#pragma once
#include"../Base/Base.h"

class Obstacle :public Base {
private:
	CImage m_img;
	CImage m_gauge;//�ϋv�̓Q�[�W
	int m_hp;//�ϋv��
	int m_max_hp;
	float m_par;
	int m_gauge_cnt;//�ϋv�̓Q�[�W�\���t���O&�\���b��
	int gauge_size;//�Q�[�W�T�C�Y�����p
	int m_rock_type;//��̎��
public:
	Obstacle(CVector2D pos,int hp,float size);
	~Obstacle();
	void Update();
	void Collision(Base* b);
	void Draw();
	void SetValue(float par);
};
