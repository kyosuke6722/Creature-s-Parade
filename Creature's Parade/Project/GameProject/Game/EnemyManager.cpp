#include "EnemyManager.h"
#include "Creature.h"
//�G�̏o���f�[�^�@
EnemyManager::EnemyData _stage1[] = {
	{0,CVector2D(200,0),120},
	{0,CVector2D(200,0),60},
	{0,CVector2D(200,0),60},

	{0,CVector2D(600,0),120},
	{0,CVector2D(600,0),60},
	{0,CVector2D(600,0),60},

};
//�G�̏o���f�[�^�܂Ƃ�
EnemyManager::EnemyDataArray _enemy_data[] = {
	{_stage1,sizeof(_stage1) / sizeof(_stage1[0])},
};

EnemyManager::EnemyManager() :Base(eType_EnemyManager)
{
	m_cnt = 0;
	m_idx = 0;
	mp_data = &_enemy_data[0];
}

void EnemyManager::Update()
{
	//�S�Ă̓G���o�Ă��Ȃ�
	if (m_idx < mp_data->size) {
		//���Ԍo��
		m_cnt++;

		EnemyData* d = &mp_data->data[m_idx];
		//�w�莞�Ԃ𒴂���ƓG���o��
		if (m_cnt >= d->cnt) {
			//�G����
			//Base::Add(new Creature(d->pos));
			//���̏o���f�[�^���Q��
			m_idx++;
			m_cnt = 0;
		}
	}
}
bool EnemyManager::isEnd() {
	//�S�Ă̓G���o���ς݂Ȃ�true��Ԃ�
	return (m_idx >= mp_data->size) ? true : false;
}
