#pragma once
#include<GLLibrary.h>

//�A�j���[�V�����̎��
enum {
	eAnimIdle=0,
	eAnimRun,
	eAnimThrow,
	eAnimDamage,
	eAnimDown,
};

//�v���C���[�̃A�j���[�V�����f�[�^
extern TexAnimData player_anim_data[];
//�G�̃A�j���[�V�����f�[�^
extern TexAnimData enemy_anim_data[];
//���̃A�j���[�V�����f�[�^
extern TexAnimData effect_fire_anim_data[];
//���ˑ�̃A�j���[�V�����f�[�^
extern TexAnimData launchpad_anim_data[];