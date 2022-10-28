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
	int m_state;//状態変数
	bool m_flip;//反転設定
public:
	Player(CVector2D pos,bool flip);
	void Update();
	void Draw();
	void StateIdle();
	void StateThrow();
};