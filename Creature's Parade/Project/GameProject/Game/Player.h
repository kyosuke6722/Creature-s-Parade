#pragma once
#include"../Base/Base.h"

class Creature;
class Player :public Base {
	std::list<Creature*> m_creature;//creatureを管理するlist
private:
	enum {
		eState_Idle,
		eState_Throw,
		eState_Damage,
		eState_Down,
	};
	CImage m_img;
	int m_state;//状態変数
	bool m_is_ground;//着地フラグ
	int m_invincible;//無敵時間
	int m_bring;//連れているCreatureの数
public:
	Player(CVector2D pos,bool flip);
	void Update();
	void Collision(Base* b);
	void Draw();
	//状態関連
	void StateIdle();
	void StateThrow();
	void StateDamage();
	void StateDown();
	void OnPlatform(Base* b);//着地処理
	bool m_flip;
	bool m_on_platform;//足場に乗っているか
	int m_hp;//体力
	//クリーチャー関連
	void EraseCreature(Creature* c);
	void ThrowCreature();
	void GatherCreature();
};