/*

Here we are not comparing the values

Eg : 2 1 1 0 4 5 4 1

Step 1) Find the maximum element in the array i.e 5
step 2) make another array of size 6 (max+1) and initialize it with 0
step 3) at index i , insert the total count of i in previous array
step 4) replace the array with the new array

Time complexity : O(n) 

*/

#include <iostream>
#include <vector>
using namespace std;
void countingSort(vector <int > &v, int n) {
    int max=v[0];
    for(int i=1;i<n;i++) {
        if(v[i]>max) max=v[i];
    }
    vector <int > count(max+1,0);
    for(int i=0;i<n;i++) {
        count[v[i]]++;
    }
    int j=0;
    for(int i=0;i<=max;i++) {
        while(count[i]>0) {
            v[j]=i;
            j++;
            count[i]--;
        }
    }
}
int main() {
    vector <int > v={2,1,1,0,4,5,4,1};
    countingSort(v,v.size());
    for(int i=0;i<v.size();i++) {
        cout<<v[i]<<" ";
    }
    return 0;
}