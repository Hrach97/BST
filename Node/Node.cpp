#include "Node.h"

Node::Node(int data = 0) :
    m_data(data),
    m_lChild(nullptr),
    m_rChild(nullptr) {}

void Node::setRchild(Node* rChild) {
   m_rChild = rChild;
}

void Node::setLchild(Node* lChild) {
   m_lChild = lChild;
}

Node* Node::getRchild() {
    return m_rChild;
}

Node* Node::getLchild() {
    return m_lChild;
}

int Node::getData() {
    return m_data;
}

void Node::setData(int data) {
    m_data = data;
}

Node::~Node() {
    
}