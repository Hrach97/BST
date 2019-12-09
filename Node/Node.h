#ifndef NODE
#define NODE


class Node {
public:
    Node(int);
    Node* getLchild();
    Node* getRchild();
    void setLchild(Node *);
    void setRchild(Node *);
    int getData();
    void setData(int);
    ~Node();

private:
    Node* m_lChild;
    Node* m_rChild;
    int m_data;

};
#endif // NODE
