// Black and White
// MediumAccuracy: 50.61%Submissions: 9K+Points: 4
// Given the chessboard dimensions. Find out the number of ways we can place a black and a white Knight on this chessboard such that they cannot attack each other.

// Note:
// The knights have to be placed on different squares. A knight can move two squares horizontally and one square vertically (L shaped), or two squares vertically and one square horizontally (L shaped). The knights attack each other if one can reach the other in one move.

// Example 1:

// Input:
// N = 2, M = 2
// Output: 12
// Explanation: There are 12 ways we can place a black and a white Knight on this chessboard such that they cannot attack each other.

// Example 2:

// Input:
// N = 2, M = 3
// Output: 26
// Explanation: There are 26 ways we can place a black and a white Knight on this chessboard such that they cannot attack each other.
// Your Task:
// Your task is to complete the function numOfWays() which takes the chessboard dimensions N and M as inputs and returns the number of ways we can place 2 Knights on this chessboard such that they cannot attack each other. Since this number can be very large, return it modulo 109+7.

// Expected Time Complexity: O(N*M).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= N * M <= 105

// View Bookmarked Problems

#define ll long long
const int mod = 1e9 + 7;

long long numOfWays(int n, int m)
{
    ll dir[8][2] = {{-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {1, 2}, {1, -2}};

    ll total_cells = n * m;
    ll ans = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            ll cnt = 0;
            for (int k = 0; k < 8; ++k)
            {
                ll di = i + dir[k][0];
                ll dj = j + dir[k][1];

                if (di >= 0 && di < n && dj >= 0 && dj < m)
                    ++cnt;
            }

            ans += ((total_cells - cnt - 1) % mod);
            ans %= mod;
        }
    }

    return ans;
}
