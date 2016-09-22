#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
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

class LinkedList
{
    public:
        ListNode* buffer_ = new ListNode(NULL);
        ListNode* tail_ = buffer_;
        void Insert(string to_add);
        //void Insert(int where_to, string to_add);
        void print();
        bool Search(string data);
        bool Delete(string data);
};

#endif
