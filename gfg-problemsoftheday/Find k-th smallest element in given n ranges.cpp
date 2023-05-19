// Find k-th smallest element in given n ranges
// MediumAccuracy: 39.75%Submissions: 3K+Points: 4
// Applying for Jobs, Now Easier Than Today's Problem! Explore Now

// Given n ranges of the form [p, q] which denotes all the numbers in the range [p, p + 1, p + 2,...q].  Given another integer q denoting the number of queries. The task is to return the kth smallest element for each query (assume k>1) after combining all the ranges.
// In case the kth smallest element doesn't exist return -1.

// Example 1:

// Input:
// n = 2, q = 3
// range[] = {{1, 4}, {6, 8}}
// queries[] = {2, 6, 10}
// Output:
// 2 7 -1
// Explanation:
// After combining the given ranges,
// the numbers become 1 2 3 4 6 7 8. As here 2nd
// element is 2, so we print 2. As 6th element is
// 7, so we print 7 and as 10th element doesn't
// exist, so weprint -1.
// Example 2:

// Input:
// n = 2, q = 2
// range[] = {{2, 6}, {5, 7}}
// queries[] = {5, 8}
// Output:
// 6 -1
// Explantion:
// After combining the ranges, we'll take Union of
// range= {2,3,4,5,6,7}, here  5th smallest number
// will be 6 and 8th smallest number does not exists.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function kthSmallestNum() which takes a n * 2 array denoting the ranges and an array denoting the queries.

// Expected Time Complexity: O(nlogn+q*n)
// Expected Auxiliary Space: O(q)

// Constraints:
// 1 <= n <= 103
// 1 <= range[i][0] <= range[i][1] <= 2*109
// 1 <= q <= 500
// 1 <= queries[i] <= 2*109

// View Bookmarked Problems

class Solution
{
public:
    vector<int> kthSmallestNum(int n, vector<vector<int>> &vec1, int q, vector<int> vec2)
    {
        sort(vec1.begin(), vec1.end());
        int start = vec1[0][0], end = vec1[0][1];
        vector<vector<int>> vec;
        for (int i = 1; i < n; i++)
        {
            if (vec1[i][0] <= end)
            {
                if (end < vec1[i][1])
                    end = vec1[i][1];
            }
            else
            {
                vec.push_back({start, end});
                start = vec1[i][0];
                end = vec1[i][1];
            }
        }
        vec.push_back({start, end});
        vector<int> res;
        for (int i = 0; i < q; i++)
        {
            int k = vec2[i];
            bool find = false;
            for (int j = 0; j < vec.size(); j++)
            {
                start = vec[j][0];
                end = vec[j][1];
                if (k <= end - start + 1)
                {
                    res.push_back(start + k - 1);
                    find = true;
                    break;
                }
                else
                {
                    k = k - (end - start + 1);
                }
            }
            if (find == false)
            {
                res.push_back(-1);
            }
        }
        return res;
    }
};
