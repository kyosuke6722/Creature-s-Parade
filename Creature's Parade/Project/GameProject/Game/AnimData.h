#pragma once
#include<GLLibrary.h>

//�A�j���[�V�����̎��
enum {
	eAnimIdle=0,
	eAnimRun,
	eAnimThrow,
	eAnimThrowEnd,
	eAnimDamage,
	eAnimDamageEnd,
	eAnimDeath,
};

//�v���C���[�̃A�j���[�V�����f�[�^
extern TexAnimData player_anim_data[];
//�G�̃A�j���[�V�����f�[�^
extern TexAnimData enemy_anim_data[];