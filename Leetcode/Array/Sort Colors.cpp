// 75. Sort Colors
// Medium

// 7674

// 356

// Add to List

// Share
// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]
// Example 3:

// Input: nums = [0]
// Output: [0]
// Example 4:

// Input: nums = [1]
// Output: [1]
 

// Constraints:

// n == nums.length
// 1 <= n <= 300
// nums[i] is 0, 1, or 2.
 

// Follow up: Could you come up with a one-pass algorithm using only constant extra space?

// Accepted
// 841,648
// Submissions
// 1,591,135



// 1 Approch
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
};


// 2 Approch
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = (int)nums.size();
        int f=0,s=0,t=0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0) f++;
            if(nums[i] == 1) s++;
            if(nums[i] == 2) t++;
        }
        
        for(int i=0; i<f; i++){
            nums[i] = 0;
        }
        for(int i=f; i<f+s; i++){
            nums[i] = 1;
        }
        for(int i=f+s; i<t+s+t; i++){
            nums[i] = 2;
        }
        
    }
};





























