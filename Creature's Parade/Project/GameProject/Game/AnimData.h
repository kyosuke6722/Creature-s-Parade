#pragma once
#include<GLLibrary.h>

//アニメーションの種類
enum {
	eAnimIdle=0,
	eAnimRun,
	eAnimThrow,
	eAnimDamage,
	eAnimDown,
};

//プレイヤーのアニメーションデータ
extern TexAnimData player_anim_data[];
//敵のアニメーションデータ
extern TexAnimData enemy_anim_data[];
//炎のアニメーションデータ
extern TexAnimData effect_fire_anim_data[];
//発射台のアニメーションデータ
extern TexAnimData launchpad_anim_data[];