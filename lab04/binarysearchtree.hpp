//
//  binarysearchtree.hpp
//  demo
//
//  Created by Tom Armstrong on 9/19/16.
//  Copyright © 2016 tarmstro. All rights reserved.
//

#ifndef binarysearchtree_hpp
#define binarysearchtree_hpp

#include <stdio.h>
#include <string>
using namespace std;
class BSTNode {
public:
    string data_;
    BSTNode* left_;
    BSTNode* right_;

public:
   BSTNode(string);
};


class BinarySearchTree {
    BSTNode* root_;

public:
    BinarySearchTree();
    Print();
    void InOrder();
    void InOrder(BSTNode*);
    bool Insert(string);
    bool Search(string);
    bool Delete(string);
};

#endif /* binarysearchtree_hpp */
