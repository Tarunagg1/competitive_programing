// Reverse an Array
// Difficulty: EasyAccuracy: 55.32%Submissions: 45K+Points: 2
// You are given an array of integers arr[]. Your task is to reverse the given array.

// Examples:

// Input: arr = [1, 4, 3, 2, 6, 5]
// Output: [5, 6, 2, 3, 4, 1]
// Explanation: The elements of the array are 1 4 3 2 6 5. After reversing the array, the first element goes to the last position, the second element goes to the second last position and so on. Hence, the answer is 5 6 2 3 4 1.
// Input: arr = [4, 5, 2]
// Output: [2, 5, 4]
// Explanation: The elements of the array are 4 5 2. The reversed array will be 2 5 4.
// Input: arr = [1]
// Output: [1]
// Explanation: The array has only single element, hence the reversed array is same as the original.
// Constraints:
// 1<=arr.size()<=105
// 0<=arr[i]<=105

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int n = arr.size()-1;
        for(int i =0;i<arr.size();i++)
        {
            if(n>=i)
            {
                int temp = arr[i];
                arr[i] = arr[n];
                arr[n] = temp;
                n--;    
            }
            
        }
    }
};
