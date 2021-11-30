/*
Peak element 
A peak element in an array is the one that is not smaller than its neighbours.
Given an array of size N, find the index of any one of its peak elements.
 

Example 1:

Input:
N = 3
arr[] = {1,2,3}
Output: 2 
Explanation: index 2 is 3.
It is the peak element as it is 
greater than its neighbour 2.
 

Example 2:

Input:
N = 2
arr[] = {3,4}
Output: 1
Explanation: 4 (at index 1) is the 
peak element as it is greater than 
its only neighbour element 3.
 

Your Task:
You don't have to read input or print anything. Complete the function peakElement() which takes the array arr[] and its size N as input parameters and return the index of any one of its peak elements.
Note: The generated output will be 1 if the index that you return is correct. Otherwise output will be 0. 

 

Expected Time Complexity: O(log N)
Expected Auxiliary Space: O(1)

 

Constraints:
1 <= N <= 105
1 <= A[] <= 106

*/

// method 1

int peakElement(int arr[], int n)
{
   // Your code here
   if(n == 1){
       return 0;
   }
   else if(n == 2){
       int x = (arr[0] > arr[1]) ? 0 : 1;
       return x;
   }else{
       if(arr[0] >= arr[1]){
           return 0;
       }
       if(arr[n-1] >= arr[n-2]){
           return n-1;
       }
       
       for(int i=1; i<n-1; i++){
           if(arr[i] >= arr[i-1] && arr[i] >= arr[i+1]){
               return i;
           }
       }
   }
}


// method 2

int peakElement(int arr[], int n)
{
   // Your code here
   int low = 0;
   int high = n-1;
   
   while(low<=high){
       int mid = (low+high) / 2;
       
       if((mid == 0 || arr[mid] >= arr[mid-1]) && (mid == n-1 || arr[mid] >= arr[mid+1])){
           return mid;
       }else if(arr[mid] <= arr[mid+1]){
           low = mid+1;
       }else{
           high = mid-1;
       }
   }
   return -1;
}


