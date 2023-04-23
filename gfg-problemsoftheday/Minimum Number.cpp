// Minimum Number
// EasyAccuracy: 71.17%Submissions: 4K+Points: 2
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// You are given an array arr of n elements. In one operation you can pick two indices i and j, such that arr[i] >= arr[j] and replace the value of arr[i] with (arr[i] - arr[j]). You have to minimize the values of the array after performing any number of such operations.

// Example 1:

// Input:
// n = 3
// arr = {3,2,4}
// Output:
// 1
// Explanation:
// 1st Operation : We can pick 4 & 3, subtract 4-3 => {3,2,1}
// 2nd Opeartion : We can pick 3 & 2, subtarct 3-2 => {1,2,1}
// 3rd Operation : We can pick 1 & 2, subtract 2-1 => {1,1,1}
// 4th Opeartion : We can pick 1 & 1, subtract 1-1 => {1,0,1}
// 5th Operation : We can pick 1 & 1, subtract 1-1 => {0,0,1}
// After this no operation can be performned, so maximum no is left in the array is 1, so the ans is 1.
// Example 2:

// Input:
// n = 2
// arr = {2,4}
// Output:
// 2
// Explanation:
// 1st Operation : We can pick 4 & 2, subtract 4-2 => {2,2}
// 2nd Operation : We can pick 2 & 2, subtract 2-2 => {0,2}
// After this no operation can be performned, so maximum no is left in the array is 2, so the ans is 2.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function minimumNumber() which takes an integer n and an array arr, as input parameters and returns the maximum number which is minimized after performing operations.

// Expected Time Complexity: O(n)
// Expected Space Complexity: O(1)

// Constraints:
// 1 ≤ n ≤ 105
// 1 ≤ arr[i] ≤ 109

// View Bookmarked Problems

class Solution
{
public:
    int minimumNumber(int n, vector<int> &arr)
    {
        // Code here
        int even = 0, odd = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
                even++;
            else
                odd++;
        }
        if (odd >= 1)
            return 1;
        return 2;
    }
};
