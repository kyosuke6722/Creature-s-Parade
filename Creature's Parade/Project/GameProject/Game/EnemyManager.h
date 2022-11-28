#pragma once
#include "../Base/Base.h"
class EnemyManager : public Base {
public:
	//�G�o���f�[�^�\����
	struct EnemyData {
		int type;		//�G�̎��(�T���v���ł͕s�g�p)
		CVector2D pos;	//�o���ʒu
		int cnt;		//�o������
	};
	//�G�o���f�[�^�܂Ƃߍ\����
	struct EnemyDataArray {
		EnemyData* data;	//�G�o���f�[�^�z��̐擪�A�h���X
		int			size;	//�G�o���f�[�^�z��̔z��v�f��
	};
private:
	int m_cnt;		//���Ԍv��
	int m_idx;		//�G�o���f�[�^�Y��
	EnemyDataArray* mp_data;	//�G�o���f�[�^�܂Ƃ�
public:
	EnemyManager();
	void Update();
	/// <summary>
	/// �I������
	/// </summary>
	/// <returns>true:�S�Ă̓G���o�����Ă���</returns>
	bool isEnd();
};