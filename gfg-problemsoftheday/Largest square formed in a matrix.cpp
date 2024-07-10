// Largest square formed in a matrix
// Difficulty: MediumAccuracy: 36.98%Submissions: 89K+Points: 4
// Given a binary matrix mat of size n * m, find out the maximum length of a side of a square sub-matrix with all 1s.

// Examples:

// Input: n = 6, m = 5
// mat = [[0, 1, 1, 0, 1],
//        [1, 1, 0, 1, 0],
//        [0, 1, 1, 1, 0],
//        [1, 1, 1, 1, 0],
//        [1, 1, 1, 1, 1],
//        [0, 0, 0, 0, 0]]
// Output: 3
// Explanation:

// The maximum length of a side of the square sub-matrix is 3 where every element is 1.
// Input: n = 2, m = 2
// mat = [[1, 1],
//        [1, 1]]
// Output: 2
// Explanation: The maximum length of a side of the square sub-matrix is 2. The matrix itself is the maximum sized sub-matrix in this case.
// Input: n = 2, m = 2
// mat = [[0, 0],
//        [0, 0]]
// Output: 0
// Explanation: There is no 1 in the matrix.
// Expected Time Complexity: O(n*m)
// Expected Auxiliary Space: O(n*m)

// Constraints:
// 1 ≤ n, m ≤ 500
// 0 ≤ mat[i][j] ≤ 1

// Seen this question in a real interview before ?
// Yes
// No
// Company Tags
// AmazonSamsung

class Solution
{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        // code here
        vector<vector<int>> dp(n + 1, vector<int>(m, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (mat[i][j] == 1)
                {
                    dp[i][j] = 1 + dp[i + 1][j];
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            // apply sliding window on dp[i]
            int st = 0, en = 0;
            deque<int> dq;
            while (en < m)
            {
                while (dq.size() > 0 and dp[i][dq.front()] > dp[i][en])
                {
                    dq.pop_front();
                }
                dq.push_front(en);
                if (en - st + 1 <= dp[i][dq.back()])
                {
                    ans = max(en - st + 1, ans);
                    en++;
                }
                else
                {
                    while (st <= en and en - st + 1 > dp[i][dq.back()])
                    {
                        if (dq.back() == st)
                        {
                            dq.pop_back();
                        }
                        st++;
                    }
                    if (st <= en)
                    {
                        ans = max(ans, en - st + 1);
                    }
                    en++;
                }
            }
        }
        return ans;
    }
};
