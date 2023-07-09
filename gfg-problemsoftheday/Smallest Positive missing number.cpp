// Smallest Positive missing number
// MediumAccuracy: 25.13%Submissions: 241K+Points: 4
// You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.

// Example 1:

// Input:
// N = 5
// arr[] = {1,2,3,4,5}
// Output: 6
// Explanation: Smallest positive missing
// number is 6.
// Example 2:

// Input:
// N = 5
// arr[] = {0,-10,1,3,-20}
// Output: 2
// Explanation: Smallest positive missing
// number is 2.
// Your Task:
// The task is to complete the function missingNumber() which returns the smallest positive missing number in the array.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= N <= 106
// -106 <= arr[i] <= 106

class Solution
{
public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n)
    {
        // Your code here

        sort(arr, arr + n); // sort arry

        int counter = 1; // declaring counter

        for (int i = 0; i < n; i++)
        {

            // if counter is found in array increase counter if not found we will return it

            if (arr[i] == counter)
            {
                counter++;
            }
        }
        return counter;
    }
};
