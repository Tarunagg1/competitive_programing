// Maximum Bipartite Matching
// MediumAccuracy: 79.76%Submissions: 2K+Points: 4
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// There are M job applicants and N jobs.  Each applicant has a subset of jobs that he/she is interested in. Each job opening can only accept one applicant and a job applicant can be appointed for only one job. Given a matrix G with M rows and N columns where G(i,j) denotes ith applicant is interested in the jth job. Find the maximum number of applicants who can get the job.

// Example 1:

// Input:
// M = 3, N = 5
// G = {{1,1,0,1,1},{0,1,0,0,1},
// {1,1,0,1,1}}
// Output: 3
// Explanation: There is one of the possible
// assignment-
// First applicant gets the 1st job.
// Second applicant gets the 2nd job.
// Third applicant gets the 4th job.
// Example 2:

// Input:
// M = 6, N = 2
// G = {{1,1},{0,1},{0,1},{0,1},
// {0,1},{1,0}}
// Output: 2
// Explanation: There is one of the possible
// assignment-
// First applicant gets the 1st job.
// Second applicant gets the 2nd job.

// Your Task:
// You don't need to read to print anything. Your task is to complete the function maximumMatch() which takes matrix G as input parameter and returns the maximum number of applicants who can get the job.

// Expected Time Complexity: O(N3).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 ≤ N, M ≤ 100

// View Bookmarked Problems

class Solution
{
public:
    int maximumMatch(vector<vector<int>> &G)
    {

        int m = G.size();

        int n = G[0].size();

        int match[n];

        memset(match, -1, sizeof(match));

        int res = 0;

        for (int i = 0; i < m; i++)
        {

            vector<bool> used(n, false);

            if (dfs(G, i, used, match))
                res++;
        }

        return res;
    }

    // Driver code

    bool dfs(vector<vector<int>> &G, int u, vector<bool> &used, int match[])
    {

        for (int v = 0; v < G[0].size(); v++)
        {

            if (G[u][v] == 1 && !used[v])
            {

                used[v] = true;

                if (match[v] == -1 || dfs(G, match[v], used, match))
                {

                    match[v] = u;

                    return true;
                }
            }
        }

        return false;
    }
};
