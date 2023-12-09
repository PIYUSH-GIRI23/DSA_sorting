/*

Eg : 432,8,530,90,88,231,11,45,677,199

arr = 432,008,530,090,088,231,011,045,677,199


Step 1) Make a count array to store the count of each unique object of 1's place in the array

count array : 

0 1 2 3 4 5 6 7 8 9
2 2 1 0 0 1 0 1 2 1

Step 2) find prefix sum of count array and store in prefix sum array

prefix sum array : 

0 1 2 3 4 5 6 7 8 9
2 4 5 5 5 6 6 7 9 10

step 3) look at the index of 1's place of each element in the array locate it in the prefix sum array and do j=prefix[i]-count[i] ans store the element in arr[j]

eg : for 199 

i = 9
j = prefix[9]-count[9] = 10-1 = 9
arr[9] = 199

eg : for 677

i = 7
j = prefix[7]-count[7] = 7-1 = 6
arr[6] = 677

the updated array is : 530,090,231,011,432,045,677,008,088,199

------------------------------------------------------------------------------------------------------------------------------

Step 2) do the same for 2nd place

count array :

0 1 2 3 4 5 6 7 8 9
1 1 0 3 1 0 0 1 1 2

prefix sum array :

0 1 2 3 4 5 6 7 8 9
1 2 2 5 6 6 6 7 8 10

updated array : 

008,011,530,231,432,045,677,088,090,199

------------------------------------------------------------------------------------------------------------------------------

Step 3) do the same for 3rd place

count array :

0 1 2 3 4 5 6 7 8 9
5 1 1 0 1 1 1 0 0 0 

prefix sum array :

0 1 2 3 4 5  6  7  8 9
5 6 7 7 8 9 10 10 10 10

updated array :

008,011,045,088,090,199,231,432,530,677

8,11,45,88,90,199,231,432,530,677


*/