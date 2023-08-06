// String Permutations
// EasyAccuracy: 48.33%Submissions: 27K+Points: 2
// Given a string S. The task is to find all permutations (need not be different) of a given string.

// Example 1:

// Input:
// S = AAA
// Output: AAA AAA AAA AAA AAA AAA
// Explanation: There are total 6 permutations, as given in the output.
// Example 2:

// Input:
// S = ABSG
// Output: ABGS ABSG AGBS AGSB ASBG ASGB
// BAGS BASG BGAS BGSA BSAG BSGA GABS
// GASB GBAS GBSA GSAB GSBA SABG SAGB
// SBAG SBGA SGAB SGBA
// Explanation: There are total 24 permutations, as given in the output.
// Your Task:
// This is a function problem. You only need to complete the function permutation that takes S as parameter and returns the list of permutations in lexicographically increasing order. The newline is automatically added by driver code.

// Constraints:
// 1 ≤ size of string ≤ 5

// Expected Time Complexity: O(N * N!), N = length of string.
// Expected Auxiliary Space: O(1)



class Solution{
    public:
    //Complete this function
    
      void solve(vector<string> &ans , string S, int index){
        if(index >= S.size()){
          ans.push_back(S);
          return;
        }
        
        for(int j = index; j<S.size(); j++){
            swap(S[index], S[j]);
            solve(ans, S, index+1);
            swap(S[index], S[j]);
        }
    }
    
    vector<string> permutation(string S)
    {
        vector<string> ans;
        int index=0;
        solve(ans, S, index);
        sort(ans.begin(), ans.end());
        return ans;
    }
};















