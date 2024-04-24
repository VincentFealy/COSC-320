using namespace std;
#include <iostream>

void deSelsort(int *arr, int n)
{
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        //the minimum and the maximum are the start of the array.
        int min = arr[i], max = arr[i];
        //index is first element of array
        int min_idx = i, max_idx = i;
        // k begins searching from front
        // j begins searching from the back
        for (int k = i; k <= j; k++){
            
            if (arr[k] > max){
                max = arr[k];
                max_idx = k;
            }
            // if the index k in the array is less than the current min then we swap.
            else if (arr[k] < min){
                min = arr[k];
                min_idx = k;
            }
        }
        // once it finds the new minimum number it swaps it to the front of the away.
        swap(arr[i], arr[min_idx]);

        if (arr[min_idx] == max)
            swap(arr[j], arr[min_idx]);
        else
            swap(arr[j], arr[max_idx]);
    }
}