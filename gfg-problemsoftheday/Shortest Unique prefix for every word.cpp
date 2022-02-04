// Shortest Unique prefix for every word 
// Hard Accuracy: 84.34% Submissions: 3239 Points: 8
// Given an array of words, find all shortest unique prefixes to represent each word in the given array. Assume that no word is prefix of another.

// Example 1:

// Input: 
// N = 4
// arr[] = {"zebra", "dog", "duck", "dove"}
// Output: z dog du dov
// Explanation: 
// z => zebra 
// dog => dog 
// duck => du 
// dove => dov 
// Example 2:

// Input: 
// N = 3
// arr[] =  {"geeksgeeks", "geeksquiz",
//                        "geeksforgeeks"};
// Output: geeksg geeksq geeksf
// Explanation: 
// geeksgeeks => geeksg 
// geeksquiz => geeksq 
// geeksforgeeks => geeksf
// Your task:
// You don't have to read input or print anything. Your task is to complete the function findPrefixes() which takes the array of strings and it's size N as input and returns a list of shortest unique prefix for each word
 
// Expected Time Complexity: O(N*length of each word)
// Expected Auxiliary Space: O(N*length of each word)
 
// Constraints:
// 1 ≤ N, Length of each word ≤ 1000
// View Bookmarked Problems
// Company Tags






class TrieNode{
public:
    TrieNode* children[26];
    int used=0;
    TrieNode(){
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }
};

class Solution
{
    private:
    TrieNode* root;
    void insertString(string s){
        TrieNode* curr=root;
        for(char x:s){
            int idx=x-'a';
            if(!curr->children[idx])
                curr->children[idx]= new TrieNode();
            curr->used++;
            curr=curr->children[idx];
        }
    }
    string getUniquePrefixes(string& s){
        TrieNode* curr=root;
        string toReturn="";
        for(char x:s){
            int idx=x-'a';
            if(curr->used==1) break;
            toReturn+=x;
            curr=curr->children[idx];
        }
        return toReturn;
    }
    
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        //code here
        root=new TrieNode();
        vector<string> ans;
        for(int i=0;i<n;i++)
            insertString(arr[i]);
        for(int i=0;i<n;i++)
            ans.push_back(getUniquePrefixes(arr[i]));
        return ans;
    }
    
};























