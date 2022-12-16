#pragma once
#include"../Base/Base.h"

class Creature;
class Player :public Base {
	std::list<Creature*> m_creature;//creature���Ǘ�����list
private:
	enum {
		eState_Idle,
		eState_Throw,
		eState_Damage,
		eState_Down,
	};
	CImage m_img;
	int m_state;//��ԕϐ�
	bool m_is_ground;//���n�t���O
	int m_invincible;//���G����
	int m_bring;//�A��Ă���Creature�̐�
public:
	Player(CVector2D pos,bool flip);
	void Update();
	void Collision(Base* b);
	void Draw();
	//��Ԋ֘A
	void StateIdle();
	void StateThrow();
	void StateDamage();
	void StateDown();
	void OnPlatform(Base* b);//���n����
	bool m_flip;
	bool m_on_platform;//����ɏ���Ă��邩
	int m_hp;//�̗�
	//�N���[�`���[�֘A
	void EraseCreature(Creature* c);
	void ThrowCreature();
	void GatherCreature();
};