#pragma once
#include"../Base/Base.h"

class Creature;
class Player :public Base {
	std::list<Creature*> m_creature;//creature‚ğŠÇ—‚·‚élist
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
	void EraseCreature(Creature* c);
	void ThrowCreature();
	bool m_flip;
};