// Missing And Repeating
// Difficulty: MediumAccuracy: 24.83%Submissions: 482K+Points: 4
// Given an unsorted array arr of of positive integers. One number 'A' from set {1, 2,....,n} is missing and one number 'B' occurs twice in array. Find numbers A and B.

// Examples

// Input: arr[] = [2, 2]
// Output: 2 1
// Explanation: Repeating number is 2 and smallest positive missing number is 1.
// Input: arr[] = [1, 3, 3]
// Output: 3 2
// Explanation: Repeating number is 3 and smallest positive missing number is 2.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 2 ≤ n ≤ 105
// 1 ≤ arr[i] ≤ n

// Seen this question in a real interview before ?

class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        // code here
        int xo = 0, n = arr.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            xo ^= abs(arr[i]) ^ (i + 1);
            if (arr[abs(arr[i]) - 1] < 0)
                ans.push_back(abs(arr[i]));
            else
                arr[abs(arr[i]) - 1] *= -1;
        }
        ans.push_back(ans[0] ^ xo);
        return ans;
    }
};
