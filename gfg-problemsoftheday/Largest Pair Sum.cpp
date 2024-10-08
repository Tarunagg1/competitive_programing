// Largest Pair Sum
// Difficulty: EasyAccuracy: 69.64%Submissions: 8K+Points: 2
// Find the largest pair sum in an array of distinct integers.

// Examples :

// Input: arr[] = [12, 34, 10, 6, 40]
// Output: 74
// Explanation: Sum of 34 and 40 is the largest, i.e, 34 + 40 = 74.
// Input: arr[] = [10, 20, 30]
// Output: 50
// Explanation: 20 + 30 = 50.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 2 ≤ arr.size() ≤ 106
// 0 ≤ arr[i] ≤ 106

class Solution
{
public:
    int pairsum(vector<int> &arr)
    {
        // code here
        int firstmax = INT_MIN;
        int secmax = INT_MIN;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > firstmax)
            {
                secmax = firstmax;
                firstmax = arr[i];
            }
        }
        if (secmax == INT_MIN)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i] > secmax && arr[i] != firstmax)
                {
                    secmax = arr[i];
                }
            }
        }
        int ans = firstmax + secmax;
        return ans;
    }
};
