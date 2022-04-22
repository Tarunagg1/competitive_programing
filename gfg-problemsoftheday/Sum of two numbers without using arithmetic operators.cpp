// Sum of two numbers without using arithmetic operators 
// Easy Accuracy: 71.8% Submissions: 15650 Points: 2
// Given two integers a and b. Find the sum of two numbers without using arithmetic operators.

// Example 1:

// Input:
// a = 5, b = 3
// Output: 8
// Explanation :
// 5 + 3 = 8
// Example 2:

// Input:
// a = 10, b = 30
// Output: 40
// Explanation:
// 10 + 30 = 40
// Your task:
// You don't need to read input or print anything. Your task is to complete the function sum() which takes two integers a and b as input and returns the sum of a and b, which is calculated without using any arithmetic operator.
 
// Expected Time Complexity : O(max(number of bits in 'a', number of bits in 'b'))
// Expected Auxiliary Space : O(1)
 
// Constraints:
// 1<=a, b<=10^8
// View Bookmarked Problems





class Solution
{
    public:
    int sum(int a , int b)
    {
        //code here
        
         while(b!=0){
           int carry=a&b;
           
           a=a^b;
           
           b=carry<<1;
       }
       return a;
    }
};






























