//
//  main.cpp
//  classbst
//
//  Created by Tom Armstrong on 9/19/16.
//  Copyright © 2016 tarmstro. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "binarysearchtree.hpp"
#include "LinkedList.h"

int main() {
    BinarySearchTree* people_names = new BinarySearchTree();
    people_names->Insert("gousie");
    people_names->Insert("patel");
    people_names->Insert("bloch");
    people_names->Insert("ratliff");
    people_names->Insert("leibowitz");
    people_names->Insert("gagne");
    people_names->Insert("armstrong");
    people_names->Insert("sklensky");
    people_names->Insert("leblanc");
    people_names->Insert("decoste");
    people_names->Insert("kahn");
    people_names->Search("decoste");
    people_names->InOrder();
    //people_names->Print();
    ifstream fin;
    string the_word;
    fin.open("foowords.txt");
    while (!fin.eof()){
        getline(fin,the_word);
        people_names->Insert(the_word);
    }
    //people_names->InOrder();
    return 0;
}
