
// Rank The Permutations 
// Medium Accuracy: 49.42% Submissions: 2389 Points: 4
// Given a string, find the rank of the string amongst its permutations sorted lexicographically. 

// Example 1:

// Input:
// S = "abc"
// Output:
// 1
// Explanation:
// The order permutations with letters 
// 'a', 'c', and 'b' : 
// abc
// acb
// bac
// bca
// cab
// cba
// Example 2:

// Input:
// S = "acb"
// Output:
// 2

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findRank() which takes the string S as input parameter and returns the rank of the string amongst its permutations.
// It is guaranteed no characters are repeated in the string.


// Expected Time Complexity: O(|S|*26)
// Expected Auxiliary Space: O(|S|)
// Note: |S| represents the length of string S.


// Constraints:
// 1 ≤ |S| ≤ 18

// View Bookmarked Problems



class Solution{
  public:
  long long fact(int n){
     if(n==0||n==1)return n;
     return n*fact(n-1);
 }
 
    long long findRank(string str) {
        //code here
        string temp=str;
       int i=0;
       long long ans=1;
       sort(temp.begin(),temp.end());
       while(i!=str.size()){
           for(int j=0;j<temp.size();j++){
               if(temp[j]==str[i]){  //////if match the charector then go forward 
                   temp=temp.substr(0,j)+temp.substr(j+1);
                   i++;
                   break;
               }
               else{
                   ans+=fact(temp.size()-1);  ///if not match then add factorial in ans
               }
           }
       }
       return ans;
    }
};





























