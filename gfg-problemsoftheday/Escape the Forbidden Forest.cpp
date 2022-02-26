// Escape the Forbidden Forest
// Medium Accuracy: 71.63% Submissions: 2978 Points: 4
// Penelope and her classmates are lost in the Forbidden Forest and the Devil is out to get them. But Penelope has magical powers that can build bridges across the dangerous river and take her friends to safety. The only bridges that can withstand the Devil's wrath are the ones built between two similar trees in the forest.
// Given str1 and str2 denoting the order of trees on either side of the river, find the maximum number of bridges that Penelope can build and save everyone from the Devil.
// Note: Each tree in the forest belongs to one of the 3 categories represented by * or # or @

// Example 1:

// Input:
// str1 = "*@#*"
// str2 = "*#"
// Output:
// 2
// Explanation:
// str1 = "*@#*" and str2 = "*#"
// Two bridges can be built between the banks
// of the river in the following manner.
// * @ # *
// |      |
// *     #
// Example 2:

// Input:
// str1 = "***"
// str2 = "##"
// Output:
// 0
// Your Task:
// You don't need to read input or print anything. Complete the function build_bridges() that takes str1 and str2 as input parameters and returns the maximum number of bridges that can be built.

// Expected Time Complexity: O(N*M)
// Expected Auxiliary Space: O(N*M)

// Constraints:
// 1 ≤ N, M ≤ 100
// Where, N and M are the size of the string str1 and str2 respectively.

// View Bookmarked Problems
// Topic Tags

class Solution
{
public:
    int build_bridges(string str1, string str2)
    {
        // code here
        int n1 = str1.length(), n2 = str2.length();
        int dp[n1 + 1][n2 + 1];

        for (int i = 0; i <= n1; i++)
        {
            for (int j = 0; j <= n2; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if (str1[i - 1] == str2[j - 1])
                    {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                    else
                    {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
        }

        return dp[n1][n2];
    }
}
