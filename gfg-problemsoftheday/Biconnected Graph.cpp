// Biconnected Graph
// Medium Accuracy: 58.75% Submissions: 1590 Points: 4
// Given a graph with n vertices, e edges and an array arr[] denoting the edges connected to each other, check whether it is Biconnected or not.
// Note: The given graph is Undirected.

// Example 1:

// Input:
// n = 2, e = 1
// arr = {0, 1}
// Output:
// 1
// Explanation:
//        0
//       /
//      1
// The above graph is Biconnected.
// Example 2:

// Input:
// n = 3, e = 2
// arr = {0, 1, 1, 2}
// Output:
// 0
// Explanation:
//        0
//       /
//      1
//       \
//        2
// The above graph is not Biconnected.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function biGraph() which takes 2 Integers n, and e and an array arr of length 2*e as input and returns 1 if the graph is biconnected else returns 0.

// Expected Time Complexity: O(n+e)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 <= e <= 100
// 2 <= n <= 100

// View Bookmarked Problems

class Solution
{
public:
    int biGraph(int a[], int n, int e)
    {
        // code here
        if (e == n - 1 && n <= 2)
            return 1;

        int f[n] = {0};

        for (int i = 0; i < 2 * e; i++)
            f[a[i]]++;

        for (int i : f)
            if (i < 2)
                return 0;

        return 1;
    }
};

