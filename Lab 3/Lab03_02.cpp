/*
By: Vincent Fealy
2/21/23
*/

#include <iostream>
#include "d_tnode1.h"
#include "max.h"

int main(){
  
  tnode<int> *root, *a, *b, *c, *d, *e;
  //Creating new nodes assigned to a through e
  a = new tnode<int>(1);
  b = new tnode<int>(8);
  c = new tnode<int>(15);
  d = new tnode<int>(30, a, (tnode<int> *)NULL);
  e = new tnode<int>(15, b, c);
  root = new tnode<int>(41, d, e);
  
  int max = maxValue(root);
  std::cout << "Max Value in Tree is: " << max << std::endl;
  //displays the tree at the root and position 6
  displayTree(root, 6);
}
