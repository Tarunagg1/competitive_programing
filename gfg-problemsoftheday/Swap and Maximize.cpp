// Swap and Maximize
// Difficulty: EasyAccuracy: 64.35%Submissions: 39K+Points: 2
// Given an array arr[ ] of positive elements. Consider the array as a circular array, meaning the element after the last element is the first element of the array. The task is to find the maximum sum of the absolute differences between consecutive elements with shuffling of array elements allowed i.e. shuffle the array elements and make [a1..an] such order that  |a1 – a2| + |a2 – a3| + …… + |an-1 – an| + |an – a1| is maximized.

// Examples:

// Input: arr[] = [4, 2, 1, 8]
// Output: 18
// Explanation: After Shuffling, we get [1, 8, 2, 4]. Sum of absolute difference between consecutive elements after rearrangement = |1 - 8| + |8 - 2| + |2 - 4| + |4 - 1| = 7 + 6 + 2 + 3 = 18.
// Input: arr[] = [10, 12]
// Output: 4
// Explanation: No need of rearrangement. Sum of absolute difference between consecutive elements = |10 - 12| + |12 - 10| = 2 + 2 = 4.
// Constraints:
// 2 ≤ arr.size()≤ 105
// 1 <= arr[i] <= 105

class Solution
{
public:
    long long maxSum(vector<int> &arr)
    {
        // code here
        int i, j;
        vector<int> temp = arr;
        sort(arr.begin(), arr.end());
        sort(temp.begin(), temp.end(), greater<>());
        long long res = 0;
        for (i = 0; i < arr.size(); i++)
        {
            res += abs(arr[i] - temp[i]);
        }
        res += abs(arr[0] - temp[arr.size() - 1]);
        return res;
    }
};
