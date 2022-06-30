// Number of ways 
// Medium Accuracy: 47.11% Submissions: 3784 Points: 4
// Given a value N. In how many ways you can construct a grid of size N x 4 using tiles of size 1 x 4.


// Example 1:

// Input: N = 1
// Output: 1
// Explaination: There is only one way.

// Example 2:

// Input: N = 4
// Output: 2
// Explaination: The first way can be when all 
// the 1 x 4 tiles are arranged horizontally. 
// Second way can be when all the 1 x 4 tiles 
// are arranged vertically.

// Your Task:
// You do not need to read input or print anything. Your task is to complete the function arrangeTiles() which takes the value N as input parameter and returns the number of ways to make N x 4 grid using 1 x 4 tiles.


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)


// Constraints:
// 1 ≤ N ≤ 80

// View Bookmarked Problems
// Company Tags





class Solution{
public:
    vector<long long int>dp;

long long int solve(int N)
    {
       //valid construction if N==0;
       if (N==0) return 1;
       //inValid construction if N<0;
       if (N<0)  return 0;
       if(dp[N]!=-1)
        return dp[N];
       //lengthwise adjustment+breadthwise adjustment(l==1 && b==4)
       return dp[N]=solve(N-1)+solve(N-4);
    }
    
    long long int arrangeTiles(int N){
        // code here
         dp.resize(N+1,-1);
       return solve(N);
    }
};


























