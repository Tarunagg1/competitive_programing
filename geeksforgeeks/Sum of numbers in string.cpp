// Sum of numbers in string 
// Basic Accuracy: 55.45% Submissions: 18427 Points: 1
// Given a string str containing alphanumeric characters. The task is to calculate the sum of all the numbers present in the string.

// Example 1:

// Input:
// str = 1abc23
// Output: 24
// Explanation: 1 and 23 are numbers in the
// string which is added to get the sum as
// 24.
// Example 2:

// Input:
// str = geeks4geeks
// Output: 4
// Explanation: 4 is the only number, so the
// sum is 4.
// Your Task:
// The task is to complete the function findSum() which finds and returns the sum of numbers in the string.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= length of the string <= 105
// Sum of Numbers <= 105

// View Bookmarked Problems





class Solution
{
    public:
    //Function to calculate sum of all numbers present in a string.
    int findSum(string str)
    {
    	// Your code here
    	int sum =0;
    	int num = 0;
    	
    	for(int i=0; i<str.size(); i++){
    	    if(str[i] >= '0' && str[i] <= '9'){
    	        num = num*10 + (int)(str[i]-'0');
    	    }else{
    	        sum += num;
    	        num = 0;
    	    }
    	}
    	
    	return sum+num;
    }
};










