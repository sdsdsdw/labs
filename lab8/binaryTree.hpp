// binaryTree.hpp
#pragma once

#include <cstdlib>
#include <iostream>
#include <cstdlib>

class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value);
};

class BinaryTree {
private:
    TreeNode* root;

    TreeNode* insertNode(TreeNode* node, int key);
    void inOrderTraversal(TreeNode* node);
    void destroyTree(TreeNode* node);
    TreeNode* searchKey(TreeNode* node, int key);

public:
    BinaryTree();
    ~BinaryTree();

    void buildTree(int n);
    void inOrderTraversal();
    TreeNode* searchKey(int key);
};
