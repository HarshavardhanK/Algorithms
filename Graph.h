//
//  Graph.cpp
//  Algorithms
//
//  Created by Harshavardhan K K on 17/09/17.
//  Copyright © 2017 Harshavardhan K. All rights reserved.
//

#include "LinkedList.hpp"
#include <queue>

class GraphNode {
    
    LinkedList<int> adjacencyList;
    int nodeKey;
    
public:
    
    GraphNode(int key) {
        nodeKey = key;
    }
    
    GraphNode() {}
    
    void setNodeKey(int key) {
        this->nodeKey = key;
    }
    
    int getNodeKey() {
        return nodeKey;
    }
    
    bool nodeExists(int node) {
        
        return adjacencyList.search(node);
    }
    
    friend ostream & operator << (ostream &out, const GraphNode &n);
    bool operator ==(GraphNode &node2);
    
};

ostream & operator << (ostream &out, const GraphNode &n) {
    out << n.nodeKey;
    return out;
}

bool GraphNode::operator ==(GraphNode &node2) {
    
    if(this->getNodeKey() == node2.getNodeKey())
        return true;
    
    return false;
}


class Graph {
    
   // static int n_graphs;
    
    LinkedList<GraphNode> *vertices;
    LinkedList<GraphNode> list;
    int g_size;
    
    bool nodeExists(int node);
    void depth_first_search_visit();
    
    
public:
    
    Graph(const int size) {
        vertices = new LinkedList<GraphNode>[size];
        g_size = 0;
    }
    
    void addEdge(int source, int destination);
    int search(GraphNode node);
    void bread_first_search(int destination);
    void depth_first_search();
    
    void print();
  
    //static int getNumberOfGraphs();
};

//int Graph::getNumberOfGraphs() {
//    return n_graphs;
//}

void Graph::bread_first_search(int destination) {
    
    bool *visited = new bool[g_size];
    
    for(int i = 0; i < g_size; i++)
        visited[i] = false;
    
    std::queue<GraphNode> queue;
    visited[destination] = true;
    
    queue.push(GraphNode(destination));
    
    while(!queue.empty()) {
        
        GraphNode des = queue.front();
        cout << "u: " << des << " ";
        queue.pop();
    }
    
}



void Graph::print() {
    
    for(int i = 0; i < g_size; i++) {
        
        vertices[i].printList();
        std::cout << std::endl;
        
    }
}

void Graph::addEdge(int source, int destination) {
    
    // check if there already exist an edge between source and destination nodes
    
    // GraphNode node(source);
    // first search for source, but now assume it exists #Update 2: Searching method added
    int index = search(GraphNode(source));
    
    if(index == -1 && !GraphNode(source).nodeExists(destination)) {
        
        vertices[g_size].append(GraphNode(source)); // root of the adjacency list is the vertices, the children nodes are the edges
        vertices[g_size++].append(GraphNode(destination));

    } else {
        vertices[index].append(GraphNode(destination));
    }
}

int Graph::search(GraphNode node) {
    
    int index = -1;
    
    for(int i = 0; i < g_size; i++) {
        
        if(vertices[i].search(node)) {
            index = i;
            break;
        }
    }
    
    return index;
}




