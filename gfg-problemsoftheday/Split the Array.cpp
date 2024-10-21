// Split the Array
// Difficulty: EasyAccuracy: 61.8%Submissions: 8K+Points: 2
// Given an array arr[] of integers, the task is to count the number of ways to split given array elements into two disjoint groups such that the XOR of elements of each group is equal.
// Note: The answer could be very large so print it by doing modulo with 109 + 7.

// Examples:

// Input : arr[] = [1, 2, 3]
// Output : 3
// Explanation: {(1),(2, 3)}, {(2),(1, 3)}, {(3),(1, 2)} are three ways with equal XOR value of two groups.
// Input : arr[] = [5, 2, 3, 2]
// Output : 0
// Explanation: No way to split into  two groups whose XOR is equal.
// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1<=arr.size()<=106
// 1<=arr[i]<=106

class Solution
{
public:
    int countgroup(vector<int> &arr)
    {
        // Complete the function
        int aa = 0;
        for (auto &b : arr)
        {
            aa ^= b;
        }
        int ans = pow(2, arr.size() - 1);
        return aa == 0 ? ans - 1 : 0;
    }
};
