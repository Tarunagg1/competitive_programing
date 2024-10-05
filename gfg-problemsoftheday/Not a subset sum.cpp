// Not a subset sum
// Difficulty: MediumAccuracy: 45.92%Submissions: 19K+Points: 4
// Given a sorted array arr[] of positive integers, find the smallest positive integer such that it cannot be represented as the sum of elements of any subset of the given array set.

// Examples:

// Input: arr[] = [1, 2, 3]
// Output: 7
// Explanation: 7 is the smallest positive number for which no subset is there with sum 7.
// Input: arr[] = [3, 6, 9, 10, 20, 28]
// Output: 1
// Explanation: 1 is the smallest positive number for which no subset is there with sum 1.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints
// 1 <= arr.size() <= 106
// 0 <= arr[i] <= 108
 


class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        // Your code goes here.
          long long curr = 1;
        for(auto it:arr){
            if(curr<it) return curr;
             curr+=it;
        }
        return curr;
    }
};

















