// Pythagorean Triplet
// MediumAccuracy: 24.77%Submissions: 158K+Points: 4
// Hiring Challenge for Working Professionals on 10th November.
// Apply to 6 Companies through 1 Contest!

// banner
// Given an array arr of n integers, write a function that returns true if there is a triplet (a, b, c) from the array (where a, b, and c are on different indexes) that satisfies a2 + b2 = c2, otherwise return false.

// Example 1:

// Input:
// N = 5
// Arr[] = {3, 2, 4, 6, 5}
// Output: Yes
// Explanation: a=3, b=4, and c=5 forms a
// pythagorean triplet.
// Example 2:

// Input:
// N = 3
// Arr[] = {3, 8, 5}
// Output: No
// Explanation: No such triplet possible.
// Your Task:
// You don't have to take any input or print any thing. You have to complete the function checkTriplet() which takes an array arr, a single integer n, as input parameters and returns boolean denoting answer to the problem.
// Note: The driver will print "Yes" or "No" instead of corresponding to the boolean value returned.

// Expected Time Complexity: O(n+max(Arr[i])2)
// Expected Auxiliary Space: O(max(Arr[i]))

// Constraints:
// 1 <= n <= 105
// 1 <= arr[i] <= 1000

// Company Tags

class Solution
{
public:
    // Function to check if the
    // Pythagorean triplet exists or not
    bool findingpair(int arr[], int k, int n)
    {
        int i = 0, j = k - 1;
        long target = arr[k] * arr[k];
        while (i < j && i < n && j >= 0)
        {
            long temp = (arr[i] * arr[i]) + (arr[j] * arr[j]);
            if (temp == target)
            {
                // cout<<i<<" "<<j<<" "<<k<<" "<<target<<endl;
                return true;
            }
            else if (temp < target)
                i++;
            else
                j--;
        }

        return false;
    }

    bool checkTriplet(int arr[], int n)
    {
        // code here
        sort(arr, arr + n);
        for (int i = n - 1; i >= 2; i--)
        {
            if (findingpair(arr, i, n))
                return true;
        }
        return false;
    }
};
