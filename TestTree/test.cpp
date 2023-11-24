//@author:�������� �������
#include "pch.h"
#include "../tree/TreeNode.h"

// ����������� ������
TreeNode<int>* createTree1() {

    // �������� ��������� �� ���� ������ 
    TreeNode<int>* rightleaf, * leftleaf, * root;


    /*
              50
             /  \
           30    70
          /  \
        20   40
    */

    rightleaf = new TreeNode<int>(40);
    leftleaf = new TreeNode<int>(20);


    root = new TreeNode<int>(30, leftleaf, rightleaf);

    rightleaf = new TreeNode<int>(70);

    root = new TreeNode<int>(50, root, rightleaf);

    return root;
}

// ����������� ������
TreeNode<int>* createTree2() {

    // �������� ��������� �� ���� ������ 
    TreeNode<int>* rightleaf, * root;


    //       10
    //        \
    //         17
    //          \
    //           27
    //            \
    //             56

    //�������� ��������� �� ���� ������ (��������� �� ����� � ������ ���� nullptr)
    rightleaf = new TreeNode<int>(56);

    //�������� ���� ������ � ������ ��������
    root = new TreeNode<int>(27, nullptr, rightleaf);

    // ��������� rightleaf ����������� �� ������ ��� ��������� ����
    rightleaf = root;

    //�������� ���� � ������ ��������
    root = new TreeNode<int>(17, nullptr, rightleaf);
    rightleaf = root;

    //�������� ���� ������ � ������ ��������
    root = new TreeNode<int>(10, nullptr, rightleaf);

    return root;
}

// ����������� �����
TreeNode<int>* createTree3() {

    // �������� ��������� �� ���� ������ 
    TreeNode<int>* leftleaf, * root;


    //       36
    //       /  
    //      34   
    //      /   
    //     6      



    //�������� ����
    root = new TreeNode<int>(6);

    // ��������� rightleaf ����������� �� ������ ��� ��������� ����
    leftleaf = root;

    //�������� ���� � ����� ��������
    root = new TreeNode<int>(34, leftleaf, nullptr);
    leftleaf = root;

    //�������� ���� ������ � ����� ��������
    root = new TreeNode<int>(36, leftleaf, nullptr);

    return root;
}

//������ ������
TreeNode<int>* createTree4() {

    // �������� ��������� �� ���� ������ 
    TreeNode<int>* leftleaf, * root;

    //     6      
    //   /  \
    // 


    //�������� ����
    root = new TreeNode<int>(6);

    return root;
}

//����� ������� ������
TEST(TestCaseName, Depth) {
    // �������� ��������� �� ������ ������ 
    TreeNode<int>* root1 = createTree1();
  EXPECT_EQ(2, Depth(root1));

  // �������� ��������� �� ������ ������ 
  TreeNode<int>* root2 = createTree2();
  EXPECT_EQ(3, Depth(root2));

  // �������� ��������� �� ������ ������ 
  TreeNode<int>* root3 = createTree3();
  EXPECT_EQ(2, Depth(root3));

  // �������� ��������� �� ������ ������ 
  TreeNode<int>* root4 = createTree4();
  EXPECT_EQ(0, Depth(root4));

  // ������ ������
  TreeNode<int>* root5 = nullptr;
  EXPECT_EQ(-1, Depth(root5));
}


//����� ���������� �������
TEST(TestTreeNode, TestCountLeaf) {

     //�������� ��������� �� ������ ������ 
    TreeNode<int>* root1 = createTree1();
    int count = 0;
    CountLeaf(root1, count);
    EXPECT_EQ(3, count );

    //�������� ��������� �� ������ ������
    TreeNode<int>* root2 = createTree2();
    count = 0;
    CountLeaf(root2, count);
    EXPECT_EQ(1, count);

    //�������� ��������� �� ������ ������
    TreeNode<int>* root3 = createTree3();
    count = 0;
    CountLeaf(root3, count);
    EXPECT_EQ(1, count);

    //�������� ��������� �� ������ ������
    TreeNode<int>* root4 = createTree4();
    count = 0;
    CountLeaf(root4, count);
    EXPECT_EQ(1, count);

    //������ ������
    TreeNode<int>* root5 = nullptr;
    count = 0;
    CountLeaf(root5, count);
    EXPECT_EQ(0, count);
}

//���� �������
TEST(TestTreeNode, TestToArray) {

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root1 = createTree1();

    vector<int> arr, arr1 = { 50, 30, 20, 40,70};
    TreeToArrayNLR(root1, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������
    arr1.clear();//������� ������

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root2 = createTree2();

    arr1 = { 10,17,27,56 };
    TreeToArrayNLR(root2, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������
    arr1.clear();//������� ������

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root3 = createTree3();

    arr1 = { 36,34,6 };
    TreeToArrayNLR(root3, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������
    arr1.clear();//������� ������

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root4 = createTree4();

    arr1 = { 6 };
    TreeToArrayNLR(root4, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������
    arr1.clear();//������� ������

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root5 = nullptr;

    arr1 = { };
    TreeToArrayNLR(root5, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������
    arr1.clear();//������� ������

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root6 = new TreeNode<int>(2);

    arr1 = { 2 };
    TreeToArrayNLR(root6, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������
    arr1.clear();//������� ������
}

//���� �����������
TEST(TestTreeNode, TestCopyTree) {
    vector<int> arr, arr1;

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root1 = createTree1();
    TreeNode<int>* rootTreeCopy = Copy(root1);

    TreeToArrayNLR(root1, arr);
    TreeToArrayNLR(rootTreeCopy, arr1);
    EXPECT_EQ(arr, arr1);
    arr.clear(); arr1.clear();//������� ������
    deleteTree(rootTreeCopy);

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root2 = createTree2();
    rootTreeCopy = Copy(root2);

    TreeToArrayNLR(root2, arr);
    TreeToArrayNLR(rootTreeCopy, arr1);
    EXPECT_EQ(arr, arr1);
    arr.clear(); arr1.clear();//������� ������
    deleteTree(rootTreeCopy);

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root3 = createTree3();
    rootTreeCopy = Copy(root3);

    TreeToArrayNLR(root3, arr);
    TreeToArrayNLR(rootTreeCopy, arr1);
    EXPECT_EQ(arr, arr1);
    arr.clear(); arr1.clear();//������� ������
    deleteTree(rootTreeCopy);

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root4 = createTree4();
    rootTreeCopy = Copy(root4);

    TreeToArrayNLR(root4, arr);
    TreeToArrayNLR(rootTreeCopy, arr1);
    EXPECT_EQ(arr, arr1);
    arr.clear(); arr1.clear();//������� ������
    deleteTree(rootTreeCopy);

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root5 = nullptr;
    rootTreeCopy = Copy(root5);

    TreeToArrayNLR(root5, arr);
    TreeToArrayNLR(rootTreeCopy, arr1);
    EXPECT_EQ(arr, arr1);
    arr.clear(); arr1.clear();//������� ������
    deleteTree(rootTreeCopy);

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root6 = new TreeNode<int>(6);
    rootTreeCopy = Copy(root6);

    TreeToArrayNLR(root6, arr);
    TreeToArrayNLR(rootTreeCopy, arr1);
    EXPECT_EQ(arr, arr1);
    arr.clear(); arr1.clear();//������� ������
    deleteTree(rootTreeCopy);
}

//���� �������� ������
TEST(TestTreeNode, TestSearch) {

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root1 = createTree1();
    EXPECT_EQ(1, SearchNode(root1, 70));
    EXPECT_EQ(2, SearchNode(root1, 20));
    EXPECT_EQ(-1, SearchNode(root1, 25));

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root2 = createTree2();
    EXPECT_EQ(3, SearchNode(root2, 56));
    EXPECT_EQ(-1, SearchNode(root2, 25));

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root3 = createTree3();
    EXPECT_EQ(0, SearchNode(root3, 36));
    EXPECT_EQ(-1, SearchNode(root3, 25));

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root4 = createTree4();
    EXPECT_EQ(0, SearchNode(root4, 6));
    EXPECT_EQ(-1, SearchNode(root4, 25));

    //������ ������
    TreeNode<int>* root5 = nullptr;
    EXPECT_EQ(-1, SearchNode(root5, 25));

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root6 = new TreeNode<int>(5);
    EXPECT_EQ(0, SearchNode(root6, 5));
    EXPECT_EQ(-1, SearchNode(root6, 25));
}


//���� ������ ���������� �����������
TEST(TestTreeNode, TestSuccessor) {
    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root1 = createTree1();

    TreeNode<int>* s = nullptr;
    Successor(root1, s, 50);
    EXPECT_EQ(70, s->getData());

    s = nullptr;
    Successor(root1, s, 70);
    EXPECT_EQ(nullptr, s);

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root2 = createTree2();

    s = nullptr;
    Successor(root2, s, 10);
    EXPECT_EQ(17, s->getData());

    s = nullptr;
    Successor(root2, s, 56);
    EXPECT_EQ(nullptr, s);

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root3 = createTree3();

    s = nullptr;
    Successor(root3, s, 6);
    EXPECT_EQ(34, s->getData());

    s = nullptr;
    Successor(root3, s, 36);
    EXPECT_EQ(nullptr, s);

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root4 = nullptr;

    s = nullptr;
    Successor(root4, s, 6);
    EXPECT_EQ(nullptr, s);

    //������ ������
    TreeNode<int>* root5 = nullptr;

    s = nullptr;
    Successor(root5, s, 10);
    EXPECT_EQ(nullptr, s);

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root6 = new TreeNode<int>(2);
    s = nullptr;
    Successor(root6, s, 2);
    EXPECT_EQ(nullptr, s);
}


//���� ������� ����
TEST(TestTreeNode, TestInsertNode) { 
    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root1 = createTree1();

    root1 = InsertNode(root1, 50);
    vector<int> arr, arr1 = { 50, 30, 20, 40,70 };
    TreeToArrayNLR(root1, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������

    /*
              50
             /  \
           30    70
          /  \
        20   40
    */


    root1 = InsertNode(root1, 45);
    arr1 = { 50, 30, 20, 40, 45, 70 };
    TreeToArrayNLR(root1, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������


    root1 = InsertNode(root1, 90);
    arr1 = { 50, 30, 20, 40, 45, 70, 90 };
    TreeToArrayNLR(root1, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root2 = createTree2();
    root2 = InsertNode(root2, 27);
    arr1 = { 10, 17, 27, 56 };
    TreeToArrayNLR(root2, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������
    //       10
    //        \
    //         17
    //          \
    //           27
    //            \
    //             56

    root2 = InsertNode(root2, 25);
    arr1 = { 10, 17, 27, 25, 56 };
    TreeToArrayNLR(root2, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root3 = createTree3();
    root3 = InsertNode(root3, 6);
    arr1 = { 36, 34, 6 };
    TreeToArrayNLR(root3, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������
    //       36
     //       /  
     //      34   
     //      /   
     //     6   

    root3 = InsertNode(root3, 17);
    arr1 = { 36, 34, 6, 17 };
    TreeToArrayNLR(root3, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root4 = createTree4();
    root4 = InsertNode(root4, 6);
    arr1 = { 6 };
    TreeToArrayNLR(root4, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������
     //     6      
     //   /  \
     // 

    root4 = InsertNode(root4, 24);
    arr1 = { 6, 24 };
    TreeToArrayNLR(root4, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������

    //������ ������
    TreeNode<int>* root5 = nullptr;
    root5 = InsertNode(root5, 8);
    arr1 = { 8 };
    TreeToArrayNLR(root5, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root6 = new TreeNode<int>(5);
    root6 = InsertNode(root6, 57);
    arr1 = { 5, 57 };
    TreeToArrayNLR(root6, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������
}


//���� �������� ����
TEST(TestTreeNode, TestDeleteNode) {
    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root1 = createTree1();

    root1 = DeleteNode(root1, 24);
    vector<int> arr, arr1 = { 50, 30, 20, 40,70 };
    TreeToArrayNLR(root1, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������
    /*
              50
             /  \
           30    70
          /  \
        20   40
    */

    root1 = DeleteNode(root1, 40);
    arr1 = { 50, 30, 20, 70 };
    TreeToArrayNLR(root1, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������

    root1 = DeleteNode(root1, 20);
    arr1 = { 50, 30,  70 };
    TreeToArrayNLR(root1, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root2 = createTree2();
    root2 = DeleteNode(root2, 20);
    arr1 = { 10, 17, 27, 56 };
    TreeToArrayNLR(root2, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������

    //       10
    //        \
    //         17
    //          \
    //           27
    //            \
    //             56

    root2 = DeleteNode(root2, 27);
    arr1 = { 10, 17, 56 };
    TreeToArrayNLR(root2, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root3 = createTree3();
    root3 = DeleteNode(root3, 27);
    arr1 = { 36, 34, 6 };
    TreeToArrayNLR(root3, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������

     //       36
     //       /  
     //      34   
     //      /   
     //     6   


    root3 = DeleteNode(root3, 6);
    arr1 = { 36, 34 };
    TreeToArrayNLR(root3, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root4 = createTree4();
    root4 = DeleteNode(root4, 8);
    arr1 = {6 };
    TreeToArrayNLR(root4, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������
    //     6      
    //   /  \
    // 

    root4 = DeleteNode(root4, 6);
    arr1 = { };
    TreeToArrayNLR(root4, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������

    //����� ������
    TreeNode<int>* root5 = nullptr;
    root5 = DeleteNode(root5, 78);
    arr1 = { };
    TreeToArrayNLR(root5, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������

    //�������� ��������� �� ������ ������ 
    TreeNode<int>* root6 = new TreeNode<int>(5);
    root6 = DeleteNode(root6, 34);
    arr1 = { 5 };
    TreeToArrayNLR(root6, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������

    root6 = DeleteNode(root6, 5);
    arr1 = {  };
    TreeToArrayNLR(root6, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();//������� ������
}