// Length of the longest subarray with positive product
// MediumAccuracy: 63.71%Submissions: 3K+Points: 4
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// Given an array arr[] consisting of n integers, find the length of the longest subarray with positive (non zero) product.

// Example 1:

// Input:
// arr[] ={0, 1, -2, -3, -4}
// Output:
// 3
// Explanation:
// The longest subarray with positive product is:
// {1, -2, -3}.Therefore, the required length is 3.

// Example 2:

// Input:
// arr[]={-1, -2, 0, 1, 2}
// Output:
// 2
// Explanation:
// The longest subarray with positive products
// are: {-1, -2}, {1, 2}. Therefore, the required
// length is 2.

// Your Task: This is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function maxLength() that takes array arr[], and an integer n as parameters and return the length of the longest subarray where the product of all of its element is positive.

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(1).

// Constraints:
//  1<=n<=105
// -109<=arr[i]<=109

// View Bookmarked Problems

class Solution
{
public:
    // Function to return the length of the
    // longest subarray with ppositive product
    int maxLength(vector<int> &arr, int n)
    {

        vector<pair<int, int>> pre(n, {0, 0}), pre1(n, {0, 0});

        int cnt = 0, cnt1 = 0;

        bool bl = false;

        for (int i = 0; i < n; i++)
        {

            if (arr[i] == 0)
                cnt = 0, cnt1 = 0;

            else
            {

                if (arr[i] > 0)
                {

                    cnt++;

                    bl = true;
                }

                else
                    cnt1++;
            }

            if (cnt1 % 2)
            {

                if (arr[i - (cnt + cnt1 - 1)] < 0)
                    pre[i] = {cnt, cnt1};

                else
                    pre[i] = {0, 0};
            }

            else
                pre[i] = {cnt, cnt1};
        }

        cnt = 0, cnt1 = 0;

        for (int i = n - 1; i >= 0; i--)
        {

            if (arr[i] == 0)
                cnt = 0, cnt1 = 0;

            else
            {

                if (arr[i] > 0)
                    cnt++;

                else
                    cnt1++;
            }

            if (cnt1 % 2)
            {

                if (arr[i + cnt + cnt1 - 1] < 0)
                    pre1[i] = {cnt, cnt1};

                else
                    pre1[i] = {0, 0};
            }

            else
                pre1[i] = {cnt, cnt1};
        }

        int mx = 0;

        if (bl)
            mx = 1;

        for (int i = 0; i < n - 1; i++)
        {

            int val = (pre[i].first + pre1[i + 1].first);

            int val1 = (pre[i].second + pre1[i + 1].second);

            if (val1 % 2)
                val1--;

            int res = (val + val1);

            mx = max(mx, res);
        }

        return mx;
    }
};
