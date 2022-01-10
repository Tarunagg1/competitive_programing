// All Tracks>Problem
// Factor Fun
// 364
// 59%
// 20
// ★★★★★5
// 1 votes
// Hashing, Factorization
// Share
// Details
// Submissions
// Discussion
// Similar Problems
// Editorial
// Problem
// You are given an array of size .
// For each element , find the number of index j such that A[j] is a factor of  and j is in range  to

// INPUT
// The first line contains an integer  denoting the size of the array.
// Next line contains  space separated integers.

// OUTPUT
// Output  space separated integers where th integer denotes the number of elements which is a factor of  in the range  to .

// CONSTRAINTS

// Author : Chandan Kumar Sharma

// Sample Input
// 5
// 1 4 2 6 8
// Sample Output
// 0 1 1 2 3

for (int i = 0; i < n; i++)
{
    int ans = 0;
    for (int j = 0; j < i; j++)
    {
        if (a[i] % j == 0)
        {
            if (a[i] / j == j)
            {
                ans += freq[j];
            }
            else
            {
                ans += freq[j];
                ans += freq[a[i] / j];
            }
        }
        cout << ans;
        freq[a[i]]++;
    }
}
