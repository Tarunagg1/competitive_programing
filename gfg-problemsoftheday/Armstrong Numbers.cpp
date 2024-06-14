// Armstrong Numbers
// EasyAccuracy: 49.88%Submissions: 121K+Points: 2
// Solve today's problem-> Be the comment of the day-> Win a GfG T-Shirt!
// Daily rewards up for grabs!

// banner
// You are given a 3-digit number n, Find whether it is an Armstrong number or not.

// An Armstrong number of three digits is a number such that the sum of the cubes of its digits is equal to the number itself. 371 is an Armstrong number since 33 + 73 + 13 = 371.

// Note: Return "Yes" if it is an Armstrong number else return "No".

// Examples

// Input: n = 153
// Output: Yes
// Explanation: 153 is an Armstrong number since 13 + 53 + 33 = 153. Hence answer is "Yes".
// Input: n = 372
// Output: No
// Explanation: 372 is not an Armstrong number since 33 + 73 + 23 = 378. Hence answer is "No".
// Expected Time Complexity: O(1)
// Expected Auxiliary Space: O(1)

// Constraints:
// 100 ≤ n <1000




class Solution {
  public:
    string armstrongNumber(int n){
        // code here
             int temp = n;
        int sum = 0;
        while(temp){
            int r = temp % 10;
            sum += r*r*r;
            temp /= 10;
        }
        return sum == n ? "Yes" : "No" ;
    }
};

















