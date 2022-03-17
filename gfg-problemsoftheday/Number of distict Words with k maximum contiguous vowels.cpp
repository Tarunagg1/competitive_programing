// Number of distict Words with k maximum contiguous vowels 
// Hard Accuracy: 50.98% Submissions: 2598 Points: 8
// Find the number of unique words consisting of lowercase alphabets only of length N that can be formed with at-most K contiguous vowels. 


// Example 1:

// Input:
// N = 2
// K = 0
// Output:
// 441
// Explanation:
// Total of 441 unique words are possible
// of length 2 that will have K( =0) vowels
// together, e.g. "bc", "cd", "df", etc are
// valid words while "ab" (with 1 vowel) is
// not a valid word.

// Example 2:

// Input:
// N = 1
// K = 1
// Output:
// 26
// Explanation:
// All the english alphabets including
// vowels and consonants; as atmost K( =1)
// vowel can be taken.

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function kvowelwords() which takes an Integer N, an intege K and returns the total number of words of size N with atmost K vowels. As the answer maybe to large please return answer modulo 1000000007.


// Expected Time Complexity: O(N*K)
// Expected Auxiliary Space: O(N*K)


// Constraints:
// 1 ≤ N ≤ 1000
// 0 ≤ K ≤ N



class Solution
{
  public:
    const int mod = 1e9+7;
    
    using ll = long long;
    int max_K;
    int kvowelwords(int N, int K) {
        int cnt = 0;
        max_K = K;
        vector<vector<ll>> dp(N+1,vector<ll> (K+1,-1));
        
        for(int i=0; i<=N; i++){
            for(int j=0; j<=K; j++){
                if(i == 0){
                    dp[i][j] = 1;
                    continue;
                }
                if(j>0){
                    dp[i][j] = (5*dp[i-1][j-1]%mod+21*dp[i-1][K]%mod)%mod;
                }
                else{
                    dp[i][j] = 21*dp[i-1][K]%mod;
                }
            }
        }
        return dp[N][K];
        
        // ll ans = solve(N,K,dp);
        // return (int)ans;
    }
    
    long long solve(int n,int k,vector<vector<ll>> &dp){
        
        if(n == 0){
            return 1;
        }
        if(dp[n][k] != -1){
            return dp[n][k];
        }
        if(k>0){
            //take oval
            ll ans1 = 5*solve(n-1,k-1,dp)%mod;
            
            //no take oval
            
            ll ans2 = 21*solve(n-1,max_K,dp)%mod;
            
            return dp[n][k] = (ans1+ans2)%mod;
        }
        else{
            //not possible to take oval, broken sequence so can take ovals again
            return dp[n][k] = 21*solve(n-1,max_K,dp)%mod;
        }
    }
};


























