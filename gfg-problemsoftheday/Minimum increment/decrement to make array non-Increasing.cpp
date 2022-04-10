// Minimum increment/decrement to make array non-Increasing
// Medium Accuracy: 58.4% Submissions: 929 Points: 4
// Lamp Geeks Summer Carnival is LIVE NOW
// Note: This POTD is a part of Geek Summer Carnival. Solve all POTD consecutively from 5th to 10th April and get a chance to win exclusive discount vouchers on our GfG courses.

// Given an array a of length n, find the minimum number of operations required to make it non-increasing. You can select any one of the following operations and preform it any number of times on an array element.

// increment the array element by 1.
// decrement the array element by 1.
// Example 1:

// Input:
// N = 4
// array = {3, 1, 2, 1}
// Output: 1
// Explanation:
// Decrement array[2] by 1.
// New array becomes {3,1,1,1} which is non-increasing.
// Therefore, only 1 step is required.

// Example 2:

// Input:
// N = 4
// array = {3, 1, 5, 1}
// Output: 4

// Your Task:
// You don't need to read input or print anything. Complete the function minOperations() that takes n and array a as input parameters and returns the minimum number of operations required.

// Expected time complexity: O(nlogn)
// Expected space complexity: O(n)

// Constraints:
// 1 <= n <= 10^4
// 1 <= a[i] <= 10^4

// View Bookmarked Problems
// Company Tags
// Topic Tags

class Solution
{
public:
    int minOperations(int *a, int n)
    {
        int sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
        {
            if (!pq.empty() && pq.top() < a[i])
            {
                sum += (a[i] - pq.top());
                pq.push(a[i]);
                pq.pop();
            }
            pq.push(a[i]);
        }
        return sum;
    }
};
