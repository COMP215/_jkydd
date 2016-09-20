#include <iostream>
using namespace std;

class Node
{
public:
    string data_;
    Node* left_;
    Node* right_;
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
public:
    Node* root_;
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
    else if (data < root_->data_)
    {
        root_->left_;
        Insert(data);
        return true;
    }
    else
    {
        root_->right_;
        Insert(data);
        return true;
    }
    return false;
}

int Main()
{
    BinarySearchTree* people_names = new BinarySearchTree();
    people_names->Insert("gousie");
    people_names->Insert("kydd");
    people_names->Insert("armstrong");
}
