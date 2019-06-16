

#ifndef TRIE_HPP
#define TRIE_HPP

#include <iostream>

using namespace std;

#define ALPHABET_SIZE 26

class TrieNode {
    
    TrieNode* *children;
    bool is_end_of_word;
    
public:
    
    TrieNode() {
        
        children = new TrieNode*[ALPHABET_SIZE]; //correct way to initializw 2D array..
        
        for(int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = nullptr;
        
        is_end_of_word = false;
    }
    
    void set_is_end_of_word(const bool is_end_of_word) {
        this->is_end_of_word = is_end_of_word;
    }
    
    bool get_is_end_of_word() {
        return is_end_of_word;
    }
    
    bool is_leaf() {
        return is_end_of_word != false;
    }
    
    void set_child(int i, TrieNode* node) {
        children[i] = node;
    }
    
    TrieNode* get_child(int index) {return children[index];}
    
};

class Trie {
    
private:
    
    TrieNode* root;
    
public:
    
    Trie() {
        root = new TrieNode;
    }
    
    //HELPER PROPERTIES
    char display[20];
    
    //HELPER FUNCTIONS
    void display_helper(TrieNode*, char[], int);
    
    
public:
    
    void insert_word(const string);
    void print_trie() {
        display_helper(this->get_root(), display, 0);
    }
    bool search(string);
    
    //MARK:- TRIE GETTERS
    
    TrieNode* get_root() {
        return root;
    }
    
};

void Trie::insert_word(const string word) {
    
    size_t length = word.length();
    
    TrieNode* auxiliary = get_root();
    
    for(size_t i = 0; i < length; i++) {
        
        int index = word[i] - 'a';
        
        if(auxiliary->get_child(int(index)) == nullptr) {
            auxiliary->set_child((int)index, new TrieNode);
        }
        
        auxiliary = auxiliary->get_child(index);
    }
    
    auxiliary->set_is_end_of_word(true);
    
    cout << "Successfully inserted " << word << endl;
}

void Trie::display_helper(TrieNode* node, char word[20], int level) {
    
    if(node->is_leaf()) {
        word[level] = '\0';
        cout << word << endl;
    }
    
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        
        if(node->get_child(i)) {
            word[level] = i + 'a';
            display_helper(node->get_child(i), word, level + 1);
        }
        
    } // END FOR LOOP
    
}

bool Trie::search(string key) {
    
    TrieNode* traverse = this->get_root();
    
    size_t length = key.length();
    
    for(int i = 0; i < length; i++) {
        
        int index = key[i] - 'a';
        
        if(traverse->get_child(index) == nullptr) {
            return false;
        }
        
        traverse = traverse->get_child(index);
    }
    
    return (traverse != nullptr && traverse->get_is_end_of_word());
    
    
}

//MARK:- Test trie functions
void test_trie() {
    string words[] = {"hello", "abu", "abba", "hello", "dead", "dear"};
    
    Trie trie;
    
    for(auto word: words) {
        trie.insert_word(word);
    }
    
    string word = "abu";
    
    if(trie.search(word)) {
        cout << word << " found\n";
    } else {
        cout << word << " not found\n";
    }
    
    trie.print_trie();
}

#endif
