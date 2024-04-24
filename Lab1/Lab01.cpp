//Lab01
//By: Vincent Fealy
//2/8/23
#include <iostream>
#include "deSelsort.h"
using namespace std;

//Main function initalizing array and prep to print array when sorted.
int main() {
  int arr[] ={13, 5, 2, 25, 47, 17, 8, 21};
  int size = sizeof(arr) / sizeof(arr[0]);
  deSelectionSort(arr, size);
  cout << "Here is the array after sort:" << endl;
  printArray(arr, size);
}