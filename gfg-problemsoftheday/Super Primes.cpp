// Super Primes 
// Medium Accuracy: 54.26% Submissions: 2450 Points: 4
// A prime number is Super Prime if it is a sum of two primes. Find all the Super Primes upto N

// Example 1:

// Input:
// N = 5
// Output: 1
// Explanation: 5 = 2 + 3, 5 is the
// only super prime

// Example 2:

// Input:
// N = 10 
// Output: 2
// Explanation: 5 and 7 are super primes

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function superPrimes() which takes the N as input and returns the count of super primes.

// Expected Time Complexity: O(Nlog(logN))
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 105

// View Bookmarked Problems
// Topic Tags



class Solution{
public:	
	
	bool isPrime(int n){
       bool flag = true;
       for(int i = 2; i <= n/2; i++){
           if(n%i == 0){
               return false;
           }
           if((n-2)%i==0){
               return false;
           }
       }
       return flag;
   }
   int superPrimes(int n) {
       int supprime = 0;
       bool flag = false;
       for(int i = 5; i<=n; i=i+2){
           flag = isPrime(i);
           if(flag == true){
               supprime ++;
           }
       }
   return supprime;
   }
};




















