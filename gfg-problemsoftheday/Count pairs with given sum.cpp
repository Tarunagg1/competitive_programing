// Count pairs with given sum
// Difficulty: EasyAccuracy: 50.11%Submissions: 35K+Points: 2
// Given an array arr[] and an integer target. You have to find numbers of pairs in array arr[] which sums up to given target.

// Examples:

// Input: arr[] = [1, 5, 7, -1, 5], target = 6 
// Output: 3
// Explanation: Pairs with sum 6 are (1, 5), (7, -1) and (1, 5). 
// Input: arr[] = [1, 1, 1, 1], target = 2 
// Output: 6
// Explanation: Pairs with sum 2 are (1, 1), (1, 1), (1, 1), (1, 1), (1, 1), (1, 1).
// Input: arr[] = [10, 12, 10, 15, -1], target = 125
// Output: 0
// Constraints:
// 1 <= arr.size() <= 105
// -104 <= arr[i] <= 104
// 1 <= target <= 104



class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        int count=0;
    unordered_map<int,int>mp;
        for(auto i:arr){     
               count+= mp[target-i];
                mp[i]++;   
        }
        return count;
    }
};
    


















