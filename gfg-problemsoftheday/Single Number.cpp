// Single Number
// Difficulty: EasyAccuracy: 41.64%Submissions: 33K+Points: 2
// Given an array arr[] of positive integers where every element appears even times except for one. Find that number occurring an odd number of times.

// Examples:

// Input: arr[] = [1, 1, 2, 2, 2]
// Output: 2
// Explanation: In the given array all element appear two times except 2 which appears thrice.
// Input: arr[] = [8, 8, 7, 7, 6, 6, 1]
// Output: 1
// Explanation: In the given array all element appear two times except 1 which appears once.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ arr.size() ≤ 106
// 0 ≤ arri ≤ 105

// Seen

class Solution
{
public:
    int getSingle(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int count = 1;

        int num = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (num == arr[i])
            {
                count++;
            }
            else if (count % 2 != 0)
                break;

            else
            {
                num = arr[i];
                count = 1;Nearest multiple of 10


            }
        }
        return num;
    }
};
