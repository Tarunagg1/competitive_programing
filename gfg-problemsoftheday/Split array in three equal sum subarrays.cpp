// Split array in three equal sum subarrays
// Difficulty: MediumAccuracy: 64.45%Submissions: 8K+Points: 4
// Given an array, arr[], determine if arr can be split into three consecutive parts such that the sum of each part is equal. If possible, return any index pair(i, j) in an array such that sum(arr[0..i]) = sum(arr[i+1..j]) = sum(arr[j+1..n-1]), otherwise return an array {-1,-1}.

// Note: Since multiple answers are possible, return any of them. The driver code will print true if it is correct otherwise, it will print false.

// Examples :

// Input:  arr[] = [1, 3, 4, 0, 4]
// Output: true
// Explanation: [1, 2] is valid pair as sum of subarray arr[0..1] is equal to sum of subarray arr[2..3] and also to sum of subarray arr[4..4]. The sum is 4.
// Input: arr[] = [2, 3, 4]
// Output: false
// Explanation: No three subarrays exist which have equal sum.
// Input: arr[] = [0, 1, 1]
// Output: false
// Constraints:
// 3 ≤ arr.size() ≤ 106
// 0 ≤ arr[i] ≤ 106

class Solution
{
public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int> &arr)
    {
        // code here
        int total_arr_sum = 0;
        for (auto it : arr)
            total_arr_sum += it;

        int first = -1;
        int second = -1;
        int temp = 0;

        // for first subarray
        int current_sum = 0;
        while (temp < arr.size())
        {

            current_sum += arr[temp];

            if (current_sum * 3 == total_arr_sum)
            {
                first = temp;
                temp++;
                break;
            }

            else if (current_sum * 3 > total_arr_sum)
                return {-1, -1};

            else
                temp++;
        }

        // for second subarray
        current_sum = 0;
        while (temp < arr.size())
        {

            current_sum += arr[temp];

            if (current_sum * 3 == total_arr_sum)
            {
                second = temp;
                temp++;
                break;
            }

            else if (current_sum * 3 > total_arr_sum)
                return {-1, -1};

            else
                temp++;
        }

        // for third subarray
        current_sum = 0;
        while (temp < arr.size())
        {

            current_sum += arr[temp];

            if (current_sum * 3 == total_arr_sum)
                return {first, second};

            else if (current_sum * 3 > total_arr_sum)
                return {-1, -1};

            else
                temp++;
        }
    }
};
