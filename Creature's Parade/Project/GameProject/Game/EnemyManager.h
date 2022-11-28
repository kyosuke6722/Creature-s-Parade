#pragma once
#include "../Base/Base.h"
class EnemyManager : public Base {
public:
	//敵出現データ構造体
	struct EnemyData {
		int type;		//敵の種類(サンプルでは不使用)
		CVector2D pos;	//出現位置
		int cnt;		//出現時間
	};
	//敵出現データまとめ構造体
	struct EnemyDataArray {
		EnemyData* data;	//敵出現データ配列の先頭アドレス
		int			size;	//敵出現データ配列の配列要素数
	};
private:
	int m_cnt;		//時間計測
	int m_idx;		//敵出現データ添字
	EnemyDataArray* mp_data;	//敵出現データまとめ
public:
	EnemyManager();
	void Update();
	/// <summary>
	/// 終了判定
	/// </summary>
	/// <returns>true:全ての敵が出現している</returns>
	bool isEnd();
};