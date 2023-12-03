// binaryTree.cpp
#include "binaryTree.hpp"

TreeNode::TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {
    destroyTree(root);
}

void BinaryTree::destroyTree(TreeNode* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

void BinaryTree::buildTree(int n) {
    for (int i = 0; i < n; ++i) {
        int randomValue = rand() % 101;
        root = insertNode(root, randomValue);
    }
}

TreeNode* BinaryTree::insertNode(TreeNode* node, int key) {
    if (!node) {
        return new TreeNode(key);
    }

    if (key < node->key) {
        node->left = insertNode(node->left, key);
    } else if (key > node->key) {
        node->right = insertNode(node->right, key);
    }

    return node;
}

void BinaryTree::inOrderTraversal() {
    inOrderTraversal(root);
    std::cout << std::endl;
}

void BinaryTree::inOrderTraversal(TreeNode* node) {
    if (node) {
        inOrderTraversal(node->left);
        std::cout << node->key << " ";
        inOrderTraversal(node->right);
    }
}

TreeNode* BinaryTree::searchKey(int key) {
    return searchKey(root, key);
}

TreeNode* BinaryTree::searchKey(TreeNode* node, int key) {
    if (!node || node->key == key) {
        return node;
    }

    if (key < node->key) {
        return searchKey(node->left, key);
    } else {
        return searchKey(node->right, key);
    }
}
