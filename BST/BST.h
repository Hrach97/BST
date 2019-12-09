#ifndef Binary_Search_Tree
#define Binary_Search_Tree

#include "../Node/Node.h"
#include <iostream>

class BST {

public:    
    BST();
    void inOrder(Node* ptr);
    void preOrder(Node* ptr);
    void postOrder(Node* ptr);
    Node* insertI(int key);
    Node* insertR(int key);
    void remove(int key);
    Node* searchI(int key);
    Node* searchR(int key);
    Node* getRoot();
    ~BST();

private:
    Node* m_root;
    Node* insertRec(int key, Node* node);
    Node* removeRec(int key, Node* node);
    Node* searchRec(int key, Node* node);
    Node* inPre(Node* node);
    Node* inSucc(Node* node);
    unsigned int height(Node* node);
    void destructTree(Node* node);
};

#endif