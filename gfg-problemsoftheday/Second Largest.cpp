// Second Largest
// Difficulty: EasyAccuracy: 26.72%Submissions: 783K+Points: 2
// Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

// Note: The second largest element should not be equal to the largest element.

// Examples:

// Input: arr[] = [12, 35, 1, 10, 34, 1]
// Output: 34
// Explanation: The largest element of the array is 35 and the second largest element is 34.
// Input: arr[] = [10, 5, 10]
// Output: 5
// Explanation: The largest element of the array is 10 and the second largest element is 5.
// Input: arr[] = [10, 10, 10]
// Output: -1
// Explanation: The largest element of the array is 10 and the second largest element does not exist.
// Constraints:
// 2 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 105


class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
          int first_max =  INT_MIN;
        int second_max = INT_MIN;
        
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] > first_max)
            {
                second_max = first_max;
                first_max = arr[i];
                
            }
            else if(arr[i] > second_max and arr[i] != first_max)
            {
                second_max = arr[i];
            }
        }
       // cout << first_max << " " << second_max << endl;
        
        return (second_max == INT_MIN ) ? -1 : second_max;
    }
};

















