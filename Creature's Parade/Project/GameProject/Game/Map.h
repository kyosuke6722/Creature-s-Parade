#pragma once
#include"../Base/Base.h"

#define MAP_WIDTH 80//�}�b�v�̉��̃`�b�v��

#define MAP_HEIGHT 15//�}�b�v�̏c�̃`�b�v��

#define MAP_TIP_SIZE 72//�}�b�v�`�b�v�̑傫��

class Map :public Base {
private:
	CImage m_img;
	CImage m_back;
public:
	Map();
	void Draw();
	int GetTip(const CVector2D& pos, int* tx = nullptr, int* ty = nullptr);//�w����W�̃`�b�v�ԍ����擾
	int GetTip(int x, int y);//�w���A�w��s�̃}�b�v�`�b�v���擾
	//�}�b�v�Ƃ̓����蔻��
	int CollisionMap(const CVector2D& pos);
	int CollisionMap(const CVector2D& pos, const CRect& rect, CVector2D* rev_pos);
};