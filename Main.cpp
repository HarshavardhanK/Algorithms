//
//  anotherMain.cpp
//  Algorithms
//
//  Created by Harshavardhan K K on 22/07/16.
//  Copyright © 2016 Harshavardhan K. All rights reserved.
//

#include "GeneralObjects.hpp"
#include "BinarySearchTree.hpp"
#include "LinkedList.hpp"
#include "BinarySTree.hpp"
#include "Sorting.hpp"
#include "Algorithm.h"
#include "Generics.h"
#include <vector>
#include "Graph.h"
#include <math.h>
#include "Prime.hpp"
#include "Dynamic.hpp"
#include "Autocorrect.h"
#include <sstream>


//#include "2DGrid.h"


using namespace std;
using namespace Algorithms;

void bst() {
    
    BST<int, Performance> searchTree;
    
    Student harsha("Harsha", 13, 71);
    Student suraj("Suraj", 28, 91);
    Student rama("Ramathmika", 24, 23);
    Student mana("Manasa", 26, 82);
    
    harsha.setPerformance("Good");
    mana.setPerformance("Good!");
    rama.setPerformance("Bitch");
    suraj.setPerformance("Awesome!");
    
    searchTree.insert(harsha.getRollNo(), harsha.getPerformance());
    searchTree.insert(rama.getRollNo(), rama.getPerformance());
    searchTree.insert(mana.getRollNo(), mana.getPerformance());
    searchTree.insert(suraj.getRollNo(), suraj.getPerformance());
    
    searchTree.print_helper();


}

//void rodCuttingProblem() {
//    
//    int prices[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
//    
//  //  cout << "Enter prices of rod of size 1 to 10: ";
//    
//    RodCutting rod(prices, 5);
//    
//    rod.cutRod();
//    
//}

void searchAndSort() {
    
    string array[10];
    
    for (int i = 0; i < 4; i++) {
        cout << "Enter string: ";
        cin >> array[i];
    }
    
    displayArray(array, 4);
    
    cout << "\nString to search: ";
    string key;
    cin >> key;
    
    Sorts<string> string_search;
    cout << string_search.searchKey(array, key, 4) << endl;
    
    Sorts<double> dob_search;
    double dob_array[100];
    
    for (int i = 0; i < 100; i++) {
        dob_array[i] = arc4random() % 103;
    }
    
    displayArray(dob_array, 100);
    double dob_key;
    cout << "Enter key: "; cin >> dob_key;
    cout << dob_search.searchKey(dob_array, dob_key, 100) << endl;

}

void sorts() {
    
    int A[5000];
    
    for(int i = 0; i < 5000; i++)
        A[i] = int(pow(-1, i) * rand()) % 100;
    
    displayArray(A, 5000);
    
    Sorts<int> sort = Sorts<int>();
    cout << "Sorted!\n\n";
    sort.cocktailShakerSort(A, 5000);
    
    displayArray(A, 5000);
}

void linkedListDemo() {
    
    LinkedList<string> *list = new LinkedList<string>;
    string data;
    
    for (int i = 0; i < 10; i++) {
        cout << "Enter string: ";
        cin >> data;
        
        list->append(data);
    }
    
    list->insert("fuck", 1);
    string ll = "fuck";
    list->printList();
    list->deleteNode(3);
    list->printList();
    
//    LinkedList* anotherList = new LinkedList(0);
//    anotherList->append(-1);
    
}

void binaryTreeDemo() {
    
   // cout << "Fuck this";
    
    BinaryTree<int> *binaryTree = new BinaryTree<int>(3);
    
    for (int i = 1; i < 20; i++) {
        binaryTree->insert(i * 3);
    }
    
    binaryTree->print_helper();
    
    binaryTree->search(0);
    
   /* if(binaryTree->iter_search(3)) {
        cout << "Found!\n";
        
    } else {
        cout << "Not found!\n";
    } */
    
   // binaryTree->tree_delete(100);

}

void activitySelector() {
    
    cout << "Enter activities: \n";
    int start[5], finish[5];
    
    for(int i = 0; i < 5; i++) {
        cout << "Enter start time: "; cin >> start[i];
        cout << "Enter finish time: "; cin >> finish[i];
    }
    
    activitySelection(start, finish, 5);
    
}

void graphDemo() {
    
    Graph graph(5);
    
    for(int i = 0; i < 5; i++) {
        graph.addEdge(i, i + 12);
    }
    
    graph.addEdge(1, 12);
    graph.addEdge(4, 15);
    graph.addEdge(4, 16);
    
    graph.print();
    
}

void primes() {
    
    Primes prime = Primes();
    prime.getNumber(500);
    
  //  prime.print_all_primes();
    
}

void editDistance() {
    char str1[20], str2[20];
    
    cout << "E1: "; cin >> str1;
    cout << "E2: "; cin >> str2;
    
    cout << "Minimum operations = " << edit_distance(str1, str2, strlen(str1), strlen(str2)) << endl;
}

void autocorrect() {
    string str;
    
    cout << "Enter word (mispelled): "; //cin >> str;
    getline(cin, str);
    
  //  string w = naive_autocorrect(str);
    
  //  cout << w << endl;
    
    Autocorrect cor_tree;
    cor_tree.suggest_correct(str);
   // cor_tree.fill_tree();

}

int main() {
    
    autocorrect();
    
 //   string input;
  //  cout << "Enter: ";
  //  getline(cin, input);
   // input += h;
    
   /* istringstream iss(input);
    
    vector<string> words;
    words = {istream_iterator<string>{iss},
        istream_iterator<string>{}};
    
    vector<string> :: iterator i;
    
    for(int i = 0; i < words.size(); i++)
        cout << words[i] << endl;
    
   // cout << words[1]; */
    
    
   // cout << input;
   /* getline(cin, input);
    cout << input; */
    
    return 0;
}


