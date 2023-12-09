/*

Heapify : It is a process of converting a binary tree into a heap data structure.
          Time Complexity : O(n) [ since we are traversing the array and swapping only once 

Prioity Queue : It is a data structure in which elements are stored in order of their priority.
                It can be done using minheap or maxheap.
                Time Complexity : Insertion and Deletion : O(logn) , Priority  Update : O(n) , Access : O(1)
                Space Complexity : O(n) [ since we are using an array to store the elements ]

*/

/*
Sorting can be done by 2 ways : 
1) Heap Sort : O(nLogn)
2) Heapify : O(n)

*/

/*

Heap Sort :

Step 1) Build a maxheap from the input data.

15,20,7,9,30

      30
     /  \
    20   7
   / \
  9   15

  [30,20,7,9,15]

Step 2) The largest item in the heap is stored at the root. 
        Replace it with the last item (rightmost child) of the heap followed by reducing the size of heap by 1.
        check for heap property and heapify if violated.
        modify the array accordingly

    (i) 30 is the largest element , so swap it with 15

          15
         /  \
        20   7
       / 
      9   

    [15,20,7,9,30]

    (ii) Now the property is violated at root , so heapify it

          20
         /  \
        15   7
       / 
      9   

    [20,15,7,9,30]

    (iii) Now swap 20 with 9 

           9
         /  \
        15   7
       

    [9,15,7,20,30]

    (iv) Now the property is violated at root , so heapify it

           15
         /    \
        9      7
       

    [15,9,7,20,30]

    (v) Now swap 15 with 7 

            7
         /    
        9      
       

    [7,9,15,20,30]

    (vi) Now the property is violated at root , so heapify it

            9
         /    
        7      
       

    [9,7,15,20,30]

    (vii)  Now swap 9 with 7 

        7  

    [7,9,15,20,30] --> Sorted array 

*/

/*

Heapify 

      15
     /  \
    5   20
   / \  / \
  1 17 10 30


15 2 20 1 17 10 30

step 1 ) The leaf node itself is a min heap..so start looking for its upper elements and heapify it

   (i) 1,17,10,30 are leaf nodes so they are min heap
   (ii) heapify [20,10,30]

        15
       /  \
      5   30
     / \  / \
    1 17 10 20

    15 5 30 1 17 10 20

    (iii) heapify [5,1,17]

        15
       /  \
     17   30
     / \  / \
    1  5 10 20

    15 17 30 1 5 10 20

    (iv) heapify [15,17,30]

        30
       /  \
     17   15
     / \  / \
    1  5 10 20

    30 17 15 1 5 10 20

    (v) heapify [30,15,20]

        30
       /  \
     17   20
    / \  / \
   1  5 10 15

    [30 17 20 1 5 10 15]


    Time Complexity : O(n) [ since we are traversing the array and swapping only once]

Step 2 ) The largest item in the heap is stored at the root. 
        Replace it with the last item (rightmost child) of the heap followed by reducing the size of heap by 1.
        check for heap property and heapify if violated.
        modify the array accordingly

*/

#include <bits/stdc++.h>
using namespace std;
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left <= n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n) {
    for (int i = n / 2 -1; i >= 0; i--) heapify(arr, n, i); // Step 1) Build a maxheap from the input data.
    for (int i = n - 1; i > 0; i--) { // Step 2)  deletion
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
    cout << "Sorted array is \n";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    return 0;
}
