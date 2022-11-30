#pragma once
#include"../Base/Base.h"

class Player;
class Creature :public Base {
	enum {
		eState_Idle,
		eState_Throw
	};
private:
	CImage m_img;
	bool m_flip;//反転設定
	int m_state;//状態変数
	bool m_is_ground;//着地フラグ
public:
	Creature(const char* name,CVector2D pos,bool flip);
	~Creature();
	Player* m_player;
	int m_column;//何列目にいるか
	bool m_friend;//仲間フラグ
	void Update();
	void Collision(Base* b);
	void Draw();
	void StateIdle();
	void ChangeType();
	//void StateThrow();
};