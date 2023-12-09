/*

Time Complexity (Best): O(nlogn)
Time Complexity (Average): O(nlogn)
Time Complexity (Worst): O(n^2)

Space Complexity: O(1)

Quick sort involves selecting an element such that all the elements to the left of that element are smaller and all the elements to the right of that element are greater than it.

NOTE: It is preferred over merge sort bcz of less memory usage
NOTE: It is not a Stable sorting algorithm bcz it does not preserve the order of elements with equal keys\
NOTE: It is an inplace sorting algorithm bcz here no extra memory is being usedx

ALgo : 

    1) Choose a pivot
    2) count all element lesser than pivot
    3) update pivot -> start+count


Eg : [4,5,3,1,2]

1st recursive call:

    pivot : 4 
    NO of elements lesser than 4 -> {3,1,2} -> 3
    update pivot -> 0+3 -> 3

    [3,1,2,4,5]

    Now check whether the left part of '4' is smaller than 4 and right part of '4' is greater than 4

2nd recursive call:

    pivot : 3
    NO of elements lesser than 3 -> {1,2} -> 2
    update pivot -> 0+2 -> 2

    [1,2,3,4,5]

    Now check whether the left part of '3' is smaller than 3 and right part of '3' is greater than 3

And after than no swapping is done bcz the array is sorted

Use case:
    When memory is a constraint
    When No of elements are large
    When array is not sorted or partially sorted

*/

#include <bits/stdc++.h>
using namespace std;
int arr[]={28,27,43,3,9,82,10};
int n=sizeof(arr)/sizeof(arr[0]);
int partition(int arr[],int s,int e){
    int pivot=arr[s];

    int count=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot) count++;
    }

    // updating pivot position
    int pivot_pos=s+count;
    swap(arr[s],arr[pivot_pos]);

    // placing all elements smaller than pivot to left and greater than pivot to right

    int i=s,j=e;
    while(i<pivot_pos && j>pivot_pos){
        while(arr[i]<=pivot) i++;
        while(arr[j]>pivot) j--;
        if(i<pivot_pos && j>pivot_pos) swap(arr[i],arr[j]);
    }
    return pivot_pos;
}
void quickSort(int arr[],int s,int e){
    if(s>=e) return;
    int mid=(s+e)/2;
    int p=partition(arr,s,e); // finding pivot
    quickSort(arr,s,p-1); // sorting left part
    quickSort(arr,p+1,e); // sorting right part
}
int main(){
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}