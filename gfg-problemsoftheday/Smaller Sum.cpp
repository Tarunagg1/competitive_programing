// Smaller Sum
// MediumAccuracy: 70.7%Submissions: 6K+Points: 4
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// You are given an array arr of n integers. For each index i, you have to find the sum of all integers present in the array with a value less than arr[i].

// Example 1:

// Input:
// n = 3
// arr = {1, 2, 3}
// Output:
// 0 1 3
// Explanation:
// For 1, there are no elements lesser than itself.
// For 2, only 1 is lesser than 2.
// And for 3, 1 and 2 are lesser than 3, so the sum is 3.
// Example 2:

// Input:
// n = 2
// arr = {4, 4}
// Output:
// 0 0
// Explanation:
// For 4, there are no elements lesser than itself.
// For 4, there are no elements lesser than itself.
// There are no smaller elements than 4.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function smallerSum() which takes an integer n and an array arr and returns an array of length n , the answer for every index.

// Expected Time Complexity:O(n log n)
// Expected Space Complexity:O(n)

// Constraints:
// 1 <= n <= 105
// 1 <= arr[i] <= 109

// View Bookmarked Problems
// Topic Tags

class Solution
{
public:
    vector<long long> smallerSum(int n, vector<int> &arr)
    {
        // Code here
        vector<int> num(arr.begin(), arr.end());

        unsigned long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = sum + arr[i];
        }
        // final vector
        vector<long long> result(n, 0);
        sort(arr.begin(), arr.end(), greater<int>());
        unordered_map<int, long long> temp;
        // 3 2 1
        // sum 6
        // 6 - 3 = 3 temp[3] = 3
        // 3 - 2 = 1 temp[2] = 1
        // 1 - 1 = 0 temp[1] = 0
        for (int i = 0; i < n; i++)
        {
            sum = sum - arr[i];
            temp[arr[i]] = sum;
        }
        // num = 1 2 3
        // temp[1] 0
        // temp[2] = 1
        // temp[3] = 3
        for (int i = 0; i < n; i++)
        {
            result[i] = temp[num[i]];
        }
        return result;
    }
};
