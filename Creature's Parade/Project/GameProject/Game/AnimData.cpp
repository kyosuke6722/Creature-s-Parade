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
	{11,5},
	{8,5},
	{9,5},
	{10,5},
};

TexAnimData player_anim_data[] = {
	ANIMDATA(playerIdle),
	ANIMDATA(playerRun),
	ANIMDATA(playerThrow),
};

//炎
static TexAnim effect_fire[] = {
	{14,2},
	{15,2},
	{16,2},
	{0,2},
	{1,2},

	{2,10},
	{3,10},
	{4,10},
	{5,10},
	{6,10},
	{7,10},
	{8,10},
	{9,10},
	{10,10},
	{11,10},
	{12,10},
	{13,10},

	{14,2},
	{15,2},
	{16,2},
};

TexAnimData effect_fire_anim_data[] = {
	ANIMDATA(effect_fire),
};

//発射台
static TexAnim launchpad[] = {
	{0,6},
	{1,2},
	{2,2},
	{3,120},
	{2,2},
	{1,2},
	{0,2},
};

TexAnimData launchpad_anim_data[] = {
	ANIMDATA(launchpad),
};