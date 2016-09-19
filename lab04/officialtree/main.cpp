#include <iostream>
using namespace std;

class Node
{
    string data_;
    Node* left_;
    Node* right_;
public:
    Node(string);
};

Node::Node(string data)
{
    data_ = data;
    left_ = NULL;
    right_ = NULL;
}

class BinarySearchTree
{
    Node* root_;
public:
    BinarySearchTree();
    bool Insert(string data);
    void InOrder();
};

BinarySearchTree::BinarySearchTree()
{
    root_ = NULL;
}

bool BinarySearchTree::Insert(string data)
{
    if (root_ == NULL)
    {
        root_ = new Node(data);
        return true;
    }
    return false;
}

int Main()
{
    BinarySearchTree* people_names = new BinarySearchTree();
    people_names->Insert("gousie");
    people_names->Insert("armstrong");
}
