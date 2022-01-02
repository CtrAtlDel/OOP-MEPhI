//
// Created by Ivan Kvasov on 02.01.2022.
//

#ifndef SPARCEMATRIX_BIB_H
#define SPARCEMATRIX_BIB_H

#include<iostream>

namespace SparceMatrix {
    struct Node;
    struct Tree;
    struct Data;

    struct Data {
        int i;
        int j;
        int data;
    };
    struct Node {
        Node *left;
        Node *right;
        Node* parent;
        Data *data;
        Tree *subTree; // строка матрицы

    };
    struct Tree {
        int n;
        int m;
        Node *root;
    };

    template<typename T>
    int getNum(T &a) {
        std::cin >> a;
        if (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return -1;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;
    }

    Tree *createTree();

    Node *createNode(int &i, int &j, int &data);

    int insert(Tree *tree, int &i, int &j, int &data);

    int printMatrix(Tree *tree);
}
#endif //SPARCEMATRIX_BIB_H
