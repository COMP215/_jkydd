#include <iostream>
#include <string>
#include <regex>
//#include "Tree.h"

using namespace std;
class Node
{
    public:
        int num;
        Node* left = NULL;
        Node* right = NULL;
        Node* root = NULL;
        Node();
        Node(int num);
        Node(int num, Node* left, Node* right);
};

Node::Node(int num)
{
    this->num = num;
}
Node::Node(int num, Node* left, Node* right)
{
    this->num = num;
    this->left = left;
    this->right = right;
}

class Tree
{
    public:
        Node* buffer_ = new Node(NULL);
        Node* tail_ = buffer_;
        void add(int to_add);
        //void add(int where_to, int to_add);
        void print();
};
void Tree::add(int to_add)
{
    if (tail_->left = NULL)
    {
        tail_->left = new Node(to_add);
        tail_ = tail_->left;
    }
    else
    {
        tail_->right = new Node(to_add);
        tail_ = tail_->right;
    }
}
void Tree::add(int where_to, int to_add)
{
    Node* foo = buffer_;
    for(int i = 0; i < where_to; i++)
    {
        foo = foo->next;
    }
    foo->num = to_add;
    if(tail_->next == foo)
    {
        tail_ = foo;
    }
}
void Tree::print()
{
    Node* foo = buffer_;
    while (foo->root != NULL)
    {
        cout << foo->num << endl;
        foo->root = foo->left;
    }
    while (foo->root != NULL)
    {
        cout << foo->num << endl;
        foo->root = foo->right;
    }
}

int main()
{
    Tree Foo;
    int user_in = 1;
    while(1)
    {
        cout << "Input an int, or don't to end this. ";
        cin >> user_in;
        if (cin.fail())
            break;
        Foo.add(user_in);
    }
    Foo.print();

}
