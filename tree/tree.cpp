// tree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//@autor Ключерев А.В.


#include <iostream>
#include "TreeNode.h"
using namespace std;
 


int main() {
    setlocale(LC_ALL, "Russian");
    //TreeNode <int> * root = createBinaryTree <T>();//функция создает и заполняет бинарное дерево.
    TreeNode<int>* root = new TreeNode <int>(50);//Создается корневой узел с значением 50
    root->setLeft(new TreeNode <int> (30));//для корневого узла создается левый потомок
    root->setRight(new TreeNode<int>(70));//для корневого узла создается правый потомок
    root->getLeft()->setLeft(new TreeNode<int>(20));//для левого потомка создается левый потомок
    root->getLeft()->setRight(new TreeNode<int>(40));//для левого потомка создается левый потомок

    // Изобразить дерево
     /*
              50       
             /  \     
           30    70    
          /  \        
        20   40       
    */

    printNode(root); // Вывод данных корневого узла
    printNode(root->getLeft()); // Вывод данных левого дочернего узла корневого узла
    printNode(root->getRight());// Вывод данных правого дочернего узла корневого узла
    printNode(root->getLeft()->getLeft());
    printNode(root->getLeft()->getRight());


    cout << "LRN: " << endl;
    // вывод дерева обратным обходом(ЛПК)
    PrintTreeLRN(root, &printNode);

    cout << "LNR: " << endl;
    // вывод дерева симметричным обходом(ЛКП)
    PrintTreeLNR(root, &printNode);

    cout << "NLR: " << endl;
    // вывод дерева прямым обходом(КЛП)
    PrintTreeNLR1(root, &printNode);
    cout << endl;


    //вывод количества узлов
    int countN = 0;
    CountNodes(root, countN);
    cout << "Количество узлов = " << countN << endl;
    cout << endl;


    //вывод количества листьев
    int count = 0;
    CountLeaf(root, count);
    cout << "количество листьев = " << count << endl;
    cout << endl;


    //вывод глубины дерева
    cout << "глубина дерева = " << Depth(root) << endl;
    cout << endl;


    // копирование дерева
    TreeNode<int>* rootTreeCopy = Copy(root);
    cout << "Копия дерева: " << endl;
    PrintTreeLRN(rootTreeCopy, &printNode);
    cout << endl;

    // Обход бинарного дерева в ширину
    std::cout << "обход дерева в ширину: ";
    breadthFirstTraversal(root);
    cout << endl;

    int countNodes = 0;
    CountNodes(root, countNodes);
    vector <int> arr;
    TreeToArrayNLR(root, arr);
    cout << "массив элементов вектора: ";
    for (int i = 0; i < countNodes; i++) {
        cout << arr[i] <<"  ";
    }
    arr.clear();
    cout << endl;




    // Просмотреть содержимое узла
    //printNode(root->getLeft());//выводит содержимого левого потомка корневого узла

    cout << "\n\nПрименение функции к узлам дерева";
    cout << "\nПрибавление 10 к каждому элемента дерева: "<<endl;
    PrintTreeNLR1(root, &Inc);
    PrintTreeNLR1(root, &printNode);

    cout << "\nДобавление единицы: " << endl;
    PrintTreeNLR1(root, &add1);
    PrintTreeNLR1(root, &printNode);

    cout << "\nВозведение элементов в квадрат: "<< endl;
    PrintTreeNLR1(root, &squaring);
    PrintTreeNLR1(root, &printNode);
    cout << endl;


    // Удалить все узлы
    deleteTree(root);
    cout << "Дерево успешно удалено" << endl;

    return 0;
}


