//
//  Huffman.cpp
//  Algorithms
//
//  Created by Harshavardhan K K on 08/03/18.
//  Copyright © 2018 Harshavardhan K. All rights reserved.
//

#include <iostream>
#include <map>
#include <utility>
#include <queue>
using namespace std;

#define MAX_HEIGHT = 256

map<char, string> codes;
map<char, int> freq;

//MARK: MinHeapNode
struct MinHeapNode {
    
    int fregquency;
    char data;
    
    MinHeapNode* right;
    MinHeapNode* left;
    
    MinHeapNode(char data, int freq) {
        
        this->data = data;
        fregquency = freq;
        
        right = left = nullptr;
    }
};

//MARK: compareFrewuency: helper method to compare two frequencies
struct compareFrequency {
    
    bool operator () (MinHeapNode* nodeOne, MinHeapNode* nodeTwo) {
        return nodeOne->fregquency > nodeTwo->fregquency;
    }
};

//MARK: printCodes:
void printCodes(MinHeapNode* root, string str) {
    
    if(!root)
        return;
    
    if(root->data != '$')
        cout << root->data << ":" << str + "\n";
    
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

//MARK: storeCodes: function to store characters along with their Huffman vaues in a hash table
void storeCodes(MinHeapNode* root, string str) {
    
    if(root == NULL)
        return;
    
    if(root->data != '$')
        codes[root->data] = str;
    
    storeCodes(root->right, str + "1");
    storeCodes(root->left, str + "0");
}
//MARK: priority_queue
priority_queue<MinHeapNode*, vector<MinHeapNode*>, compareFrequency> minHeap;

//MARK: huffman_codes: function to build a Huffman tree and store it
void huffman_codes() {
    
    MinHeapNode* left, *right, *top;
    
    for(map<char, int>::iterator v = freq.begin(); v != freq.end(); v++)
        minHeap.push(new MinHeapNode(v->first, v->second));
    
    while(minHeap.size() != 1) {
        
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        
        top = new MinHeapNode('$', left->fregquency + right->fregquency);
        top->right = right;
        top->left = left;
        
        minHeap.push(top);
        
    }
    
    storeCodes(minHeap.top(), "");
}

//MARK: calculate_frequency: Calculates the frequency of each character in the string
void calculuate_frequency(string str) {
    
    for(int i = 0; i < str.size(); i++)
        freq[str[i]]++;
}

// PRAGMA MARK: Decode encoded Huffman string
//MARK: decode_string: if s == 1, moves right, if s == 0, moves left
string decode_string(MinHeapNode* root, string str) {
    
    string final_string = "";
    MinHeapNode* child = root;
    
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '0')
            child = child->left;
        else
            child = child->right;
        
        if(child->right == NULL && child->left == NULL) {
            final_string += child->data;
            child = root;
        }
    }
    
    return final_string + '\0';
}

int main() {
    
    string word = "geeksforgeeks";
    string encoded_string, decoded_string;
    
    calculuate_frequency(word);
    huffman_codes();
    
    cout << "Characters with their frequencies are: ";
    
    for(auto v = codes.begin(); v != codes.end(); v++) {
        cout << v->first << ' ' << v->second << endl;
    }
    
    for(auto i: word)
        encoded_string += codes[i];
    
    cout << "Encoded Huffman data is: " << encoded_string << endl;
    
    decoded_string = decode_string(minHeap.top(), encoded_string);
    cout << "Decoded Huffman is: " << decoded_string << endl;
    
    return 0;
}


class HuffmanCompression {
    
    map<char, string> codes;
    map<char, int> freq;
};
