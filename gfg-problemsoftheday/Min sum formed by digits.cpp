// Min sum formed by digits 
// Easy Accuracy: 61.83% Submissions: 8027 Points: 2
// Given an array of digits (values are from 0 to 9), find the minimum possible sum of two numbers formed from digits of the array. All digits of given array must be used to form the two numbers.

 

// Example 1:

// Input:
// N = 6
// arr[] = {6, 8, 4, 5, 2, 3}
// Output:
// 604
// Explanation:
// The minimum sum is formed by numbers 
// 358 and 246
 

// Example 2:

// Input:
// N = 5
// arr[] = {5, 3, 0, 7, 4}
// Output:
// 82
// Explanation:
// The minimum sum is formed by numbers 
// 35 and 047


// Your Task:
// You don't have to print anything, printing is done by the driver code itself. Your task is to complete the function minSum() which takes the array A[] and its size N as inputs and returns the required sum.
 


// Expected Time Complexity: O(N. log(N))
// Expected Auxiliary Space: O(1)


// Constraints:
// 1 ≤ N ≤ 35
// 0 ≤ A[] ≤ 9

// View Bookmarked Problems





class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
          sort(arr,arr+n);
     
     priority_queue<int>pq_even;//for even index store [from 0]
     priority_queue<int>pq_odd;//for odd index store [from 1]
     
     
     //now insert the value accordingly
     for(int i=0;i<n;i=i+2){
       pq_even.push(arr[i]);  
     }
      for(int i=1;i<n;i=i+2){
       pq_odd.push(arr[i]);  
     }
     
     
     //Now extract the the two numbers accordingly
     //by u it place methods
     
      /*important to take num1 num2 and power in long long int 
      either it will not pass all test-cases*/
     long long int num1=0;
     long long int power=1;
     while(!pq_even.empty()){
         num1+=(pq_even.top()*power);
         pq_even.pop();
         power*=10;
     }
     power=1;
     long long int num2=0;
     while(!pq_odd.empty()){
         num2+=(pq_odd.top()*power);
         pq_odd.pop();
         power*=10;
     }
     return num1+num2;
    }
};































