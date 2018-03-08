//
//  BinaryTree.cpp
//  Algorithms
//
//  Created by Harshavardhan K K on 08/03/18.
//  Copyright © 2018 Harshavardhan K. All rights reserved.
//

#include <iostream>
using namespace std;

template <typename T>

struct BinaryTreeNode {
    
    T data;
    BinaryTreeNode* right;
    BinaryTreeNode* left;
    
};

template <typename T>

class BinaryTree {
    BinaryTreeNode<T>* root;
    
public:
    
    BinaryTree() {
        root = nullptr;
        root->left = root->right = nullptr;
    }
    
    void insert(T data) {
        BinaryTreeNode<T> child = root;
        
        if(root == nullptr) {
            root->data = data;
            return;
        }
        
        
    }
    
};
