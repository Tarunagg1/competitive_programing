// Find Total Time Taken
// EasyAccuracy: 59.49%Submissions: 7K+Points: 2
// Unlock your coding potential - join our Hiring Coding Contest and land your dream job!

// You are given an array arr of size n, containing the values in between 1 to n, you are asked to determine the total time taken in order to pick all the array elements from left to right but there is a condition, you are also given an another array time again of size n, time[element] ( 1 <= element <= n ) represents the time after which you can again pick element, For clearity, while moving from left to right if you have once picked element, then you can again pick element only after time[element] sec.

// NOTE:
// 1. It takes 1 sec to move from index i to i+1 (1 <= i < n).
// 2. 1-based indexing.

// Example 1:

// Input:
// n = 4
// arr = {1, 2, 3, 3}
// time = {1, 2, 3, 4}
// Output:
// 5
// Explanation:
// for 1st element(1) = 0 Sec-> total = 0
//     2nd element(2) = 1 Sec-> total = 1+0=1
//     3rd element(3) = 1 Sec-> total = 1+1=2
//     4th element(3) : here element 3 is repeated
//     so we have to calculate time by time[arr[i]]
//     : time[arr[4]] => time[3] => 3 -> total = 2+3 =5
// here you can see 4th element(3) is repeated
// so time will be not 1 sec & we have to
// calculate time by this: time[arr[i]].
// Example 2:

// Input:
// n = 4
// arr = {1, 2, 3, 4}
// time = {1, 2, 3, 4}
// Output:
// 3
// Explanation:
// for 1st element(1) = 0 Sec-> total = 0
//     2nd element(2) = 1 Sec-> total = 1
//     3rd element(3) = 1 Sec-> total = 2
//     4th element(4) = 1 Sec-> total = 3
// here you can see no elements are repeated
// so time will be 1 sec else will have to
// calculate time by this: time[arr[i]].
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function totalTime() which takes three variables n, arr, time, as explained in the problem statement, and returns the total time taken to pick all the elements.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 <= n <= 10^5
// 1 <= arr[i] <= n
// 1 <= time[i] <= 10^5

// View Bookmarked Problems

class Solution
{
public:
    int totalTime(int n, vector<int> &arr, vector<int> &time)
    {
        // code here
        int cur = 0;
        unordered_map<int, int> umap;
        for (int i = 0; i < n; i++)
        {
            if (umap.find(arr[i]) == umap.end())
            {
                umap[arr[i]] = cur + time[arr[i] - 1];
            }
            else
            {
                if (umap[arr[i]] > cur)
                {
                    cur = umap[arr[i]];
                    umap[arr[i]] = cur + time[arr[i] - 1];
                }
                else
                {
                    umap[arr[i]] = cur + time[arr[i] - 1];
                }
            }
            if (i != n - 1)
                cur++;
        }
        return cur;
    }
};
