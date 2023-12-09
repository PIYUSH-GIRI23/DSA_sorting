/*

This is also known as bucket sorting
Here we are not comparing the values
Here we start comparison from LSB i.e from 1's place and then 10's place and so on

*/

/*

[15,1,321,10,802,2,123,90,109,11]

Step 1 ) Find the maximum element in the array i.e 802 and find the number of digits in it i.e 3

step 2) now make every number a 3 digit number
[015,001,321,010,802,002,123,090,109,011]

step 3) Now since the base/radix is 10 we will make 10 buckets from 0 to 9
Note : In case of strings , we take 26 buckets from a to z

step 4) Insert the numbers in the bucket based on their first LSB digit

0 : [010,090]
1 : [001,321,001]
2 : [802,002]
3: [123]
4:
5: [015]
6:
7:
8 : [109]
9 :

Now empty the buckets in the array

[010,090,001,321,001,802,002,123,015,109]

Step 5) Now repeat the same process for the 10's place/second digit

0 : [001,802,002,109]
1 : [010,011,015]
2 : [321,123]
3:
4:
5:
6:
7:
8 :
9 : [090]

Now empty the buckets in the array

[001,802,002,109,010,011,015,321,123,090]

Step 6) Now repeat the same process for the 100's place/third digit

0 : [001,002,010,011,015,090]
1 : [109,123]
2 : 
3: [321]
4:
5:
6:
7:
8 : [802]
9 : 

Now empty the buckets in the array

[001,002,010,011,015,090,109,123,321,802]

[1,2,10,11,15,90,109,123,321,802]



Let d -> no of digit
let b -> base/radix 
let n -> no of elements in the array

TIme Complexity : O(d*(n+b)) 

*/