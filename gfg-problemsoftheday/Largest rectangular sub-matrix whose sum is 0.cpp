// Largest rectangular sub-matrix whose sum is 0
// HardAccuracy: 45.28%Submissions: 14K+Points: 8
// Money can’t buy you happiness. But Geekbits can buy you GfG goodies and it’s the same thing. Earn 2X Geekbits Now

// banner
// Given a matrix mat[][] of size N x M. The task is to find the largest rectangular sub-matrix by area whose sum is 0.

// If there are multiple solutions return the rectangle which starts from minimum column index. If you still have multiple solutions return the one starting from minimum row index. If you still have multiple solutions return the one having greatest row number. If no such matrix is present return a zero (0) size matrix.

// Example 1:

// Input: N = 3, M = 3
// mat[][] =  1, 2, 3
//           -3,-2,-1
//            1, 7, 5

// Output:  1, 2, 3
//         -3,-2,-1

// Explanation: This is the largest sub-matrix,
// whose sum is 0.
// Example 2:

// Input: N = 4, M = 4
// mat[][] = 9, 7, 16, 5
//           1,-6,-7, 3
//           1, 8, 7, 9
//           7, -2, 0, 10

//  Output: -6,-7
//           8, 7
//          -2, 0
// Your Task:
// You don't need to read input or print anything. You just have to complete the function sumZeroMatrix() which takes a 2D matrix mat[][], its dimensions N and M as inputs and returns a largest sub-matrix, whose sum is 0.

// Expected Time Complexity: O(N*M*M).
// Expected Auxiliary Space: O(N*M).

// Constraints:
// 1 <= N, M <= 100
// -1000 <= mat[][] <= 1000

class Solution
{
public:
    pair<int, int> kadne(vector<int> &v)
    {
        int sum = 0;
        int maxi = -1e9; // Initialize maximum sum to a very small value
        int l = 0;       // Initialize left index of the maximum sum subarray
        int r = -1;      // Initialize right index of the maximum sum subarray

        int s = 0; // Initialize the start index of the current subarray
        for (int i = 0; i < v.size(); i++)
        {
            sum += v[i]; // Add the current element to the running sum

            // If the current sum is greater than the maximum sum, update maximum sum and indices
            if (sum > maxi)
            {
                maxi = sum;
                l = s;
                r = i;
            }

            // If the current sum becomes negative, reset sum and update the start index
            if (sum < 0)
            {
                sum = 0;
                s = i + 1;
            }
        }

        // Return the pair of indices representing the maximum sum subarray
        return {l, r};
    }

    vector<vector<int>> sumZeroMatrix(vector<vector<int>> a)
    {
        int m = a.size();    // Number of rows in the matrix
        int n = a[0].size(); // Number of columns in the matrix

        int left, right, up, down;
        left = right = up = down = 0;

        // Iterate over all possible submatrices
        for (int i = 0; i < n; i++)
        {
            vector<int> arr(m, 0);

            for (int j = i; j < n; j++)
            {
                // Calculate the cumulative sum of the submatrix in the 'arr' vector
                for (int k = 0; k < m; k++)
                {
                    arr[k] += a[k][j];
                }

                unordered_map<long long, int> map;
                map[0] = -1;

                int l = 0, r = 0;
                long long sum = 0;

                // Use Kadane's algorithm to find the subarray with the maximum sum
                for (int k = 0; k < m; k++)
                {
                    sum += arr[k];

                    // Update the subarray indices when a zero-sum subarray is found
                    if (map.count(sum))
                    {
                        if ((k - map[sum]) > (r - l))
                        {
                            l = map[sum] + 1;
                            r = k + 1;
                        }
                    }
                    else
                    {
                        map[sum] = k;
                    }
                }

                // Update the maximum submatrix indices
                if ((j - i + 1) * (r - l) > (right - left) * (down - up))
                {
                    up = l;
                    down = r;
                    left = i;
                    right = j + 1;
                }
            }
        }

        // Extract the maximum submatrix and return it
        vector<vector<int>> result;

        for (int i = up; i < down; i++)
        {
            vector<int> arr;

            for (int j = left; j < right; j++)
            {
                arr.push_back(a[i][j]);
            }

            result.push_back(arr);
        }

        return result;
    }
};
