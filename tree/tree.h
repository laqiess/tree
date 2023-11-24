#pragma once

#include <iostream>
#include <queue>
#include<vector>

using namespace std;
//узел дерева
template < typename T>



struct TreeNode {
    //int data;//хранит значение узла, типа int
    T data;//хранит значение узла, типа int
    TreeNode <T>* left; //указатель на левое поддерево
    TreeNode<T>* right;//указатель на правое поддерево

    //Конструктор
    /*TreeNode(T value) {
        data = value;//Принимает параметр value, который устанавливает значение data узла
        left = nullptr;//обгуляем,так как при создании узла еще нет дочерних узлов
        right = nullptr;//обгуляем,так как при создании узла еще нет дочерних узлов
    }*/

    //конструктор по умолчанию
    TreeNode() = default;




    //конструктор с параметрами
    TreeNode(const T& value, TreeNode<T>* left1 = nullptr, TreeNode<T>* right1 = nullptr) {
        data = value;
        left = left1;
        right = right1;
    }


    // Методы для доступа к значениям и потомкам узла
    T getData() {
        return data;// возвращает значение узла
    }

    TreeNode <T>* getLeft() {
        return left;//возвращает указатель на левое поддерево
    }

    TreeNode <T>* getRight() {
        return right;//возвращает указатель на правое поддерево
    }

    template < typename T>
    void setLeft(TreeNode<T>* node) {
        left = node;//устанавливает левое поддерево, получая указатель на узел node
    }

    template < typename T>
    void setData(T node) {
       data = node;//устанавливает левое поддерево, получая указатель на узел node
    }

    template < typename T>
    void setRight(TreeNode <T>* node) {
        right = node;//устанавливает правое поддерево, получая указатель на узел node
    }
};

// Функция для просмотра содержимого узла
template < typename T>
void printNode(TreeNode <T>* node) {
    cout << "узел =  " << node->getData() << endl;//получаем значение data (хранящееся в узле)
}

// функция добавления единицы к значению узла
template <typename T>
void add1(TreeNode<T>* root) {
    // Проверяем, что указатель 't' не равен nullptr, чтобы не обрабатывать пустое дерево
    if (root) {
        printNode(root + 1);
        PrintTreeNLR(root->left);
        PrintTreeNLR(root->right);
    }
}

// функция возведения в квадрат значения узла
template <typename T>
void squaring(TreeNode<T>* root) {
    root->setData(root->data() * root->data());
}

// L, R, N
// Функция для удаления узлов с обходом LRN
template < typename T>
void deleteTree(TreeNode<T>* root) {
    if (root == nullptr) {
        return;//проверяем, является ли указатель на корневой узел root равным nullptr,
        //если да,то функция завершается
    }

    deleteTree(root->getLeft());//функция вызывается рекурсивно для левого и правого потомка корневого узла
    deleteTree(root->getRight());
    ////Это позволяет удалить все поддеревья, начиная с левого и правого потомка корневого узла.

    delete root;//корневой узел root удаляется
}




// вывод дерева обратным обходом(ЛПК)
template < typename T>
void PrintTreeLRN(TreeNode<T>* t) {
    // Проверяем, что указатель 't' не равен nullptr, чтобы не обрабатывать пустое дерево
    if (t) {
        PrintTreeLRN(t->left);
        PrintTreeLRN(t->right);
        // Выводим значение текущего узла
        printNode(t);
    }
}

// вывод дерева симетричным обходом(ЛКП)
template < typename T>
void PrintTreeLNR(TreeNode<T>* t) {
    // Проверяем, что указатель 't' не равен nullptr, чтобы не обрабатывать пустое дерево
    if (t) {
        PrintTreeLNR(t->left);
        printNode(t);
        PrintTreeLNR(t->right);
    }
}


// вывод дерева прямым обходом(КЛП)
template < typename T>
void PrintTreeNLR(TreeNode<T>* t) {
    // Проверяем, что указатель 't' не равен nullptr, чтобы не обрабатывать пустое дерево
    if (t) {
        printNode(t);
        PrintTreeNLR(t->left);
        PrintTreeNLR(t->right);
    }
}



//обратный метод прохождения(ЛПК)
template < typename T>
void CountNodes(TreeNode<T>* t, int& count) {
    if (t != nullptr) {
        // Рекурсивно вызываем функцию CountNodes для левого и правого поддерева
        CountNodes(t->left, count);
        CountNodes(t->right, count);

        count++;
    }
}


// эта функция использует обратный метод прохождения(ЛПК)
//поиск количества листов дерева
template < typename T>
void CountLeaf(TreeNode<T>* t, int& count) {
    // Проверяем, что указатель на текущий узел не равен nullptr
    if (t != nullptr) {
        // Рекурсивно вызываем функцию CountLeaf для левого и правого поддерева
        CountLeaf(t->left, count);
        CountLeaf(t->right, count);

        // Проверяем, является ли текущий узел листовым узлом 
        // (если оба указателя на левое и правое поддерево равны nullptr)
        if (t->left == nullptr && t->right == nullptr) {
            count++;
        }
    }
}


// функция использует обратный метод прохождения(ЛПК) для вычисления глубины
// левого и правого поддеревьев узла и возвращает результирующее
// значение глубины, равное 1 + max(depthLeft, depthRight).
// глубина пустого дерева равна -1
template < typename T>
int Depth(TreeNode<T>* t) {
    int depthLeft, depthRight, depthval;
    // Если указатель на текущий узел равен nullptr, то возвращаем -1 в качестве глубины
    if (t == nullptr) {
        depthval = -1;
    }
    else
    {
        depthLeft = Depth(t->left);
        depthRight = Depth(t->right);

        // Вычисляем глубину текущего узла как максимум из глубин левого и правого поддерева, увеличенную на 1
        depthval = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
    }
    return depthval;
}



// функция для копирование бинарного дерева
template < typename T>
TreeNode<T>* Copy(TreeNode<T>* node) {
    // Проверяем, что указатель 'node' не равен nullptr, чтобы не копировать пустое дерево
    if (node == nullptr)
        return nullptr;
    // Создаем новый узел с данными текущего узла
    TreeNode<T>* newnode = new TreeNode<T>(node->data);
    // Рекурсивно вызываем функцию Copy для левого и правого поддерева
    // присваиваем возвращаемый указатель новому узлу 'newnode->left' и 'newnode->right'
    newnode->left = Copy(node->left);
    newnode->right = Copy(node->right);

    return newnode;
}

// Функция для обхода бинарного дерева в ширину
template < typename T>
void breadthFirstTraversal(TreeNode<T>* root) {
    if (root == nullptr) {
        return;
    }

    //создаем очередь q
    std::queue < TreeNode<T>* > q;
    //помещает указатель на корневой узел
    q.push(root);

    //цикл пока очередь не станет пустой
    while (!q.empty()) {
        //извлекает первый элемент из очереди и сохраняет его в переменную  current
        TreeNode<T>* current = q.front();
        //удаляет его из очереди
        q.pop();

        //выводит этот элемент на экран
        cout << current->data << " ";

        //проверяет существет ли левый дочерний узел
        if (current->left != nullptr) {
            //если есть то добавляет его в очередь
            q.push(current->left);
        }

        //проверяет существет ли правый дочерний узел
        if (current->right != nullptr) {
            //если есть то добавляет его в очередь
            q.push(current->right);
        }
    }
}

//создание массива на основе дерева
template < typename T>
void TreeToArrayNLR(TreeNode<T>* root,vector<T> & arr ){
    if (root == nullptr) {
        return;
    }

            //добавление узла в массив
            arr.push_back(root->data);

            //если есть потомок справа или слева добавляем его в массив
            if (root->left) {
                TreeToArrayNLR(root->left, arr);
            }
            if (root->right)
            {
                TreeToArrayNLR(root->right, arr);
            }
}





/// Бинарное дерево поиска

// поиск узла по значению
// возвращает уровень, на котором был найден узел
// либо -1, если узла с искомым значением нет
template <typename T>
int SearchNode(TreeNode<T>* root, const T key, int depth = 0) {
    // если дошли до nullptr, до искомого значения в дереве нет
    if (root == nullptr) {
        return -1;
    }

    // поиск в правом поддереве
    if (key > root->getData()) {
        SearchNode(root->getRight(), key, depth + 1);
    }

    // поиск в левом поддереве
    else if (key < root->getData()) {
        SearchNode(root->getLeft(), key, depth + 1);
    }

    // если key равен значению в текущем узле
    else return depth;
}

// операция вставки узла в бинарное дерево поиска
template <typename T>
TreeNode<T>* InsertNode(TreeNode<T>* root, const T value) {

    if (root == nullptr) {

        // если дерево пустое, то создаём корень (первый узел)
        return new TreeNode<T>(value);
    }

    // Вставляем данные либо в левое, либо в правое поддерево
    if (value > root->getData()) {
        // если значение, которое нужно добавить, больше текущего
        root->setRight(InsertNode(root->getRight(), value));
    }
    else if (value < root->getData()) {
        // если значение, которое нужно добавить, меньше текущего
        root->setLeft(InsertNode(root->getLeft(), value));
    }

    //возвращаем корень дерева
    return root;
}

// Нахождение минимального узла в поддереве
template <typename T>
TreeNode<T>* getNextLeft(TreeNode<T>* root)
{
    while (root->getLeft() != nullptr) {
        root = root->getLeft();
    }

    return root;
}

// нахождение ближайшего наибольшего
template <typename T>
void Successor(TreeNode<T>* root, TreeNode<T>*& succ, int key) {

    // Базовый случай (пустое дерево)
    if (root == nullptr) {
        succ = nullptr;
    }

    // если найден узел, для которого нужно найти ближайшее наибольшее
    else if (root->getData() == key)
    {
        // если есть правый потомок
        if (root->getRight() != nullptr) {
            // находим самый левый узел от правого потомка
            succ = getNextLeft(root->getRight());
        }
    }

    // поиск нужного узла в левом или правом поддереве
    else if (key < root->getData())
    {
        succ = root;
        Successor(root->getLeft(), succ, key);
    }
    else {
        Successor(root->getRight(), succ, key);
    }
}

// операция удаления узла из бинарного дерева поиска
template <typename T>
TreeNode<T>* DeleteNode(TreeNode<T>* root, const T value) {

    // базовый случай
    if (root == nullptr) {
        return root;
    }

    // рекурсивный вызов функции, пока не будет найден узел, который нужно удалить
    if (root->getData() > value) {
        root->setLeft(DeleteNode(root->getLeft(), value));
        return root;
    }
    else if (root->getData() < value) {
        root->setRight(DeleteNode(root->getRight(), value));
        return root;
    }

    // Когда найден узел на удаление

    // Случаи 1 и 2. если есть только 1 потомок или удалить необходимо лист (0 потомков)
    // если нет левого потомка, то правый поднимается на место удаляемого узла
    if (root->getLeft() == nullptr) {
        TreeNode<T>* temp = root->getRight();
        delete root;
        return temp;
    }
    // если нет правого потомка, то левый поднимается на место удаляемого узла
    else if (root->getRight() == nullptr) {
        TreeNode<T>* temp = root->getLeft();
        delete root;
        return temp;
    }

    // Случай 3. если есть оба потомка
    else {

        // узел, который является родителем ближайшего наибольшего
        TreeNode<T>* succParent = root;

        // Находим ближайшее наибольшее (самый левый узел в правом поддереве) и его родителя
        TreeNode<T>* succ = root->getRight();
        while (succ->getLeft() != nullptr) {
            succParent = succ;
            succ = succ->getLeft();
        }


        // задача сводится к случаю удаления узла только с правым потомком
        // правого потомка ближайшего наибольшего делаем левым потомком родителя
        // ближайшего наибольшего

        if (succParent != root)
            succParent->setLeft(succ->getRight());
        else
            // если спуска по левому поддереву не было
            succParent->setRight(succ->getRight());


        // данные из ближайшего наибольшего переносятся на место удаляемого узла
        root->setData(succ->getData());

        // Удаляем ближайшее наибольшее
        delete succ;
        return root;
    }
}
