#include "BST.h"

BST::BST() : m_root(nullptr) {}

Node* BST::getRoot() {
    return m_root;
}

Node* BST::insertI(int key) {
    if(m_root == nullptr) {
        m_root = new Node(key);
        return m_root;
    }

    Node* tmp = m_root;
    Node* prev = nullptr;
    while(tmp != nullptr) {
        prev = tmp;
        if(key < tmp->getData()) {
            tmp = tmp->getLchild();
        }
        else if(key > tmp->getData()) {
            tmp = tmp->getRchild();
        }
        else {
            return prev;
        }
    }

    tmp = new Node(key);
    if(key < prev->getData()) {
        prev->setLchild(tmp);
    }
    else {
        prev->setRchild(tmp);
    }
    return tmp;
}

Node* BST::insertR(int key) {
    if(m_root == nullptr) {
        m_root = new Node(key);
        return m_root;
    }
    return insertRec(key, m_root);
}

Node* BST::insertRec(int key, Node* node) {
    if(node == nullptr) {
        return new Node(key);
    }
    if(key < node->getData()) {
        node->setLchild(insertRec(key, node->getLchild())); 
    }
    else if(key > node->getData()) {
        node->setRchild(insertRec(key, node->getRchild())); 
    }
    return node;
}

unsigned int BST::height(Node* tmp) {
    unsigned int x,y;
    if(tmp == nullptr) {
        return 0;
    }
    x = height(tmp->getLchild());
    y = height(tmp->getRchild());
    return x > y ? x + 1 : y + 1;
}

Node* BST::inPre(Node *tmp) {
    while(tmp != nullptr && tmp->getRchild() != nullptr) {
        tmp = tmp->getRchild();
    }
    return tmp;
}

Node* BST::inSucc(Node* tmp) {
    while(tmp != nullptr && tmp->getLchild() != nullptr) {
        tmp = tmp->getLchild();
    }
    return tmp;
}

void BST::remove(int key) {
    removeRec(key, nullptr);
} 

Node* BST::removeRec(int key, Node* node) {
    
    node = searchRec(key, node);

    if(node == nullptr) {
        return node;
    }
    if(node->getLchild() == nullptr && node->getRchild() == nullptr) {
        std::cout << 1;
        if(node == m_root) {
            m_root = nullptr;
        }
        delete node;
        return nullptr;
    }
    auto a = node->getLchild()->getData();
    auto b = node->getRchild()->getData();

    std::cout << node->getData();
    Node* tmp = nullptr;
    if(height(node->getLchild()) > height(node->getRchild())) {
        tmp = inPre(node->getLchild());
        node->setData(tmp->getData());
        node->setLchild(removeRec(tmp->getData(), node->getLchild()));
    }
    else {
        tmp = inSucc(node->getRchild());
        node->setData(tmp->getData());
        node->setRchild(removeRec(tmp->getData(), node->getRchild()));
    }
    return node;
}

Node* BST::searchI(int key) {
    if(m_root == nullptr) {
        return m_root;
    }
    Node* tmp = m_root;
    while(tmp != nullptr) {
        if(key == tmp->getData()) {
            return tmp;
        }
        else if(key < tmp->getData()) {
            tmp = tmp->getLchild();
        }
        else {
            tmp = tmp->getRchild();
        }
    }
    return nullptr;
}

Node* BST::searchR(int key) {
    return searchRec(key, m_root);    
}

Node* BST::searchRec(int key, Node* node) {
    if(node == nullptr) {
        return node;
    }

    if(key < node->getData()) {
        node->setLchild(searchRec(key, node->getLchild())); 
    }
    else if(key > node->getData()) {
        node->setRchild(searchRec(key, node->getRchild())); 
    }
    return node;
}

void BST::inOrder(Node* node) {
    if(node != nullptr) {
        inOrder(node->getLchild());
        std::cout << node->getData() <<  " ";
        inOrder(node->getRchild());
    }
}

void BST::preOrder(Node* node) {
    if(node != nullptr) {
        std::cout << node->getData() <<  " ";
        preOrder(node->getLchild());
        preOrder(node->getRchild());
    }
}

void BST::postOrder(Node* node) {
    if(node != nullptr) {
        postOrder(node->getLchild());
        postOrder(node->getRchild());
        std::cout << node->getData() <<  " ";
    }
}

void BST::destructTree(Node* node) {
    if(node != nullptr) {
        destructTree(node->getLchild());
        destructTree(node->getRchild());
        std::cout << 1 << std::endl;
        delete node;
        std::cout << node->getData();
    }
}

BST::~BST() {
    destructTree(m_root);
}