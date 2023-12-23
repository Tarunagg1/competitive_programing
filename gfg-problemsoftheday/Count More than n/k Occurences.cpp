// Count More than n/k Occurences
// EasyAccuracy: 58.35%Submissions: 73K+Points: 2
// Money can’t buy you happiness. But Geekbits can buy you GfG goodies and it’s the same thing. Earn 2X Geekbits Now

// banner
// Given an array arr of size N and an element k. The task is to find the count of elements in the array that appear more than n/k times.

// Example 1:

// Input:
// N = 8
// arr = [3,1,2,2,1,2,3,3]
// k = 4
// Output:
// 2
// Explanation:
// In the given array, 3 and 2 are the only elements that appears more than n/k times.
// Example 2:

// Input:
// N = 4
// arr = [2,3,3,2]
// k = 3
// Output:
// 2
// Explanation: In the given array, 3 and 2 are the only elements that appears more than n/k times. So the count of elements are 2.
// Your Task:
// The task is to complete the function countOccurence() which returns count of elements with more than n/k times appearance.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= N <= 105
// 1 <= a[i] <= 109
// 1 <= k <= N

// Company Tags

class Solution
{
public:
    // Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k)
    {
        // Your code here
        unordered_map<int, int> mp;
        int ans = 0;
        int t = n / k;

        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
            if (mp[arr[i]] > t)
            {
                mp[arr[i]] = INT_MIN;
                ans++;
            }
        }

        return ans;
    }
};
