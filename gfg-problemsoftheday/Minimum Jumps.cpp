// Minimum Jumps
// Difficulty: MediumAccuracy: 11.91%Submissions: 853K+Points: 4
// Given an array arr[] of non-negative integers. Each array element represents the maximum length of the jumps that can be made forward from that element. This means if arr[i] = x, then we can jump any distance y such that y ≤ x.
// Find the minimum number of jumps to reach the end of the array starting from the first element. If an element is 0, then you cannot move through that element.
// Note:  Return -1 if you can't reach the end of the array.

// Examples :

// Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
// Output: 3
// Explanation:First jump from 1st element to 2nd element with value 3. From here we jump to 5th element with value 9, and from here we will jump to the last.
// Input: arr = {1, 4, 3, 2, 6, 7}
// Output: 2
// Explanation: First we jump from the 1st to 2nd element and then jump to the last element.
// Input: arr = {0, 10, 20}
// Output: -1
// Explanation: We cannot go anywhere from the 1st element.
// Expected Time Complexity: O(n)
// Expected Space Complexity: O(1)

// Constraints:
// 0 ≤ arr[i] ≤ 105
// 2 ≤ arr.size() ≤ 106

// Seen this question in a real interview before ?
// Yes
// No
// Company Tags

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        // Your code here
        int n = arr.size();
        int idx = 0;
        int cnt = 0;
        while (idx < n)
        {
            int val = arr[idx];
            if (idx + val >= n - 1)
            {
                cnt++;
                return cnt;
            }
            cnt++;
            int ans = INT_MIN;
            int newCurr = idx;
            for (int j = idx + 1; j <= idx + val; j++)
            {
                if (ans <= arr[j] + j)
                {
                    ans = arr[j] + j;
                    newCurr = j;
                }
            }
            if (ans != INT_MIN)
            {
                idx = newCurr;
            }
            if (val == 0)
            {
                return -1;
            }
        }
        return -1;
    }
};
