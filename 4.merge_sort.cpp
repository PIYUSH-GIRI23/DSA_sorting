/*

Time Complexity (Average): O(nlogn)
Space Complexity: O(n)

Merge sort follows divide and conquer approach. 
It divides the array into two halves, calls itself for the two halves until the size of array becomes 1 
Then it merges the two sorted halves. 

Eg : [28,27,43,3,9,82,10]

1st recursive call:

[28,27,43,3] and [9,82,10]

2nd recursive call:

[28,27] [43,3] and [9,82] [10]

3rd recursive call:

[28] [27] [43] [3] and  [9] [82] [10]

Now we start merging the two halves

[27,28] [3,43] and [9,82] [10]

Now we start merging the two halves

[3,27,28,43] and [9,10,82]

Now we start merging the two halves

[3,9,10,27,28,43,82]


At last we get our sorted array

NOTE: It is not an inplace sorting algorithm bcz here extra memory is being used
NOTE: It is a Stable sorting algorithm bcz it preserves the order of elements with equal keys

Use case: When memory is not a constraint
          When No of elements are large
          When array is not sorted or partially sorted

Disadvantages of merge sort: 

    1. It uses extra memory
    2. It goes on whole process even if the array is sorted
    3. It is not inplace sorting algorithm
    4. Slower for small arrays

*/

#include <bits/stdc++.h>
using namespace std;
int arr[]={28,27,43,3,9,82,10};
int n=sizeof(arr)/sizeof(arr[0]);
void merge(int arr[],int s,int e){
    int mid=(s+e)/2;
    int len1=mid-s+1; 
    int len2=e-mid; 
    int left[len1+1],right[len2+1];

    for(int i=0;i<len1;i++){
        left[i]=arr[i+s];
    }
    for(int i=0;i<len2;i++){
        right[i]=arr[i+mid+1];
    }
    left[len1]=right[len2]=INT_MAX;  

    int i=0,j=0;
    for(int k=s;k<=e;k++){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
    }
}
void mergesort(int arr[],int s,int e){
    if(s>=e) return;
    int mid=(s+e)/2;
    mergesort(arr,s,mid); // sorting left part
    mergesort(arr,mid+1,e); // sorting right part
    merge(arr,s,e); // merging both parts
}
int main(){
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}