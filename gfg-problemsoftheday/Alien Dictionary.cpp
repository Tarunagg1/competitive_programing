// Alien Dictionary
// Difficulty: HardAccuracy: 47.81%Submissions: 114K+Points: 8
// Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
// Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
 

// Examples :

// Input:  N = 5, K = 4, dict = {"baa","abcd","abca","cab","cad"}
// Output: 1
// Explanation: Here order of characters is 'b', 'd', 'a', 'c' Note that words are sorted and in the given language "baa" comes before "abcd", therefore 'b' is before 'a' in output.
// Similarly we can find other orders.
// Input: N = 3, K = 3, dict = {"caa","aaa","aab"}
// Output: 1
// Explanation: Here order of characters is 'c', 'a', 'b' Note that words are sorted and in the given language "caa" comes before "aaa", therefore 'c' is before 'a' in output.
// Similarly we can find other orders.
// Expected Time Complexity: O(N * |S| + K) , where |S| denotes maximum length.
// Expected Space Compelxity: O(K)


// Constraints:
// 1 ≤ N≤ 104
// 1 ≤ K ≤ 26
// 1 ≤ Length of words ≤ 50



class Solution {
  public:
       string ans;
    vector<bool> vis,cur;
    unordered_set<int> g[26]; // Graph
    
    void topological_sort(int r) {
        vis[r]=cur[r]=1;
        for(int i:g[r]) 
            if(!vis[i])
                topological_sort(i);
        
        ans=char(97+r)+ans;
        cur[r]=0;
    }
    
    string findOrder(string arr[], int N, int K) {
        ans="";
        vis.assign(26,0); 
        cur=vis;
      
         for(int i=1;i<N;i++) {
          string a=arr[i-1],b=arr[i];
          int l=0,n=min(a.size(),b.size());
          while(l<n && a[l]==b[l]) 
                l++;
          if(l!=n) g[a[l]-'a'].insert(b[l]-'a');
         }
      
       for(int i=0;i<K;i++)
            if(!vis[i])
                topological_sort(i);
        return ans;
    }
};






















