#pragma once
#include"../Base/Base.h"

class Creature :public Base {
	enum {
		eState_Idle,
		eState_Throw
	};
private:
	CImage m_img;
	bool m_flip;//���]�ݒ�
	int m_state;//��ԕϐ�
	bool m_is_ground;//���n�t���O
public:
	Creature(CVector2D pos,bool flip);
	void Update();
	void Collision(Base* b);
	void Draw();
	void StateIdle();
	void StateThrow();
};