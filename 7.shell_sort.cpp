/*

Shell Sort is a special case of insertion sort where the no of swaps is reduced.
In Insertion sort , the gap is 1 i.e ith element is compared with i-1th element.
But in shelll sort , the gap can be n/2,n/4..... and so on.

Eg : for n=10 , gap is {5,2,1}. If gap=0, then break the loop

Time complexity : O(n^2) [depends on gap sequence]
Best case : O(nlogn)

*/

/*

Eg : [23 , 29 , 15 , 19 , 31 , 7 , 9 , 5 , 2]

gap1 = 9/2 = 4
gap2 = 5/2 = 2
gap3 = 3/2 = 1

gap = {4,2,1}

*/

/*

23 29 15 19 31 7 9 5 2

Step 1) Initialize 2 pointers i and j pointing at 0th and 4th(0+gap1) element respectively.
Step 2) Compare ith and jth element. If ith element is greater than jth element, swap them.
Step 3) Before moving the pointers , check if i>=gap1. 
Step 4) If yes, then swap the elements at i and i-gap1 position if ith element is smaller than (i-gap1)th element.
Step 5) Increment i and j by 1.
Step 6) Repeat step 2 to 5 till i<n and j<n.
Step 7) Now , change the gap1 to gap 2 and repeat step 1 to 6. until gap becomes 0

At last , we will get the sorted array

Note : the gaps can be anything , it can be n/2,n/3,n/4....

*/

/*

eg : [23 , 29 , 15 , 19 , 31 , 7 , 9 , 5 , 2]

Pass 1 : gap = 4

i=0 , j=4 : 23 29 15 19 31 7 9 5 2 (no swap as 23<31)
i=1 , j=5 : 23 7 15 19 31 29 9 5 2 (swap as 29>7) 
i=2 , j=6 : 23 7 9 19 31 29 15 5 2 (swap as 15>9)
i=3 , j=7 : 23 7 9 5 31 29 15 19 2 (swap as 19>5)
i=4 , j=8 : 23 7 9 5 2 29 15 19 31 (swap as 31>2)

Now here i>=gap1 , so we will swap 23 and 2 as 2<23

2 7 9 5 23 29 15 19 31

Pass 2 : gap = 2

i=0 , j=2 : 2 7 9 5 23 29 15 19 31 (no swap as 2<9)
i=1 , j=3 : 2 5 9 7 23 29 15 19 31 (swap as 7>5)
i=2 , j=4 : 2 5 9 7 23 29 15 19 31 (no swap as 9<23)

Note : here i>=gap2 , so we check if 9<2 , if yes then swap them

2 5 9 7 23 29 15 19 31

i=3 , j=5 : 2 5 9 7 23 29 15 19 31 (no swap as 7<29) and also check if 7<5 , if yes then swap them
i=4 , j=6 : 2 5 9 7 15 29 23 19 31 (swap as 23>15)
i=5 , j=7 : 2 5 9 7 15 19 23 29 31 (swap as 29>19)
i=6 , j=8 : 2 5 9 7 15 19 23 29 31 (no swap as 23<31)

2 5 9 7 15 19 23 29 31

Pass 3 : gap = 1

i=0 , j=1 : 2 5 9 7 15 19 23 29 31 (no swap as 2<5)
i=1 , j=2 : 2 5 9 7 15 19 23 29 31 (no swap as 5<9)
i=2 , j=3 : 2 5 7 9 15 19 23 29 31 (swap as 9>7)
i=3 , j=4 : 2 5 7 9 15 19 23 29 31 (no swap as 9<15)
i=4 , j=5 : 2 5 7 9 15 19 23 29 31 (no swap as 15<19)
i=5 , j=6 : 2 5 7 9 15 19 23 29 31 (no swap as 19<23)
i=6 , j=7 : 2 5 7 9 15 19 23 29 31 (no swap as 23<29)
i=7 , j=8 : 2 5 7 9 15 19 23 29 31 (no swap as 29<31)

2 5 7 9 15 19 23 29 31 --> Sorted array


*/

// #include <iostream>
// using namespace std;
// void shellSort(int arr[], int n) {
//     for (int gap = n / 2; gap > 0; gap /= 2) {
//         for (int i = gap; i < n; i++) {
//             int temp = arr[i];
//             int j;
//             for (j = i; (j >= gap) && (arr[j - gap] > temp); j -= gap) arr[j] = arr[j - gap];
//             arr[j] = temp;
//         }
//     }
// }
// int main() {
//     const int size = 9;
//     int arr[size] = {12, 34, 54, 2, 3, 300 , 43 , 1 , 23};
//     cout << "Original array: ";
//     for (int i = 0; i < size; i++) {
//         cout << arr[i] << " ";
//     }
//     shellSort(arr, size);
//     cout << "\nSorted array: ";
//     for (int i = 0; i < size; i++) {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
void shellsort(vector <int> &v,int n){
    int gap=n/2;
    while(gap>0){
        int i=0;
        int j=gap;
        while(j<n){
            if(v[i]>=v[j]) swap(v[i],v[j]);
            if((i>=gap) && (v[i]<v[i-gap])){
                swap(v[i],v[i-gap]);
            }
            i++;
            j++;
        }
        gap=gap/2;
    }
}
int main(){
    int n=18;
    vector <int> v={23 , 29 , 15 , 19 , 31 , 7 , 9 , 5 , 2 , 12 , 34 , 54 , 2, 3, 300 , 43 , 1 , 23};
    shellsort(v,n);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}