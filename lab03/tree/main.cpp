#include <iostream>

using namespace std;
class Node
{
    public:
        int num;
        Node* left = NULL;
        Node* right = NULL;
        Node* root = NULL;
        Node(int data);
        Node(Node* left, Node* right);
        Node(int num, Node* left, Node* right);
};
Node::Node(int data)
{
    num = data;
    this->left = left;
    this->right = right;
}
Node::Node(Node* left, Node* right)
{
    this->left = left;
    this->right = right;
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
        int hmr_data_ = 0;
        int* data_ = new int[hmr_data_];
        Node* buffer_ = new Node(NULL);
        Tree(int* passed_data);
        void Print(Node* printing_node);
        Node* Print_This();
        int num = 0;
};
Tree::Tree(int* passed_data)
{
    buffer_ = new Node;

}
void Tree::Print(Node* printing_node)
{
    if(printing_node->root == NULL)
    {
        cout << "end" << endl;
        return;
    }
    Print(printing_node->left);
    cout << printing_node->num;
    Print(printing_node->right);
}
Node* Tree::Print_This()
{
    return buffer_->root;
}

int main()
{
    int foo[8] = {17,34,9,16,10,1,74,20};
    //int foo = 3;
    Tree bar(foo);
    bar.Print(bar.Print_This());
}
