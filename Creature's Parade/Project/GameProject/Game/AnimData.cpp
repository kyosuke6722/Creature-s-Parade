#include"AnimData.h"

//プレイヤー
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

//ダメージアニメーション
static TexAnim playerDamage[] = {
	{17,18},
};

//死亡アニメーション
static TexAnim playerDown[] = {
	{17,18},
	{18,12},
	{19,12},
	{20,48},
};

TexAnimData player_anim_data[] = {
	ANIMDATA(playerIdle),
	ANIMDATA(playerRun),
	ANIMDATA(playerThrow),
	ANIMDATA(playerDamage),
	ANIMDATA(playerDown),
};

//炎
static TexAnim effect_fire[] = {
	{0,2},
	{1,2},
	{2,10},
	{3,10},
	{4,10},
	{5,10},
	{6,10},
	{7,10},
	{8,10},
	{9,8},
	{10,8},
	{11,8},
	{12,8},
	{13,8},
	{14,2},
	{15,2},
	{16,2},
};

TexAnimData effect_fire_anim_data[] = {
	ANIMDATA(effect_fire),
};

//発射台
static TexAnim launchpad[] = {
	{0,60},
	{1,6},
	{2,6},
	{3,2*60},
	{2,6},
	{1,6},
	{0,60},
};

TexAnimData launchpad_anim_data[] = {
	ANIMDATA(launchpad),
};