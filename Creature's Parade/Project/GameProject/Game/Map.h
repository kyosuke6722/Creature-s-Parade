#pragma once
#include"../Base/Base.h"

#define MAP_WIDTH 40//マップの横のチップ数

#define MAP_HEIGHT 22//マップの縦のチップ数

#define MAP_TIP_SIZE 72//マップチップの大きさ

class Map :public Base {
private:
	CImage m_img;
public:
	Map();
	void Draw();
	int GetTip(const CVector2D& pos);//指定座標のチップ番号を取得
	int GetTip(int col, int raw);//指定列、指定行のマップチップを取得
	//マップとの当たり判定
	int CollisionMap(const CVector2D& pos);
	int CollisionMap(const CVector2D& pos, const CRect& rect);
};