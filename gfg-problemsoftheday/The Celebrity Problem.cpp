// The Celebrity Problem
// Difficulty: MediumAccuracy: 38.33%Submissions: 250K+Points: 4
// A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people.  A square matrix mat is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

// Note: Follow 0-based indexing.

// Examples:

// Input: mat[][] = [[0 1 0],
//                 [0 0 0],
//                 [0 1 0]]
// Output: 1
// Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity.
// Input: mat[][] = [[0 1],
//                 [1 0]]
// Output: -1
// Explanation: The two people at the party both know each other. None of them is a celebrity.
// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= mat.size()<= 3000
// 0 <= mat[i][j]<= 1

// Seen this question in a real interview before ?

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size();

        int i = 0, j = n - 1;
        while (i < j)
        {
            // check if both person don't know each other then neither can be celebrity
            if (mat[i][j] == 0 && mat[j][i] == 0)
            {
                i++;
                j--;
            }
            // if i know j then i is not celebrity but j  can be
            else if (mat[i][j] == 1)
                i++;
            // if j knows i then j cannot but i can be
            else if (mat[j][i] == 1)
                j--;

            // continue this loop, the pointer will be stuck on the potential celebrity as
            // if i is the celebrity then mat[i][j] != 1 for any j so i will be stuck on the celebrity
        }

        // now i is our potential celebrity but as in question there may be no celebrity so check only for i
        for (int k = 0; k < n; k++)
        {
            if (k == i)
                continue; // celebrity does't know itself
            if (mat[i][k] == 1 || mat[k][i] == 0)
                return -1;
        }
        return i;
    }
};
