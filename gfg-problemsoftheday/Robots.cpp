// Robots 
// Medium Accuracy: 51.49% Submissions: 3641 Points: 4
// There are two kinds of bots A and B in a 1-D array. A bot can only move left while B can only move right. There are also empty spaces in between represented by #. But its also given that the bots cannot cross over each other.

// Given the initial state and final state, we should tell if the transformation is possible.

// NOTE: There can be many bots of the same type in a particular array. 


// Example 1:

// Input:
// s1 = #B#A#
// s2 = ##BA#
// Output: Yes
// Explanation: Because we can reach the 
// final state by moving 'B' to the 
// right one step.

// Example 2:

// Input:
// s1 = #B#A#
// s2 = #A#B# 
// Output: No
// Explanation: Because the robots 
// cannot cross each other.


// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function moveRobots() which takes the initial and final states as strings s1 and s2 respectively and returns if a valid transformation can be done. Return "Yes" if possible, else "No".

 

// Expected Time Complexity: O(|s1|)
// Expected Auxiliary Space: O(|s1|)

 

// Constraints:
// 1 <= |s1| = |s2| <= 105
// The strings only consists of 'A', 'B' and '#'.


class Solution{   
public:
    string moveRobots(string s1, string s2){
        // code here 
        int i=0,j=0,n=s1.length();
        
        while(i<n && j<n){
            if(s1[i] == '#') i++;
            else if(s2[j] == '#') j++;
            else if(s1[i] != s2[j]) return "No";
            else if(s1[i] == 'B' && i>j) return "No";
            else if(s1[i] == 'A' && i<j) return "No";
            else{
                j++;
                i++;
            }
        }
        return "Yes";
    }
};





















