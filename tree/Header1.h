#pragma once
//@author:Ключерев Артемий

#include <iostream>
#include "TreeNode.h"

template <typename T>
class BinSTree
{
private:
	// указатели на корень и на текущий узел
	TreeNode<T>* root;//корень
	TreeNode<T>* current;//текущий уровень

	// число элементов дерева 
	int size;


public:
	// конструктор по умолчанию
	BinSTree();

	// конструктор с параметром
	BinSTree(TreeNode<T>* tree);


	// конструктор копирования
	BinSTree(const BinSTree<T>& tree);

	// оператор копирования (присваивания)
	BinSTree<T>& operator = (const BinSTree<T>& rhs);

	// деструктор
	~BinSTree() { deleteTree(this->root); }
};


// конструктор по умолчанию
template <typename T>
BinSTree<T>::BinSTree()
{
	this->root = nullptr;
	this->current = nullptr;
	this->size = 0;
}

// конструктор с параметрами
template <typename T>
BinSTree<T>::BinSTree(TreeNode<T>* tree)
{
	this->root = CopyTree(tree);
	this->current = nullptr;
	this->size = treeCount(this->root);
}

// конструктор копирования
template <typename T>
BinSTree<T>::BinSTree(const BinSTree<T>& tree)
{
	this->root = CopyTree(tree.root);

	// присвоить текущему указателю значение корня и задать размер дерева
	this->current = this->root;
	this->size = tree.size;
}


// оператор копирования (присваивания)
template <class T>
BinSTree<T>& BinSTree<T>::operator= (const BinSTree<T>& rhs)
{
	// нельзя копировать дерево в само себя
	if (this == &rhs)
		return *this;

	// очистить текущее дерево
	ClearList();

	// скопировать новое дерево в текущий объект
	this->root = CopyTree(rhs.root);

	// присвоить текущему указателю значение корня и задать размер дерева
	this->current = this->root;
	this->size = rhs.size;

	// возвратить ссылку на текущий объект
	return *this;
}
