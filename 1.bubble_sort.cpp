/*

Time Complexity (Best): O(n) [when array is sorted]
Time Complexity (Worst): O(n^2)

Space Complexity: O(1)

Bubble sort is a sorting algorithm that compares two adjacent elements and swaps them if they are not in the intended order.
After ith iteration, the largest i element will be at rightmost position.

Eg : [10,1,7,6,14,9]

Round 1 : 

[1,10,7,6,14,9] -> 10 swapped by 1
[1,7,10,6,14,9] -> 10 swapped by 7
[1,7,6,10,14,9] -> 10 swapped by 6
[1,7,6,10,14,9] -> no change
[1,7,6,10,9,14] -> 14 swapped by 9

After 1st round, largest element (14) is at rightmost position

Round 2 : 

[1,7,6,10,9,14] -> 7 swapped by 1
[1,6,7,10,9,14] -> 7 swapped by 6
[1,6,7,10,9,14] -> no change
[1,6,7,9,10,14] -> 10 swapped by 9

After 2nd round, 2nd largest element (10) is at 2nd rightmost position

Round 3 : 

[1,6,7,9,10,14]
[1,6,7,9,10,14] 
[1,6,7,9,10,14] 

After 3rd round, 3rd largest element (9) is at 3rd rightmost position

Round 4 : 

[1,6,7,9,10,14] 
[1,6,7,9,10,14] 

After 4th round, 4th largest element (7) is at 4th rightmost position

Round 5 : 

[1,6,7,9,10,14] 

After 5th round, 5th largest element (6) is at 5th rightmost position

Total no of rounds = n-1

use case : When memory is a constraint
           When No of elements are small
           When array is almost sorted or partially sorted

NOTE: It is an example of inplace sorting algorithm bcz here no extra memory is being used
NOTE : It is a Stable sorting algorithm bcz it preserves the order of elements with equal keys


*/

#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int n,int arr[]){
    bool swapped;
    for(int i=0;i<n;i++){
        swapped=false;
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(swapped==false) break;
    }
}