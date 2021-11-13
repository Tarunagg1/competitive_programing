// 560. Subarray Sum Equals K
// Medium

// 9726

// 323

// Add to List

// Share
// Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

 

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2
 

// Constraints:

// 1 <= nums.length <= 2 * 104
// -1000 <= nums[i] <= 1000
// -107 <= k <= 107
// Accepted
// 604,878
// Submissions
// 1,383,951


// Brute force Approch
 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int count = 0;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
              sum+=nums[j];
            
              if(sum == k) 
                 count++;   
            }
        }
        return count;
    }
};


// Good Approch














