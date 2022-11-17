// Count of Subarrays
// MediumAccuracy: 42.66%Submissions: 9468Points: 4
// Given an array of N positive integers  Arr1, Arr2 ............ Arrn. The value of each contiguous subarray of given array is the maximum element present in that subarray. The task is to return the number of subarrays having value strictly greater than K.

// Example 1:

// Input:
// N = 3, K = 2
// Arr[] = {3, 2, 1}
// Output: 3
// Explanation: The subarrays having value
// strictly greater than K are: [3], [3, 2]
// and [3, 2, 1]. Thus there are 3 such
// subarrays.
// Example 2:

// Input:
// N = 4, K = 1
// Arr[] = {1, 2, 3, 4}
// Output: 9
// Explanation: There are 9 subarrays having
// value strictly greater than K.
// Your Task:
// Complete the function countSubarray() which takes an array arr, two integers n, k, as input parameters and returns an integer denoting the answer. You don't to print answer or take inputs.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 105
// 1 <= Arr[i] <= 105

// View Bookmarked Problems

class Solution
{
public:
    // #define ll long long

    ll countSubarray(int arr[], int n, int k)
    {
        // code here
        vector<ll> v(n, 0);

        int x = -1;

        if (arr[0] <= k)
        {

            v[0] = 0;
        }

        else
        {

            v[0] = 1;

            x = 1;

            x++;
        }

        for (int i = 1; i < n; i++)
        {

            if (x == -1)
            {

                if (arr[i] <= k)
                {

                    v[i] = 0;
                }

                else
                {

                    //    cout<<"ni\n";

                    v[i] = i + 1;

                    x = i + 2;
                }
            }

            else
            {

                if (arr[i] <= k)
                {

                    v[i] = v[i - 1];
                }

                else
                {

                    v[i] = x;
                }

                x++;
            }

            // cout<<x<<"\n";
        }

        ll ans = 0;

        for (int i = 0; i < n; i++)
        {

            // cout<<v[i]<<"    ";

            ans += v[i];
        }

        // cout<<endl;

        return ans;
    }
};
