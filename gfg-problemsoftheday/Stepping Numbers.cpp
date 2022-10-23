// Stepping Numbers
// MediumAccuracy: 55.2%Submissions: 2787Points: 4
// A number is called a stepping number if all adjacent digits have an absolute difference of 1, e.g. '321' is a Stepping Number while 421 is not. Given two integers n and m, find the count of all the stepping numbers in the range [n, m].

// Example 1:

// Input: n = 0, m = 21
// Output: 13
// Explanation: Stepping no's are 0 1 2 3 4 5
// 6 7 8 9 10 12 21
// Example 2:

// Input: n = 10, m = 15
// Output: 2
// Explanation: Stepping no's are 10, 12

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function steppingNumbers() which takes the integer n and integer m as input parameters and returns the number of stepping numbers in the range between n and m.

// Expected Time Complexity: O(log(M))
// Expected Auxiliary Space: O(SN) where SN is the number of stepping numbers in the range

// Constraints:
// 0 ≤ N < M ≤ 107

// View Bookmarked Problems
// Company Tags

class Solution
{
public:
    void dfs(int i, int m, int n, int &ans)

    {

        if (i >= n && i <= m)
            ans++;

        if (i > m || i == 0)
            return;

        int x = i % 10;

        int y = i * 10 + x + 1;

        int z = i * 10 + x - 1;

        if (x == 0) // now we can't go negative

        {

            dfs(y, m, n, ans);
        }

        else if (x == 9) // now can't go positive  side

        {

            dfs(z, m, n, ans);
        }

        else
        {

            dfs(y, m, n, ans);

            dfs(z, m, n, ans);
        }
    }

    int steppingNumbers(int n, int m)

    {

        // Code Here

        int ans = 0;

        for (int i = 0; i < 10; i++)

        {

            dfs(i, m, n, ans);
        }

        // for every no from 0 to 9 we are creating graph of all its neightbours which are stepping

        // and they are in range than we ans++;

        return ans;
    }
};
