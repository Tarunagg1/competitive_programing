// Counts Zeros Xor Pairs 
// Easy Accuracy: 63.84% Submissions: 8076 Points: 2
// Given an array A[] of size N. Find the number of pairs (i, j) such that
// Ai XOR Aj = 0, and 1 ≤ i < j ≤ N.

// Example 1:

// â€‹Input : arr[ ] = {1, 3, 4, 1, 4}
// Output : 2
// Explanation:
// Index( 0, 3 ) and (2 , 4 ) are only pairs 
// whose xors is zero so count is 2.

// â€‹Example 2:

// Input : arr[ ] = {2, 2, 2} 
// Output :  3

 

// Your Task:
// This is a function problem. The input is already taken care of by the driver code. You only need to complete the function calculate() that takes an array (arr), sizeOfArray (n), and return the count of Zeros Xor's Pairs. The driver code takes care of the printing.

// Expected Time Complexity: O(N*Log(N)).
// Expected Auxiliary Space: O(1).



// Output:
// For each test case, output a single integer i.e counts of Zeros Xors Pairs

// Constraints
// 2 ≤ N ≤ 10^5
// 1 ≤ A[i] ≤ 10^5

 long long int calculate(int a[], int n)
{
    // Complete the function
     map<long long int,long long int> mp;
  for(int i=0;i<n;i++){
      mp[a[i]]++;
  }
  int c=0;
  for(auto it:mp){
      if(it.second>1){
          c+=(it.second*(it.second-1))/2;
      }
  }
  return c;
}















