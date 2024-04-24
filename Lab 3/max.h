#ifndef MAX
#define MAX
#include "d_tnode.h"

template <typename T>

int maxValue(tnode<T> *t)
{
   
  int maxVal = 0;
  if(t != NULL)
  {
    
    maxVal = t->nodeValue;
    //search left and right
    int leftVal = maxValue(t->left);
    int rightVal = maxValue(t->right);
    //if the next search is on the next and greater than the right then replace.
    if(leftVal > maxVal)
    {
      maxVal = leftVal;
    }
    //if the right node value is greater then replace with max value.
    if(rightVal > maxVal)
    {
      maxVal = rightVal;
    }
  }
  
  return maxVal;
};
#endif