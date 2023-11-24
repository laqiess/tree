#pragma once
//@author:�������� �������

#include <iostream>
#include "TreeNode.h"

template <typename T>
class BinSTree
{
private:
	// ��������� �� ������ � �� ������� ����
	TreeNode<T>* root;//������
	TreeNode<T>* current;//������� �������

	// ����� ��������� ������ 
	int size;


public:
	// ����������� �� ���������
	BinSTree();

	// ����������� � ����������
	BinSTree(TreeNode<T>* tree);


	// ����������� �����������
	BinSTree(const BinSTree<T>& tree);

	// �������� ����������� (������������)
	BinSTree<T>& operator = (const BinSTree<T>& rhs);

	// ����������
	~BinSTree() { deleteTree(this->root); }
};


// ����������� �� ���������
template <typename T>
BinSTree<T>::BinSTree()
{
	this->root = nullptr;
	this->current = nullptr;
	this->size = 0;
}

// ����������� � �����������
template <typename T>
BinSTree<T>::BinSTree(TreeNode<T>* tree)
{
	this->root = CopyTree(tree);
	this->current = nullptr;
	this->size = treeCount(this->root);
}

// ����������� �����������
template <typename T>
BinSTree<T>::BinSTree(const BinSTree<T>& tree)
{
	this->root = CopyTree(tree.root);

	// ��������� �������� ��������� �������� ����� � ������ ������ ������
	this->current = this->root;
	this->size = tree.size;
}


// �������� ����������� (������������)
template <class T>
BinSTree<T>& BinSTree<T>::operator= (const BinSTree<T>& rhs)
{
	// ������ ���������� ������ � ���� ����
	if (this == &rhs)
		return *this;

	// �������� ������� ������
	ClearList();

	// ����������� ����� ������ � ������� ������
	this->root = CopyTree(rhs.root);

	// ��������� �������� ��������� �������� ����� � ������ ������ ������
	this->current = this->root;
	this->size = rhs.size;

	// ���������� ������ �� ������� ������
	return *this;
}
