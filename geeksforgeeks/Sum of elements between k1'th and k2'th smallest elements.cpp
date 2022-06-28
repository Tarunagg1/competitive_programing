// Sum of elements between k1'th and k2'th smallest elements 
// Easy Accuracy: 50.31% Submissions: 11258 Points: 2
// Given an array A[] of N positive integers and two positive integers K1 and K2. Find the sum of all elements between K1th and K2th smallest elements of the array. It may be assumed that (1 <= k1 < k2 <= n).

 

// Example 1:

// Input:
// N  = 7
// A[] = {20, 8, 22, 4, 12, 10, 14}
// K1 = 3, K2 = 6
// Output:
// 26
// Explanation:
// 3rd smallest element is 10
// 6th smallest element is 20
// Sum of all element between
// K1 & K2 is 12 + 14 = 26
 

// Example 2:

// Input
// N = 6
// A[] = {10, 2, 50, 12, 48, 13}
// K1= 2, K2 = 6
// Output:
// 73
 

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function sumBetweenTwoKth() which takes the array A[], its size N and two integers K1 and K2 as inputs and returns the sum of all the elements between K1th and K2th smallest elements.
 

// Expected Time Complexity: O(N. log(N))
// Expected Auxiliary Space: O(N)

 

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ K1, K2 ≤ 109

// View Bookmarked Problems


class Solution{
    public:
    long long sumBetweenTwoKth( long long a[], long long n, long long k1, long long k2)
    {
        // Your code goes here
        k2--;
    priority_queue<long long> pq;

    for (long long i = 0; i < n; i++)
    {
        pq.push(a[i]);
        if (pq.size() > k2)
        {
            pq.pop();
        }
    }

    long long d = k2 - k1;

    long long sum = 0;
    while (d--)
    {
        sum += pq.top();
        pq.pop();
    }

    return sum;
    }
};






















