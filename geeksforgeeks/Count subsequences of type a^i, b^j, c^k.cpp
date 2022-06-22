// Count subsequences of type a^i, b^j, c^k 
// Medium Accuracy: 46.28% Submissions: 12243 Points: 4
// Given a string S, the task is to count number of subsequences of the form aibjck, where i >= 1, j >=1 and k >= 1.

// Note: 
// 1. Two subsequences are considered different if the set of array indexes picked for the 2 subsequences are different.
// 2.  For large test cases, the output value will be too large, return the answer MODULO 10^9+7

 

// Example 1:

// Input:
// S = "abbc"
// Output: 3
// Explanation: Subsequences are abc, abc and abbc.

// Example 2:

// Input:
// S = "abcabc"
// Output: 7
// Explanation: Subsequences are abc, abc,
// abbc, aabc abcc, abc and abc.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function fun() which takes the string S as input parameter and returns the number of subsequences which follows given condition.


// Expected Time Complexity: O(Length of String).
// Expected Auxiliary Space: O(1) .


// Constraints:
// 1 <= |S| <= 105

// View Bookmarked Problems
// Company Tags


class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        //code here
        long long ans = 0 , mod = 1e9+7 , a = 0, ab = 0, abc = 0 ; 
    for(auto &c: s){
        if(c == 'a')
            a = (2*a + 1)%mod ;
        else if(c == 'b')
            ab = (2*ab + a)%mod ;
        else
            abc = (2*abc + ab)%mod ;
    }
    return abc ;
    }
};




































