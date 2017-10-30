//
//  BinarySearchTree.h
//  Algorithms
//
//  Created by Harshavardhan K K on 21/07/16.
//  Copyright © 2016 Harshavardhan K. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <stdlib.h>
#include <stdint.h>
#include <exception>


namespace Algorithms {
    
    template<typename KeyT, typename ValueT>
    
    class BST {
        
    private:
        
        /*
         binary search tree definition
         */
        
        struct treeNode {
            
            KeyT key;
            ValueT value;
            treeNode *parent;
            treeNode *left;
            treeNode *right;
            
        };
        
        class BSTException: public std::exception {
        public:
            virtual const char * what() const throw() {
                return "Key does not exist";
            }
        } excp_key;
        
        treeNode * m_root;
        
        BST(const BST&);
        BST& operator =(const BST&);
        
    public:
        
        BST():m_root(NULL) {};
        
        ~BST() {
            __destruct(m_root);
        }
        
        // find key
        
        treeNode * find(const KeyT& key) {
            treeNode *node = m_root;
            
            while(node != NULL && key != node->key) {
                
                if(key < node->key) {
                    node = node->left;
                    
                } else {
                    node = node->right;
                }
            }
            
            return node;
        }
        
        // insert a new data into the binary search tree
        
        void insert(const KeyT& key, const ValueT value) {
            
            treeNode *node = new treeNode;
            node->key = key;
            node->value = value;
            node->left = node->right = node->parent = NULL;
            
            treeNode *anotherNode = m_root;
         
            
            while(anotherNode != NULL) {
                
                if(key < anotherNode->key) {
                    anotherNode = anotherNode->left;
                    
                } else {
                    anotherNode = anotherNode->right;
                }
                
            }
                        
            node->parent = anotherNode;
            
            if (anotherNode == NULL) { // doesnt the while loop end because anotherNode became NULL?
                m_root = node;
                
            } else if(key < anotherNode->key) {
                anotherNode->left = node;
                
            } else {
                anotherNode->right = node;
            }
        }
        
        // delete a key from the binary search tree
        
        bool deleteKey(const KeyT& key) {
            treeNode *childNode = find(key);
            
            if(childNode == NULL)
                return false;
            
            if(childNode->left == NULL) {
                transplant(childNode, childNode->right);
                
            } else if(childNode->right == NULL) {
                transplant(childNode, childNode->left);
                
            } else {
                // find the minimum element of the right subtree
                treeNode *minimumNode = minimum(childNode->right);
                
                if(minimumNode->parent != childNode) {
                    
                    transplant(minimumNode, minimumNode->right); // replace the minimumNode with the right child
                    minimumNode->right = childNode->right; // replace the right child of minimumNode with the rigth child of childNode
                    minimumNode->right->parent = minimumNode;
                }
                
                // replace childNode with minimumNode
                transplant(childNode, minimumNode);
                minimumNode->left = childNode->left;
                minimumNode->left->parent = minimumNode;
                
            }
            
            delete childNode;
            
            return true;
        }
        
        void print_helper() {
            print_tree(m_root, 0);
        }
        
    private:
        
        void print_tree(treeNode *node, int indent) {
            if (node == NULL) {
                return;
            }
            
            print_tree(node->right, indent + 1);
            int i;
            
            for(i = 0; i < indent; i++) {
                printf(" ");
            }
            
            std::cout << "[" << node->key << "," << node->value << "]" << std::endl;
            
            print_tree(node->left, indent + 1);
        }

        
        void __destruct(treeNode* node) {
            
            if(node == NULL) return;
            
            __destruct(node->left);
            __destruct(node->right);
            
            delete node;
        }
        
        // replace one node with another
        
        void transplant(treeNode *node, treeNode* anotherNode) {
            
            if(node->parent == NULL) {
                m_root = anotherNode;
                
            } else if( node == node->parent->left) {
                node->parent->left = anotherNode;
                
            } else {
                node->parent->right = anotherNode;
            }
            
            if(anotherNode != NULL) {
                anotherNode->parent = node->parent;
            }
        }
        
        treeNode *minimum(treeNode *node) {
            
            while(node->left != NULL) {
                node = node->left;
            }
            
            return node;
        }
    };
}


#endif /* BinarySearchTree_h */
