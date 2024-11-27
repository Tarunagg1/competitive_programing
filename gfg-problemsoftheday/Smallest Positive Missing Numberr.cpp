// Smallest Positive Missing Number
// Difficulty: MediumAccuracy: 25.13%Submissions: 357K+Points: 4
// You are given an integer array arr[]. Your task is to find the smallest positive number missing from the array.

// Note: Positive number starts from 1. The array can have negative integers too.

// Examples:

// Input: arr[] = [2, -3, 4, 1, 1, 7]
// Output: 3
// Explanation: Smallest positive missing number is 3.
// Input: arr[] = [5, 3, 2, 5, 1]
// Output: 4
// Explanation: Smallest positive missing number is 4.
// Input: arr[] = [-8, 0, -1, -4, -3]
// Output: 1
// Explanation: Smallest positive missing number is 1.
// Constraints:
// 1 <= arr.size() <= 105
// -106 <= arr[i] <= 106

class Solution
{
public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr)
    {
        // Your code here
        vector<int> narr;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > 0)
                narr.push_back(arr[i]);
        }

        sort(narr.begin(), narr.end());
        int sm = 1;
        for (int i = 0; i < narr.size(); i++)
        {
            // Skip duplicates
            if (i > 0 && narr[i] == narr[i - 1])
                continue;
            if (narr[i] == sm)
                sm++;
            else if (narr[i] > sm)
                return sm;
        }
        return sm;
    }
};
