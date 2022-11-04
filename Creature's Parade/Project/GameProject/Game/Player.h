#pragma once
#include"../Base/Base.h"

class Creature;
class Player :public Base {
	std::list<Creature*> m_creature;//creatureを管理するlist
private:
	enum {
		eState_Idle,
		eState_Throw
	};
	CImage m_img;
	//CImage m_throw;
	int m_state;//状態変数
	bool m_is_ground;//着地フラグ
	int m_cnt;
	int m_hp;//体力
	int m_bring;//連れているCreatureの数
public:
	Player(CVector2D pos,bool flip);
	void Update();
	void Collision(Base* b);
	void Draw();
	void StateIdle();
	void StateThrow();
	void EraseCreature(Creature* c);
	void ThrowCreature();
	bool m_flip;
};