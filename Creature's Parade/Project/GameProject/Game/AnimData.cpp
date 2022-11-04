#include"AnimData.h"

//�ҋ@�A�j���[�V����
static TexAnim playerIdle[] = {
	{0,45},
	{1,30},
	{3,45},
};

//���s�A�j���[�V����
static TexAnim playerRun[] = {
	{6,4},
	{7,4},
	{8,4},
	{9,4},
	{10,4},
};

//�����A�j���[�V����
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