/*

Time Complexity (Best): O(n^2)
Time Complexity (Worst): O(n^2)

Space Complexity: O(1)

Selection sort is a sorting algorithm that selects the smallest element from an unsorted list 
In each iteration, it swaps that element with the element at the current index.

Eg : [4,5,1,2,3]

1st iteration : [1,5,4,2,3] -> 4 swapped by 1 or we can say that 1 is selected and placed at 0th index
2nd iteration : [1,2,4,5,3] -> 5 swapped by 2
3rd iteration : [1,2,3,5,4] -> 4 swapped by 3
4th iteration : [1,2,3,4,5] -> 5 swapped by 4

No of iterations = n-1

Use case : When memory is a constraint
           When No of elements are small
           When array is almost sorted or partially sorted

Note: It is an example of inplace sorting algorithm bcz here no extra memory is being used
Note: It is an Unstable sorting algorithm bcz it does not preserve the order of elements with equal keys

*/

#include <iostream>
using namespace std;
void selection_sort(int arr[], int n){
    int min_index;
    for (int i = 0; i < n - 1; i++){
        min_index = i;
        for (int j = i + 1; j < n; j++){
            if (arr[min_index] > arr[j]) min_index = j;
        }
        swap(arr[min_index], arr[i]);
    }
}

