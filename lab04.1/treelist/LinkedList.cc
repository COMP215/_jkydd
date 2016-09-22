#include <iostream>
#include <string>
#include <regex>

using namespace std;
class ListNode
{
    public:
        string data_;
        ListNode* next_ = NULL;
        ListNode();
        ListNode(string data);
        ListNode(string data, ListNode* next);
};

ListNode::ListNode(string data)
{
    data_ = data;
}
ListNode::ListNode(string data, ListNode* next)
{
    data_ = data;
    next_ = next;
}

class LinkedList
{
    public:
        ListNode* buffer_ = new ListNode(NULL);
        ListNode* tail_ = buffer_;
        void print();
        void Insert(string to_add);
        bool Search(string);
        bool Delete(string);
};

void LinkedList::Insert(string to_add)
{
    tail_->next_ = new ListNode(to_add);
    tail_ = tail_->next_;
}

void LinkedList::print()
{
    ListNode* printing_node = buffer_->next_;
    cout << "There were ";
    while(printing_node->next_ != tail_)
    {
        cout << printing_node->data_ << ", ";
        printing_node = printing_node->next_;
    }
    cout << "and " << printing_node->data_ << " in the list." << endl;
}

bool LinkedList::Search(string data)
{
    ListNode* sorting_node = buffer_;
    while(sorting_node != tail_)
    {
        if (sorting_node->data_ == data)
            return true;
    }
    return false;
}

bool LinkedList::Delete(string data)
{
    ListNode* sorting_node = buffer_;
    if(Search(data))
    {
        while(sorting_node != tail_)
        {
            if (sorting_node->next_->data_ == data)
            {
                ListNode* to_die = sorting_node->next_;
                sorting_node->next_ = sorting_node->next_->next_;
                delete to_die;
                return true;
            }
        }
    }
    return false;
}
