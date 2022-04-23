// Search insert position of K in a sorted array 
// Easy Accuracy: 49.94% Submissions: 16796 Points: 2
// Given a sorted array Arr[](0-index based) consisting of N distinct integers and an integer k, the task is to find the index of k, if it’s present in the array Arr[]. Otherwise, find the index where k must be inserted to keep the array sorted.


// Example 1:

// Input:
// N = 4
// Arr = {1 , 3, 5, 6}
// k = 5
// Output: 2
// Explaination: Since 5 is found at index 2 
// as arr[2] = 5, the output is 2.

// Example 2:

// Input:
// N = 4
// Arr = {1, 3, 5, 6}
// k = 2
// Output: 1
// Explaination: Since 2 is not present in 
// the array but can be inserted at index 1 
// to make the array sorted.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function searchInsertK() which takes the array Arr[] and its size N and k as input parameters and returns the index.


// Expected Time Complexity: O(logN)
// Expected Auxiliary Space: O(1)


// Constraints:
// 1 ≤ N ≤ 104
// -103 ≤ Arr[i] ≤ 103
// -103 ≤ k ≤ 103

// View Bookmarked Problems



class Solution{
    public:
    int searchInsertK(vector<int>Arr, int N, int k)
    {
        // code here
        int beg = 0, end = N - 1;
       int mid;
       while(beg <= end){
           mid = beg + (end - beg)/2;
           if(Arr[mid] == k)
               return mid;
           else if(Arr[mid] > k)
               end = mid - 1;
           else
               beg = mid + 1;
       }
       return beg;
    }
};




















