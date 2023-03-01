// Update Queries
// MediumAccuracy: 59.17%Submissions: 3K+Points: 4
// Lamp
// Don't Miss Out on the Chance to Work with Leading Companies! Visit the GFG Job Fair Now!

// You are given an array of n elements, initially all a[i] = 0. Q queries need to be performed. Each query contains three integers l, r, and x  and you need to change all a[i] to (a[i] | x) for all l ≤ i ≤ r.

// Return the array after executing Q queries.

// Example 1:

// Input:
// N=3, Q=2
// U=[[1, 3, 1],
//    [1, 3, 2]]

// Output:
// a[]={3,3,3}

// Explanation:
// Initially, all elements of the array are 0. After execution of the
// first query, all elements become 1 and after execution of the
// second query all elements become 3.
// Example 2:

// Input:
// N=3, Q=2
// U=[[1, 2, 1],
//    [3, 3, 2]]

// Output:
// a[]={1,1,2}

// Explanantion:
// [0,0,0] => [1,1,0] => [1,1,2]

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function updateQuery() which takes the integer N,Q, and U a QX3 matrix containing the Q queries where U[i][0] is li, U[i][1] is ri andU[i][2] is xi.and it returns the final array a.

// Expected Time Complexity: O(N)
// Expected Space Complexity: O(N)

// Constraints:

// 1<=N<=105

// 1<=Q<=105

// 1<=U[i][0] <= U[i][1]<=N

// 1<= U[i][2] <=105

// View Bookmarked Problems

class Solution
{
public:
    vector<int> updateQuery(int N, int Q, vector<vector<int>> &U)
    {
        // code here
        vector<int> ans(N, 0);
        vector<vector<int>> pref(N, vector<int>(31, 0));
        for (int i = 0; i < Q; i++)
        {
            int l = U[i][0] - 1, r = U[i][1], x = U[i][2];
            for (int j = 0; j < 31; j++)
            {
                int mask = 1 << j;
                if (mask & x)
                {
                    pref[l][j]++;
                    if (r < N)
                    {
                        pref[r][j]--;
                    }
                }
            }
        }
        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < 31; j++)
            {
                pref[i][j] += pref[i - 1][j];
            }
        }
        for (int i = 0; i < N; i++)
        {
            int a = 0;
            for (int j = 0; j < 31; j++)
            {
                if (pref[i][j])
                {
                    a |= (1 << j);
                }
            }
            ans[i] = a;
        }
        return ans;
    }
};
