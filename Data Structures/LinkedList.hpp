//
//  LinkedList.hpp
//  Algorithms
//
//  Created by Harshavardhan K K on 11/08/16.
//  Copyright © 2016 Harshavardhan K. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <iostream>

template <typename T>

class Node {
    
public:
    
    Node* next;
    T data;
    
    Node(const T data) {
        this->data = data;
    }
    
    T getValue() {
        return data;
    }
};

template <typename T>

class LinkedList {
    
public:
    
    LinkedList() {
        root = NULL;
        size = 0;
        
    }
    
    LinkedList(const T data) {
        
        root->data = data;
        
        size = 0;
        size++;
        
    }
    
    ~LinkedList() {
        
        for (int i = 0; i < size; i++) {
            deleteNode(i);
        }
    }
    
    void insert(const T data, size_t position = 0) {
        
        if (root == NULL) {
            root->data = data;
            root->next = NULL;
            
            return;
        }
        
        if (position == 0) {
            root->data = data;
            
            return;
        }
        
        Node<T>* node = new Node<T>(data);
        Node<T> *childNode = root;
        int currentPosition = 0;
        
        while(childNode->next != NULL && currentPosition < position - 1) {
            childNode = childNode->next;
            currentPosition++;
        }
        
        Node<T>* nodeAtPosition = childNode->next;
        childNode->next = node;
        childNode->next->next = nodeAtPosition;
        
        size++;
        
        
    }
    
    void append(const T data) {
        
        Node<T>* node = root;
        //  std::cout << "Appending";
        
        if (root == NULL) {
            root = new Node<T>(data);
            size = 1;
            return;
        }
        
        while(node->next != NULL) {
            node = node->next;
        }
        
        Node<T>* childNode = new Node<T>(data);
        node->next = childNode;
        
        size++;
        
        return;
    }
    
    void deleteNode(const int position) {
        
        if (position > size) {
            std::cout << "index larger than list size\n";
            return;
        }
        
        int current_position = 0;
        Node<T>* node = root;
        
        while (node != NULL && current_position < position - 1 ) {
            node = node->next;
            current_position++;
        }
        
        Node<T>* childNode = node->next->next;
        node->next = childNode;
        
        size--;
        
    }
    
    bool search(T value) {
        
        Node<T> *child = root;
        
        while(child != NULL) {
            
            if(child->data == value) {
                return true;
            }
            
            child = child->next;
        }
        
        return false;
    }
    
    void printList() {
        
        Node<T>* node = root;
        
        while(node != NULL) {
            std::cout << node->getValue() << "->";
            node = node->next;
        }
        
        std::cout << "NULL" << std::endl;
        
        return;
    }
    
    void removeDuplicate() {
        
        Node<T>* node = root;
        
        while(node != NULL) {
            
            int value = node->data;
            int thisFre = frequency(value);
            
            if(thisFre > 1) {
                
                int pos = position(value);
                deleteNode(pos);
            }
            
            node = node->next;
        }
    }
    
    
    std::string getList_name() {return list_name;}
    size_t getSize() {return size;}
    
private:
    
    Node<T>* root;
    
    std::string list_name;
    size_t size;
    
    int frequency(Node<T>* node, T num) {
        int count = 0;
        
        while(node != NULL) {
            
            if(num == node->data) {
                count++;
            }
            
            node = node->next;
        }
        
        return count;
    }
    
    int position(Node<T>* node, T value) {
        
        int pos = 0;
        
        while(node != NULL && node->data != value) {
            pos++;
            node = node->next;
        }
        
        return pos;
    }
    
    

};

#endif /* LinkedList_hpp */

/*/*
 
 Remove all duplicate elements from a sorted linked list
 Node is defined as
 struct Node
 {
 int data;
 struct Node *next;
 }
 
int frequency(Node* node, int num) {
    int count = 0;
    
    while(node != NULL) {
        
        if(num == node->data) {
            count++;
        }
        
        node = node->next;
    }
    
    return count;
}

int position(Node* node, int value) {
    
    int pos = 0;
    
    while(node != NULL && node->data != value) {
        pos++;
        node = node->next;
    }
    
    return pos;
}

void deleteNode(Node* head, int position) {
    
    Node* node = head;
    int curr = 0;
    
    while(node != NULL && curr < position - 1) {
        node = node->next;
        curr++;
    }
    
    Node* del = node->next;
    node->next = del->next;
    
    delete del;
}

Node* RemoveDuplicates(Node *head)
{
    // This is a "method-only" submission.
    // You only need to complete this method.
    
    Node* node = head;
    
    while(node != NULL) {
        int value = node->data;
        int thisFre = frequency(head, value);
        
        if(thisFre > 1) {
            int pos = position(head, value);
            deleteNode(head, pos);
            
        }
        
        node = node->next;
    }
    
    return head;
}
 
 
 Reverse a linked list and return pointer to the head
 The input list will have at least one element
 Node is defined as
 struct Node
 {
 int data;
 struct Node *next;
 }
 
Node* Reverse(Node *head)
{
    // Complete this method
    
    Node *node = head;
    Node *child = head;
    Node* gran = head;
    
    int count = 0;
    
    while(node != NULL) {
        node = node->next;
        count++;
    }
    
    int array[count];
    int array2[count];
    
    for(int i = 0; i < count; i++) {
        array[i] = child->data;
        child = child->next;
    }
    
    int j = 0;
    for(int i = count - 1; i >= 0; i--) {
        array2[j++] = array[i];
    }
    
    for(int i = 0; i < count; i++) {
        gran->data = array2[i];
        gran = gran->next;
    }
    
    return head;
    
}


 */
