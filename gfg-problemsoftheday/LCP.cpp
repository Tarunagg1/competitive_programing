// LCP 
// Medium Accuracy: 50.88% Submissions: 2824 Points: 4
// Lamp Geeks Summer Carnival is LIVE NOW   
// Note: This POTD is a part of Geek Summer Carnival. Solve all POTD consecutively from 5th to 10th April and get a chance to win exclusive discount vouchers on our GfG courses.

// Geek is at the geek summer carnival. He is given an array of N strings. To unlock exclusive course discounts he needs to find the longest common prefix among all strings present in the array. Can you help him ?


// Example 1:

// Input:
// N = 4
// ar[] = {geeksforgeeks, geeks, geek, geezer}

// Output:
// gee

// Explanation: 
// Longest common prefix in all the given string is gee. 
 

// Example 2:

// Input:
// N = 3
// ar[] = {apple, ape, april}

// Output:
// ap

// Your Task:
// You don't need to read input or print anything. Complete the function LCP() that takes integer n and ar[] as input parameters and return the LCP. 

 

// Expected time complexity: O(NlogN)
// Expected space complexity: O(string length)


// Constraints:
// 1 <= N <= 10^3
// 1 <= String Length <= 100

// View Bookmarked Problems
// Topic Tags

class Solution{
public:
    string LCP(string ar[], int n)
    {
        // code here
        sort(ar, ar+n);
       int ans = 0;
       string s = "";
       string a = ar[0], b = ar[n-1];
       if(a == b)
           return b;
       for(int i = 0; i<b.size(); i++)
       {
           if(a[i] != b[i])
           {
               ans = i;
               break;
           }
       }
       s = b.substr(0, ans);
       if(s.size() > 0)
           return s;
       return "-1";
    }
};




















