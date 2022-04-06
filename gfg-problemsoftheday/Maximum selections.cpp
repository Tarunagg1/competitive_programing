// Maximum selections 
// Medium Accuracy: 72.58% Submissions: 2977 Points: 4
// Lamp Geeks Summer Carnival is LIVE NOW   
// Note: This POTD is a part of Geek Summer Carnival. Solve all POTD consecutively from 5th to 10th April and get a chance to win exclusive discount vouchers on our GfG courses.

// Geek wants to select the maximum number of course bundles at the Geek Summer Carnival. 

// You are given a finite number of courses and N range of numbers each depicting a bundle of courses. Select the maximum number of bundles such that no courses overlap in any of the bundle.

// Note: The ending of a range being the same as start of another isn't considered as an overlap.


// Example 1:

// Input:
// N = 4
// Bundles = 
// 1 5
// 2 3
// 1 8
// 3 5

// Output:
// 2

// Explanation: 

// We can select 2 bundles at max while 
// staying true to the condition. For this, 
// we can pick the ranges (2,3) and (3,5) 
// without any overlap. 
 

// Example 2:

// Input:
// N = 5
// Bundles = 
// 7 9 
// 2 8 
// 1 3 
// 10 11 
// 10 16

// Output:
// 3

// Explanation: 

// We can pick the ranges (1,3), 
// (7,9) and (10,11) without any overlap.

// Your Task:
// You don't need to read input or print anything. Complete the function max_non_overlapping() that takes a 2D array representing N ranges as input parameter.  Return the maximum number of course bundles. 


// Expected time complexity: O(NlogN)
// Expected space complexity: O(1)


// Constraints:
// 1 <= N <= 1000
// 0 <= range[i][j] <= 1000

// View Bookmarked Problems
// Topic Tags


class Solution{
public:
    static bool camp(vector<int> &a,vector<int> &b)
    {
        return a[1] < b[1];
    }

    int check(int ind,vector< vector<int> >& ranges)
    {
        int cnt = ranges[ind][1];
        int count = 1;
        for(int i = ind + 1;i < ranges.size();i++)
        {
            if(ranges[i][0] >= cnt)   
            {
                count++;
                cnt = ranges[i][1];
            }
        }
        // cout << count << endl;
        return count;
    }

    int max_non_overlapping( vector< vector<int> >& ranges )
    {
        // code here
        sort(ranges.begin(),ranges.end(),camp);
        int maxi = INT_MIN;
        maxi = max(maxi,check(0,ranges));
        return maxi;
    }
};


























