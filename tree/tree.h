#pragma once

#include <iostream>
#include <queue>
#include<vector>

using namespace std;
//���� ������
template < typename T>



struct TreeNode {
    //int data;//������ �������� ����, ���� int
    T data;//������ �������� ����, ���� int
    TreeNode <T>* left; //��������� �� ����� ���������
    TreeNode<T>* right;//��������� �� ������ ���������

    //�����������
    /*TreeNode(T value) {
        data = value;//��������� �������� value, ������� ������������� �������� data ����
        left = nullptr;//��������,��� ��� ��� �������� ���� ��� ��� �������� �����
        right = nullptr;//��������,��� ��� ��� �������� ���� ��� ��� �������� �����
    }*/

    //����������� �� ���������
    TreeNode() = default;




    //����������� � �����������
    TreeNode(const T& value, TreeNode<T>* left1 = nullptr, TreeNode<T>* right1 = nullptr) {
        data = value;
        left = left1;
        right = right1;
    }


    // ������ ��� ������� � ��������� � �������� ����
    T getData() {
        return data;// ���������� �������� ����
    }

    TreeNode <T>* getLeft() {
        return left;//���������� ��������� �� ����� ���������
    }

    TreeNode <T>* getRight() {
        return right;//���������� ��������� �� ������ ���������
    }

    template < typename T>
    void setLeft(TreeNode<T>* node) {
        left = node;//������������� ����� ���������, ������� ��������� �� ���� node
    }

    template < typename T>
    void setData(T node) {
       data = node;//������������� ����� ���������, ������� ��������� �� ���� node
    }

    template < typename T>
    void setRight(TreeNode <T>* node) {
        right = node;//������������� ������ ���������, ������� ��������� �� ���� node
    }
};

// ������� ��� ��������� ����������� ����
template < typename T>
void printNode(TreeNode <T>* node) {
    cout << "���� =  " << node->getData() << endl;//�������� �������� data (���������� � ����)
}

// ������� ���������� ������� � �������� ����
template <typename T>
void add1(TreeNode<T>* root) {
    // ���������, ��� ��������� 't' �� ����� nullptr, ����� �� ������������ ������ ������
    if (root) {
        printNode(root + 1);
        PrintTreeNLR(root->left);
        PrintTreeNLR(root->right);
    }
}

// ������� ���������� � ������� �������� ����
template <typename T>
void squaring(TreeNode<T>* root) {
    root->setData(root->data() * root->data());
}

// L, R, N
// ������� ��� �������� ����� � ������� LRN
template < typename T>
void deleteTree(TreeNode<T>* root) {
    if (root == nullptr) {
        return;//���������, �������� �� ��������� �� �������� ���� root ������ nullptr,
        //���� ��,�� ������� �����������
    }

    deleteTree(root->getLeft());//������� ���������� ���������� ��� ������ � ������� ������� ��������� ����
    deleteTree(root->getRight());
    ////��� ��������� ������� ��� ����������, ������� � ������ � ������� ������� ��������� ����.

    delete root;//�������� ���� root ���������
}




// ����� ������ �������� �������(���)
template < typename T>
void PrintTreeLRN(TreeNode<T>* t) {
    // ���������, ��� ��������� 't' �� ����� nullptr, ����� �� ������������ ������ ������
    if (t) {
        PrintTreeLRN(t->left);
        PrintTreeLRN(t->right);
        // ������� �������� �������� ����
        printNode(t);
    }
}

// ����� ������ ����������� �������(���)
template < typename T>
void PrintTreeLNR(TreeNode<T>* t) {
    // ���������, ��� ��������� 't' �� ����� nullptr, ����� �� ������������ ������ ������
    if (t) {
        PrintTreeLNR(t->left);
        printNode(t);
        PrintTreeLNR(t->right);
    }
}


// ����� ������ ������ �������(���)
template < typename T>
void PrintTreeNLR(TreeNode<T>* t) {
    // ���������, ��� ��������� 't' �� ����� nullptr, ����� �� ������������ ������ ������
    if (t) {
        printNode(t);
        PrintTreeNLR(t->left);
        PrintTreeNLR(t->right);
    }
}



//�������� ����� �����������(���)
template < typename T>
void CountNodes(TreeNode<T>* t, int& count) {
    if (t != nullptr) {
        // ���������� �������� ������� CountNodes ��� ������ � ������� ���������
        CountNodes(t->left, count);
        CountNodes(t->right, count);

        count++;
    }
}


// ��� ������� ���������� �������� ����� �����������(���)
//����� ���������� ������ ������
template < typename T>
void CountLeaf(TreeNode<T>* t, int& count) {
    // ���������, ��� ��������� �� ������� ���� �� ����� nullptr
    if (t != nullptr) {
        // ���������� �������� ������� CountLeaf ��� ������ � ������� ���������
        CountLeaf(t->left, count);
        CountLeaf(t->right, count);

        // ���������, �������� �� ������� ���� �������� ����� 
        // (���� ��� ��������� �� ����� � ������ ��������� ����� nullptr)
        if (t->left == nullptr && t->right == nullptr) {
            count++;
        }
    }
}


// ������� ���������� �������� ����� �����������(���) ��� ���������� �������
// ������ � ������� ����������� ���� � ���������� ��������������
// �������� �������, ������ 1 + max(depthLeft, depthRight).
// ������� ������� ������ ����� -1
template < typename T>
int Depth(TreeNode<T>* t) {
    int depthLeft, depthRight, depthval;
    // ���� ��������� �� ������� ���� ����� nullptr, �� ���������� -1 � �������� �������
    if (t == nullptr) {
        depthval = -1;
    }
    else
    {
        depthLeft = Depth(t->left);
        depthRight = Depth(t->right);

        // ��������� ������� �������� ���� ��� �������� �� ������ ������ � ������� ���������, ����������� �� 1
        depthval = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
    }
    return depthval;
}



// ������� ��� ����������� ��������� ������
template < typename T>
TreeNode<T>* Copy(TreeNode<T>* node) {
    // ���������, ��� ��������� 'node' �� ����� nullptr, ����� �� ���������� ������ ������
    if (node == nullptr)
        return nullptr;
    // ������� ����� ���� � ������� �������� ����
    TreeNode<T>* newnode = new TreeNode<T>(node->data);
    // ���������� �������� ������� Copy ��� ������ � ������� ���������
    // ����������� ������������ ��������� ������ ���� 'newnode->left' � 'newnode->right'
    newnode->left = Copy(node->left);
    newnode->right = Copy(node->right);

    return newnode;
}

// ������� ��� ������ ��������� ������ � ������
template < typename T>
void breadthFirstTraversal(TreeNode<T>* root) {
    if (root == nullptr) {
        return;
    }

    //������� ������� q
    std::queue < TreeNode<T>* > q;
    //�������� ��������� �� �������� ����
    q.push(root);

    //���� ���� ������� �� ������ ������
    while (!q.empty()) {
        //��������� ������ ������� �� ������� � ��������� ��� � ����������  current
        TreeNode<T>* current = q.front();
        //������� ��� �� �������
        q.pop();

        //������� ���� ������� �� �����
        cout << current->data << " ";

        //��������� ��������� �� ����� �������� ����
        if (current->left != nullptr) {
            //���� ���� �� ��������� ��� � �������
            q.push(current->left);
        }

        //��������� ��������� �� ������ �������� ����
        if (current->right != nullptr) {
            //���� ���� �� ��������� ��� � �������
            q.push(current->right);
        }
    }
}

//�������� ������� �� ������ ������
template < typename T>
void TreeToArrayNLR(TreeNode<T>* root,vector<T> & arr ){
    if (root == nullptr) {
        return;
    }

            //���������� ���� � ������
            arr.push_back(root->data);

            //���� ���� ������� ������ ��� ����� ��������� ��� � ������
            if (root->left) {
                TreeToArrayNLR(root->left, arr);
            }
            if (root->right)
            {
                TreeToArrayNLR(root->right, arr);
            }
}





/// �������� ������ ������

// ����� ���� �� ��������
// ���������� �������, �� ������� ��� ������ ����
// ���� -1, ���� ���� � ������� ��������� ���
template <typename T>
int SearchNode(TreeNode<T>* root, const T key, int depth = 0) {
    // ���� ����� �� nullptr, �� �������� �������� � ������ ���
    if (root == nullptr) {
        return -1;
    }

    // ����� � ������ ���������
    if (key > root->getData()) {
        SearchNode(root->getRight(), key, depth + 1);
    }

    // ����� � ����� ���������
    else if (key < root->getData()) {
        SearchNode(root->getLeft(), key, depth + 1);
    }

    // ���� key ����� �������� � ������� ����
    else return depth;
}

// �������� ������� ���� � �������� ������ ������
template <typename T>
TreeNode<T>* InsertNode(TreeNode<T>* root, const T value) {

    if (root == nullptr) {

        // ���� ������ ������, �� ������ ������ (������ ����)
        return new TreeNode<T>(value);
    }

    // ��������� ������ ���� � �����, ���� � ������ ���������
    if (value > root->getData()) {
        // ���� ��������, ������� ����� ��������, ������ ��������
        root->setRight(InsertNode(root->getRight(), value));
    }
    else if (value < root->getData()) {
        // ���� ��������, ������� ����� ��������, ������ ��������
        root->setLeft(InsertNode(root->getLeft(), value));
    }

    //���������� ������ ������
    return root;
}

// ���������� ������������ ���� � ���������
template <typename T>
TreeNode<T>* getNextLeft(TreeNode<T>* root)
{
    while (root->getLeft() != nullptr) {
        root = root->getLeft();
    }

    return root;
}

// ���������� ���������� �����������
template <typename T>
void Successor(TreeNode<T>* root, TreeNode<T>*& succ, int key) {

    // ������� ������ (������ ������)
    if (root == nullptr) {
        succ = nullptr;
    }

    // ���� ������ ����, ��� �������� ����� ����� ��������� ����������
    else if (root->getData() == key)
    {
        // ���� ���� ������ �������
        if (root->getRight() != nullptr) {
            // ������� ����� ����� ���� �� ������� �������
            succ = getNextLeft(root->getRight());
        }
    }

    // ����� ������� ���� � ����� ��� ������ ���������
    else if (key < root->getData())
    {
        succ = root;
        Successor(root->getLeft(), succ, key);
    }
    else {
        Successor(root->getRight(), succ, key);
    }
}

// �������� �������� ���� �� ��������� ������ ������
template <typename T>
TreeNode<T>* DeleteNode(TreeNode<T>* root, const T value) {

    // ������� ������
    if (root == nullptr) {
        return root;
    }

    // ����������� ����� �������, ���� �� ����� ������ ����, ������� ����� �������
    if (root->getData() > value) {
        root->setLeft(DeleteNode(root->getLeft(), value));
        return root;
    }
    else if (root->getData() < value) {
        root->setRight(DeleteNode(root->getRight(), value));
        return root;
    }

    // ����� ������ ���� �� ��������

    // ������ 1 � 2. ���� ���� ������ 1 ������� ��� ������� ���������� ���� (0 ��������)
    // ���� ��� ������ �������, �� ������ ����������� �� ����� ���������� ����
    if (root->getLeft() == nullptr) {
        TreeNode<T>* temp = root->getRight();
        delete root;
        return temp;
    }
    // ���� ��� ������� �������, �� ����� ����������� �� ����� ���������� ����
    else if (root->getRight() == nullptr) {
        TreeNode<T>* temp = root->getLeft();
        delete root;
        return temp;
    }

    // ������ 3. ���� ���� ��� �������
    else {

        // ����, ������� �������� ��������� ���������� �����������
        TreeNode<T>* succParent = root;

        // ������� ��������� ���������� (����� ����� ���� � ������ ���������) � ��� ��������
        TreeNode<T>* succ = root->getRight();
        while (succ->getLeft() != nullptr) {
            succParent = succ;
            succ = succ->getLeft();
        }


        // ������ �������� � ������ �������� ���� ������ � ������ ��������
        // ������� ������� ���������� ����������� ������ ����� �������� ��������
        // ���������� �����������

        if (succParent != root)
            succParent->setLeft(succ->getRight());
        else
            // ���� ������ �� ������ ��������� �� ����
            succParent->setRight(succ->getRight());


        // ������ �� ���������� ����������� ����������� �� ����� ���������� ����
        root->setData(succ->getData());

        // ������� ��������� ����������
        delete succ;
        return root;
    }
}
