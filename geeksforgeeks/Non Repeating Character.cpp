/*

Given a string S consisting of lowercase Latin Letters. Find the first non-repeating character in S.

Example 1:

Input:
S = hello
Output: h
Explanation: In the given string, the
first character which is non-repeating
is h, as it appears first and there is
no other 'h' in the string.
Example 2:

Input:
S = zxvczbtxyzvy
Output: c
Explanation: In the given string, 'c' is
the character which is non-repeating. 
Your Task:
You only need to complete the function nonrepeatingCharacter() that takes string S as a parameter and returns the character. If there is no non-repeating character then return '$' .

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).
Note: N = |S|

*/

char nonrepeatingCharacter(string s)
    {
       //Your code here
       int chars = 256;
       int n = (int)s.size();
       
       int arr[chars];
       fill(arr,arr+chars,0);
       
       for(int i=0; i<n; i++){
           arr[s[i]]++;
       }
       
       for(int i=0; i<n; i++){
           if(arr[s[i]] == 1)
               return (char)s[i];
       }
       return '$';
    }








