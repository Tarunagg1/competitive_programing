// Unequal Arrays
// MediumAccuracy: 73.76%Submissions: 3K+Points: 4
// Unlock your coding potential - join our Hiring Coding Contest and land your dream job!

// You are given two arrays A and B each of length N. You can perform the following operation on array A zero or more times.

// Select any two indices i and j, 1 <= i , j <= N and i != j
// Set A[i] = A[i] + 2 and A[j] = A[j]-2
// Find the minimum number of operations required to make A and B equal.

// Note :

// Two arrays are said to be equal if the frequency of each element is equal in both of them.
// Arrays may contain duplicate elements.
// Example 1:

// Input:
// N = 3
// A[] = {2, 5, 6}
// B[] = {1, 2, 10}
// Output: 2
// Explanation:
// Select i = 3, j = 2, A[3] = 6 + 2 = 8 and A[2] = 5 - 2 = 3
// Select i = 3, j = 2, A[3] = 10 - 2 = 8 and A[2] = 3 - 2 = 1
// Now A = {2, 1, 10} and B = {1, 2, 10}
// Example 2:

// Input:
// N = 2
// A[] = {3, 3}
// B[] = {9, 8}
// Output: -1
// Explanation:
// It can be shown that A cannot be made equal to B.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function solve() which takes the 2 arrays A[], B[] and their size N as input parameters and returns the minimum number of moves to make A and B equal if possible else return -1.

// Expected Time Complexity: O(NlogN)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= N <= 105
// -109 <= A[i] <= 109
// -109 <= B[i] <= 109

// View Bookmarked Problems

class Solution
{
public:
    long long solve(int N, vector<int> &A, vector<int> &B)
    {
        // code here
        long long s = 0, s1 = 0, diff = 0;
        for (int i = 0; i < N; i++)
        {
            s += A[i];
            s1 += B[i];
        }
        if (s != s1)
            return -1;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        vector<int> a, b, c, d;
        for (int i = 0; i < N; i++)
        {
            if (A[i] % 2 == 0)
                a.push_back(A[i]);
            else
                b.push_back(A[i]);
            if (B[i] % 2 == 0)
                c.push_back(B[i]);
            else
                d.push_back(B[i]);
        }
        if (a.size() != c.size() || b.size() != d.size())
            return -1;
        for (int i = 0; i < a.size(); i++)
            diff += abs(a[i] - c[i]);
        for (int i = 0; i < b.size(); i++)
            diff += abs(b[i] - d[i]);
        if (diff % 4 != 0)
            return -1;
        return diff / 4;
    }
};
