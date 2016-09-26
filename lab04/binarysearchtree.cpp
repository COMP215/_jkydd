//
//  binarysearchtree.cpp
//  demo
//
//  Created by Tom Armstrong on 9/19/16.
//  Copyright © 2016 tarmstro. All rights reserved.
//

#include "binarysearchtree.hpp"

#include <iostream>
using namespace std;

BSTNode::BSTNode(string data) {
    data_ = data;
    left_ = NULL;
    right_ = NULL;
}

BinarySearchTree::BinarySearchTree() {
    root_ = NULL;
}

bool BinarySearchTree::Insert(string data) {
    if (root_ == NULL) {
        // Empty tree, make a root
        root_ = new BSTNode(data);
        return true;
    } else {
        // Non-empty tree, find correct position for data
        BSTNode* curr = root_;
        while (curr != NULL) {
            if (data == curr->data_) {
                // Data already in tree, fail to insert
                return false;
            } else if (data < curr->data_) {
                // Lexicographically lesser, find location to the left
                if (curr->left_ == NULL) {
                    curr->left_ = new BSTNode(data);
                    return true;
                } else {
                    curr = curr->left_;
                }
            } else {
                // Lexicographically greater, find location to the right
                if (curr->right_ == NULL) {
                    curr->right_ = new BSTNode(data);
                    return true;
                } else {
                    curr = curr->right_;
                }
            }
        }
    }
    return false;
}
BinarySearchTree::Print()
{
    BSTNode* curr = root_;
    while(curr != NULL)
    {
        cout << curr->data_ << endl;
        curr = curr->left_;
    }
    curr = root_;
    while(curr != NULL)
    {
        cout << curr->data_ << endl;
        curr = curr->right_;
    }
    if(curr == NULL)
    {
        cout << "nothing in tree" << endl;
    }
}

bool BinarySearchTree::Search(string data)
{
    if (root_ == NULL) {
        cout << "nothing in tree";
        return false;
    } else {
        BSTNode* curr = root_;
        while (curr->data_ != data)
        {
            cout << "loop" << endl;
            if (data < curr->data_) {
                cout << "left" << endl;
                curr = curr->left_;
                if (curr == NULL){
                    cout << "entry not found" << endl;
                    return false;
                }
            } else {
                cout << "right" << endl;
                curr = curr->right_;
                if (curr == NULL){
                    cout << "entry not found" << endl;
                    return false;
                }
            }
        }
        cout << "found: " << curr->data_ << endl;
        return true;
        }
    }


void BinarySearchTree::InOrder()
{
    if (root_ != NULL)
    {
       InOrder(root_);
    }
}

void BinarySearchTree::InOrder(BSTNode* node)
{
    cout << node->data_ << endl;
    if (node->left_ != NULL)
    {
        InOrder(node->left_);
    }
    if (node->right_ != NULL)
    {
        InOrder(node->right_);
    }
}
