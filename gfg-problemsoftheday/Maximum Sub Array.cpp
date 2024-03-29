// Maximum Sub Array
// MediumAccuracy: 15.84%Submissions: 49606Points: 4
// Find out the maximum sub-array of non negative numbers from an array.

// The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

// Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

// Example:
// a = [1, 2, 5, -7, 2, 3]
// The two sub-arrays are [1, 2, 5] [2, 3].
// The answer is [1, 2, 5] as its sum is larger than [2, 3]

// NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length.
// If there is still a tie, then return the segment with minimum starting index.
// If no such subarray is present return "-1"

// Example 1:

// Input:
// n = 3
// a[] = {1, 2, 3}
// Output: 1 2 3
// Explanation: In the given array every
// element is non-negative.
// Example 2:

// Input:
// n = 2
// a[] = {-1, 2}
// Output: 2
// Explanation: The only subarray [2] is
// the answer.

// Your Task:
// Complete the function findSubarray() which takes the array a and the size of the array, n, as input parameters and returns an array representing the answer. If there is no subarray return an array of length 1 containing -1 only. You don't to print answer or take inputs.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 105
// -105 ≤ A[i] ≤ 105

// View Bookmarked Problems

class Solution
{
public:
    vector<int> findSubarray(int a[], int n)
    {
        // code here
        vector<int> ans;

        vector<int> store;

        int sum = 0;

        int ansSum = 0;

        for (int i = 0; i <= n; i++)
        {

            if (i == n or a[i] < 0)
            {

                if (ansSum < sum)
                {

                    ansSum = sum;

                    ans = store;
                }

                sum = 0;

                store.clear();

                continue;
            }

            sum += a[i];

            store.push_back(a[i]);
        }

        if (ans.size() == 0)
            return {-1};

        return ans;
    }
};
