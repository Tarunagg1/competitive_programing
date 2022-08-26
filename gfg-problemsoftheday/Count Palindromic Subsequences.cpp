// Count Palindromic Subsequences
// MediumAccuracy: 49.32%Submissions: 83221Points: 4
// Given a string str of length N, you have to find number of palindromic subsequence (need not necessarily be distinct) which could be formed from the string str.
// Note: You have to return the answer module 109+7;

// Example 1:

// Input:
// Str = "abcd"
// Output:
// 4
// Explanation:
// palindromic subsequence are : "a" ,"b", "c" ,"d"

// Example 2:

// Input:
// Str = "aab"
// Output:
// 4
// Explanation:
// palindromic subsequence are :"a", "a", "b", "aa"

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function countPs() which takes a string str as input parameter and returns the number of palindromic subsequence.

// Expected Time Complexity: O(N*N)
// Expected Auxiliary Space: O(N*N)

// Constraints:
// 1<=length of string str <=1000

class Solution
{
public:
    /*You are required to complete below method */

    long long int countPS(string str)
    {
        long long int mod = 1e9 + 7;
        int n = str.length();
        vector<vector<long long int>> v(n, vector<long long int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            v[i][i] = 1;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                long long int temp = (v[j][j + i - 1] % mod + v[j + 1][j + i] % mod) % mod;
                if (str[j] == str[j + i])
                {
                    v[j][j + i] = (temp + 1) % mod;
                }
                else
                {
                    v[j][j + i] = (mod + temp - v[j + 1][j + i - 1] % mod) % mod;
                }
            }
        }

        return v[0][n - 1];
    }
};
