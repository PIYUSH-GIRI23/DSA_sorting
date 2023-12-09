/*

Time Complexity (Worst): O(n^2)
Time Complexity (Best): O(n)

Space Complexity: O(1)

Insertion sort involves comparing the element from right to left (i.e from index i to 0) and place it at the suitable position

Eg : [ 10,1,7,4,8,2,11]

1st iteration : 10 is at correct position

2nd iteration : 1 is at wrong position, so we compare it with 10 .
                Since 10>1 , thus we shift 10 to left and place 1 at 0th position

[1,10,7,4,8,2,11]

3rd iteration : 7 is at wrong position, so we compare it with 10 .
                Since 10>7 , thus we shift 10 to left 
                Now we compare 7 with 1 . since 7>1 , thus 7 will lie between 1 and 10
                and place 7 at 1st position

[1,7,10,4,8,2,11]

4th iteration : 4 is at wrong position, so we compare it with 10 .
                Since 10>4 , thus we shift 10 to left 
                Now we compare 4 with 7 . since 7>4 , thus we shift 7 to left 
                Now we compare 4 with 1 . since 1<4 , thus 4 will lie between 1 and 7
                and place 4 at 1st position

[1,4,7,10,8,2,11]

5th iteration : 8 is at wrong position, so we compare it with 10 .
                Since 10>8 , thus we shift 10 to left 
                Now we compare 8 with 7 . since 7<8 , thus 8 will lie between 7 and 10
                and place 8 at 2nd position

[1,4,7,8,10,2,11]

6th iteration : 2 is at wrong position, so we compare it with 10 .
                Since 10>2 , thus we shift 10 to left 
                Now we compare 2 with 8 . since 8>2 , thus we shift 8 to left 
                Now we compare 2 with 7 . since 7>2 , thus we shift 7 to left 
                Now we compare 2 with 4 . since 4>2 , thus we shift 4 to left 
                Now we compare 2 with 1 . since 1<2 , thus 2 will lie between 1 and 4
                and place 2 at 1st position

[1,2,4,7,8,10,11]

7th iteration : 11 is at correct position

Use case : When memory is a constraint
           When No of elements are small
           When array is almost sorted or partially sorted

NOTE: It is an example of inplace sorting algorithm bcz here no extra memory is being used
NOTE : It is a Stable sorting algorithm bcz it preserves the order of elements with equal keys


*/

#include <bits/stdc++.h>
using namespace std;
void InsertionSort(int n,int arr[]){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        if(j==i-1) break;
    }
}