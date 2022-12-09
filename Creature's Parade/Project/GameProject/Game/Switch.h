#pragma once
#include"../Base/Base.h"
class Switch :public Base {
private:
	CImage m_img;
	int m_cnt;
public:
	Switch(CVector2D pos);
	void Update();
	void Collision(Base* b);
	void Draw();
	bool move_flag;//PlatformˆÚ“®ƒtƒ‰ƒO
};