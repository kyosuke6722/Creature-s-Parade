#include "Map.h"
static int stage1data[MAP_HEIGHT][MAP_WIDTH] = {
	//                    1                   2                   3                   4
	//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//0
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//1
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//2
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//3
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//4
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//5
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//6
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//7
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//8
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//9
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//10
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//11
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//12
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//13
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//14
};


Map::Map() :Base(eType_Field) {
	m_img = COPY_RESOURCE("MapTip", CImage);
}

void Map::Draw() {
	//マップチップによる表示の繰り返し
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			//表示しない制御
			if (stage1data[i][j] == 0)continue;
			int t = stage1data[i][j];
			m_img.SetRect(16 * t, 0, 16 * t + 16, 16);//画像切り抜き
			m_img.SetSize(MAP_TIP_SIZE, MAP_TIP_SIZE);//表示サイズ設定
			m_img.SetPos(MAP_TIP_SIZE * j - m_scroll.x, MAP_TIP_SIZE * i - m_scroll.y);//表示位置設定
			m_img.Draw();//描画
		}
	}
}

int Map::GetTip(const CVector2D& pos, int* tx, int* ty)
{
	//列を計算
	int x = pos.x / MAP_TIP_SIZE;
	//列の制限
	if (x < 0) x = 0;
	if (x > MAP_WIDTH - 1) x = MAP_WIDTH - 1;
	//行を計算
	int y = pos.y / MAP_TIP_SIZE;
	//行の制限
	if (y < 0) y = 0;
	if (y > MAP_HEIGHT - 1) y = MAP_HEIGHT - 1;
	//行と列の出力
	if (ty) *ty = y;
	if (tx) *tx = x;
	//チップデータを返却
	return stage1data[y][x];
}

int Map::GetTip(int x, int y)
{
	return stage1data[y][x];
}


int Map::CollisionMap(const CVector2D& pos)
{
	return GetTip(pos);
}
int Map::CollisionMap(const CVector2D& pos, const CRect& rect, CVector2D* rev_pos)
{
	int tx, ty;
	//左上
	int t = GetTip(CVector2D(pos.x + rect.m_left, pos.y + rect.m_top), &tx, &ty);
	if (t != 0) {
		//修正後位置
		rev_pos->x = (tx + 1) * MAP_TIP_SIZE - rect.m_left + 1;
		rev_pos->y = (ty + 1) * MAP_TIP_SIZE - rect.m_top + 1;
		return t;
	}
	//右上
	t = GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_top), &tx, &ty);
	if (t != 0) {
		//修正後位置
		rev_pos->x = tx * MAP_TIP_SIZE - rect.m_right - 1;
		rev_pos->y = (ty + 1) * MAP_TIP_SIZE - rect.m_top + 1;
		return t;
	}
	//左下
	t = GetTip(CVector2D(pos.x + rect.m_left, pos.y + rect.m_bottom), &tx, &ty);
	if (t != 0) {
		//修正後位置
		rev_pos->x = (tx + 1) * MAP_TIP_SIZE - rect.m_left + 1;
		rev_pos->y = ty * MAP_TIP_SIZE - rect.m_bottom - 1;
		return t;
	}
	//右下
	t = GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_bottom), &tx, &ty);
	if (t != 0) {
		//修正後位置
		rev_pos->x = tx * MAP_TIP_SIZE - rect.m_right - 1;
		rev_pos->y = ty * MAP_TIP_SIZE - rect.m_bottom - 1;
		return t;
	}
	return 0;
}