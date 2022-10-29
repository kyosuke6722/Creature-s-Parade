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
	int m_state;//ó‘Ô•Ï”
	bool m_is_ground;//’…’nƒtƒ‰ƒO
	int m_cnt;
public:
	Player(CVector2D pos,bool flip);
	void Update();
	void Collision(Base* b);
	void Draw();
	void StateIdle();
	void StateThrow();
	bool m_flip;
};