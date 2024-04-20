// Union of Two Sorted Arrays
// MediumAccuracy: 31.39%Submissions: 184K+Points: 4
// Fast-Track your resumes to top tech companies and get the job you deserve! Register for Job-A-Thon Hiring Challenge

// banner
// Given two sorted arrays of size n and m respectively, find their union. The Union of two arrays can be defined as the common and distinct elements in the two arrays.

// Example 1:

// Input:
// n = 5, arr1[] = {1, 2, 3, 4, 5}
// m = 5, arr2 [] = {1, 2, 3, 6, 7}
// Output:
// 1 2 3 4 5 6 7
// Explanation:
// Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
// Example 2:

// Input:
// n = 5, arr1[] = {2, 2, 3, 4, 5}
// m = 5, arr2[] = {1, 1, 2, 3, 4}
// Output:
// 1 2 3 4 5
// Explanation:
// Distinct elements including both the arrays are: 1 2 3 4 5.
// Example 3:

// Input:
// n = 5, arr1[] = {1, 1, 1, 1, 1}
// m = 5, arr2[] = {2, 2, 2, 2, 2}
// Output:
// 1 2
// Explanation:
// Distinct elements including both the arrays are: 1 2.
// Your Task:
// You do not need to read input or print anything. Complete the function findUnion() that takes two arrays arr1[], arr2[], and their size n and m as input parameters and returns a list containing the union of the two arrays.

// Expected Time Complexity: O(n+m).
// Expected Auxiliary Space: O(n+m).

// Constraints:
// 1 <= n, m <= 105
// -109 <= arr1[i], arr2[i] <= 109

class Solution
{
public:
    // arr1,arr2 : the arrays
    //  n, m: size of arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        // Your code here
        // return vector with correct order of elements
        set<int> s;

        for (int i = 0; i < n; i++)
            s.insert(arr1[i]);
        for (int j = 0; j < m; j++)
            s.insert(arr2[j]);

        vector<int> ans(s.begin(), s.end());
        return ans;
    }
};
