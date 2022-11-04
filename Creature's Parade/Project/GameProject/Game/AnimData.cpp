#include"AnimData.h"

//待機アニメーション
static TexAnim playerIdle[] = {
	{0,45},
	{1,30},
	{3,45},
};

//走行アニメーション
static TexAnim playerRun[] = {
	{6,4},
	{7,4},
	{8,4},
	{9,4},
	{10,4},
};

//投擲アニメーション
static TexAnim playerThrow[] = {
	{11,8},
	{8,7},
	{9,7},
	{10,8},
};

TexAnimData player_anim_data[] = {
	ANIMDATA(playerIdle),
	ANIMDATA(playerRun),
	ANIMDATA(playerThrow),
};