
//By: Vincent Fealy
//3/7/23

#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <utility>
#include "d_stree.h"
#include "int.h"
#include "d_except.h"

//main lab 
int main(){
    
    srand(time(0));
    stree<integer> int_Tree;
//for loop for 10,000 random ints for binary tree
    for(int i = 0; i < 10000; i++)
    { 
        int rndNum = rand() % 7;

        stnode<integer> *searchN = int_Tree.findNode(rndNum);
        //search function if its null
        if(searchN == NULL)
        {
            int_Tree.insert(rndNum);
        }
        else
        {
            searchN->nodeValue.incCount();
        }
    }

        stnode<integer> *temp;
        std::cout << "Run:" << std::endl;
//storing the correct values in the tree
    std::cout << "Values within the tree: " << std::endl;
    for(int i = 0; i < 7; i++){
        temp = int_Tree.findNode(i);
        std::cout << temp->nodeValue << std::endl;
    }
    std::cout << std::endl;
// te print for the tree
    std::cout << "Tree:" << std::endl;
    int_Tree.displayTree(4);
}