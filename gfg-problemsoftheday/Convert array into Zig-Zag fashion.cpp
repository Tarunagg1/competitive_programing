// Convert array into Zig-Zag fashion
// EasyAccuracy: 58.28%Submissions: 128K+Points: 2
// Solve today's problem-> Be the comment of the day-> Win a GfG T-Shirt!
// Daily rewards up for grabs!

// banner
// Given an array arr of distinct elements of size n, the task is to rearrange the elements of the array in a zig-zag fashion so that the converted array should be in the below form: 

// arr[0] < arr[1]  > arr[2] < arr[3] > arr[4] < . . . . arr[n-2] < arr[n-1] > arr[n]. 

// Note: Modify the given arr[] only, If your transformation is correct, the output will be 1 else the output will be 0. 

// Examples

// Input: n = 7, arr[] = {4, 3, 7, 8, 6, 2, 1}
// Output: 3 7 4 8 2 6 1
// Explanation: 3 < 7 > 4 < 8 > 2 < 6 > 1
// Input: n = 4, arr[] = {1, 4, 3, 2}
// Output: 1 4 2 3
// Explanation: 1 < 4 > 2 < 3
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= n <= 106
// 0 <= arri <= 109

class Solution {
  public:
    void zigZag(int n, vector<int> &arr) {
        // code here
        
         for (int i = 0; i < n - 1; i++) {
            // If i is even, arr[i] should be less than arr[i+1]
            if (i % 2 == 0) {
                if (arr[i] > arr[i + 1]) {
                    // Swap arr[i] and arr[i+1]
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            } else {
                // If i is odd, arr[i] should be greater than arr[i+1]
                if (arr[i] < arr[i + 1]) {
                    // Swap arr[i] and arr[i+1]
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            }
        }

    }
};



















