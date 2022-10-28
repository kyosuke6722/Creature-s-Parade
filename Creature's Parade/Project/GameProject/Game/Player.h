#pragma once
#include"../Base/Base.h"

class Player :public Base {
private:
	enum {
		eState_Idle,
		eState_Throw
	};
	CImage m_img;
	CImage m_throw;
	int m_state;//��ԕϐ�
	bool m_flip;//���]�ݒ�
public:
	Player(CVector2D pos,bool flip);
	void Update();
	void Draw();
	void StateIdle();
	void StateThrow();
};