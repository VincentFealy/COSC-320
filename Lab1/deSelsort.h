#include <iostream>
using namespace std;

// swap function with a and b variables
void swap(int *a, int *b) 
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Void function put in place here to print this array.
void printArray(int array[], int size) 
{
  for (int i = 0; i < size; i++) 
  {
    cout << array[i] << " ";
  }
  cout << endl;
}

//Nested for loop as well as if statement used that sorts from desending order.
//in each loops it selects he min element within each loop
void deSelectionSort(int array[], int size) 
{
  for (int step = 0; step < size - 1; step++) 
  {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) 
    {

      if (array[i] < array[min_idx])
        min_idx = i;
    }

    swap(&array[min_idx], &array[step]);
  }
}