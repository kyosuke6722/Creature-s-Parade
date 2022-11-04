#pragma once
#include<GLLibrary.h>

//アニメーションの種類
enum {
	eAnimIdle=0,
	eAnimRun,
	eAnimThrow,
	eAnimThrowEnd,
	eAnimDamage,
	eAnimDamageEnd,
	eAnimDeath,
};

//プレイヤーのアニメーションデータ
extern TexAnimData player_anim_data[];
//敵のアニメーションデータ
extern TexAnimData enemy_anim_data[];