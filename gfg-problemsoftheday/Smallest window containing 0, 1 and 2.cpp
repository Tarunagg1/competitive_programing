// Smallest window containing 0, 1 and 2 
// Easy Accuracy: 69.8% Submissions: 1530 Points: 2
// Given a string S consisting of the characters 0, 1 and 2. Your task is to find the length of the smallest substring of string S that contains all the three characters 0, 1 and 2. If no such substring exists, then return -1.

// Example 1:

// Input:
// S = "01212"
// Output:
// 3
// Explanation:
// The substring 012 is the smallest substring
// that contains the characters 0, 1 and 2.
// Example 2:

// Input: 
// S = "12121"
// Output:
// -1
// Explanation: 
// As the character 0 is not present in the
// string S, therefor no substring containing
// all the three characters 0, 1 and 2
// exists. Hence, the answer is -1 in this case.
// Your Task:
// Complete the function smallestSubstring() which takes the string S as input, and returns the length of the smallest substring of string S that contains all the three characters 0, 1 and 2.

// Expected Time Complexity: O(|S|)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ |S| ≤ 105
// All the characters of String S lies in the set {'0', '1', '2'}

// View Bookmarked Problems



class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int i=0, j=0, n = S.length(), len = INT_MAX;
        
        int count0 = 0, count1 = 0, count2 = 0;
        while(j<n){
            if(count0 and count1 and count2){
                len = min(len, j-i);
                if(S[i] == '0')
                    count0--;
                if(S[i] == '1')
                    count1--;
                if(S[i] == '2')
                    count2--;
                i++;
            }
            else{
                if(S[j] == '0')
                    count0++;
                if(S[j] == '1')
                    count1++;
                if(S[j] == '2')
                    count2++;
                j++;
            }
        }
        while(i<n){
            if(count0 and count1 and count2)
                len = min(len, j-i);
            if(S[i] == '0')
                count0--;
            if(S[i] == '1')
                count1--;
            if(S[i] == '2')
                count2--;
            i++;
        }
        return len == INT_MAX ? -1:len; 
    }
};