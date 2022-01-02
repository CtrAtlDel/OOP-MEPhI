
#include "SparceMatrix.h"

using namespace SparceMatrix;

Tree *createTree() {
    Tree* tree;
    tree = new Tree;
    tree->root = nullptr;
    return tree;
}

Node *createNode(int &i, int &j, int &data) {
    Node *node = new Node;
    node->data->data = data;/// init data
    node->data->i = i;
    node->data->j = j;
    node->left = node->right = node->parent = nullptr;
    node->subTree = nullptr;
    return node;
}

int insert(Node **root, int &i, int &j, int &data) {
    Node *new_node = nullptr;
    Node *ptr = *root;
    if (*root == nullptr) {
        *root = ::createNode(i, j, data); /// если дерево пусто
        return 1;
    }
    while (ptr != nullptr) {
        if (ptr->data->i > i) {
            if (ptr->right != nullptr) {
                ptr = ptr->right;
                continue;
            } else {
                ptr->right = ::createNode(i, j, data);
                return 1;
            }
        }
        if (ptr->data->i < i) {
            if (ptr->left != nullptr) {
                ptr = ptr->left;
                continue;
            } else {
                ptr->left = ::createNode(i, j, data);
                return 1;
            }
        }
        if (ptr->data->i == i) {
            if (ptr->data->j == j) {
                ptr->data->data = data;
                return 1;
            } else {
                /// идем в поддерево
            }

        }
    }
    return -1;
}

