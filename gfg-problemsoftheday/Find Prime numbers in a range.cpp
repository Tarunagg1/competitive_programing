// Find Prime numbers in a range 
// Medium Accuracy: 70.74% Submissions: 9105 Points: 4
// Given two integers M and N, generate all primes between M and N.

// Example 1:

// Input:
// M=1,N=10
// Output:
// 2 3 5 7
// Explanation:
// The prime numbers between 1 and 10
// are 2,3,5 and 7.
// Example 2:

// Input:
// M=2, N=5
// Output:
// 2,3,5
// Explanation:
// The prime numbers between 2 and 5 are 
// 2,3 and 5.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function primeRange() which takes 2 integer inputs M and N and returns a list of all primes between M and N.


// Expected Time Complexity:O(N*sqrt(N))
// Expected Auxillary Space:O(1)


// Constraints:
// 1<=M<=N<=106


class Solution {
  public:
  
   bool isPrime(int n){
    if(n<=1) return false;
    
    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0) return false;
    }
    
    return true;
   }
   
    vector<int> primeRange(int M, int N) {
        // code here
        vector<int> ans;
        
        for(int i=M; i<=N; i++){
            if(isPrime(i)){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};




























