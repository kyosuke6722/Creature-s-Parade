#pragma once
#include"../Base/Base.h"

class Obstacle :public Base {
private:
	CImage m_img;
	CImage m_gauge;//耐久力ゲージ
	int m_hp;//耐久力
	int m_max_hp;
	float m_par;
	int m_gauge_cnt;//耐久力ゲージ表示フラグ&表示秒数
	int gauge_size;//ゲージサイズ調整用
	int m_rock_type;//岩の種類
public:
	Obstacle(CVector2D pos,int hp,float size);
	~Obstacle();
	void Update();
	void Collision(Base* b);
	void Draw();
	void SetValue(float par);
};
