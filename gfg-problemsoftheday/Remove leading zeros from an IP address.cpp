// Remove leading zeros from an IP address 
// Medium Accuracy: 61.68% Submissions: 4716 Points: 4
// Given an IP address, remove leading zeros from the IP address. Note that our IP address here can be a little different. It can have numbers greater than 255. Also, it does not necessarily have 4 numbers. The count can be lesser/more.

// Example 1:

// Input:
// S = "100.020.003.400"
// Output: 100.20.3.400
// Explanation: The leading zeros are removed
// from 20 and 3.
// Example 2:

// Input: 
// S = "100.000.010.0999"
// Output: 100.0.10.999
// Explanation: The leading zeros are removed
// from 0, 10 and 999.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function newIPAdd() which takes the string S representing the IP address as input and returns a string representing the resultant IP address. 


// Expected Time Complexity: O(|S|).
// Expected Auxiliary Space: O(|S|).


// Constraints:
// 1<=|S|<=1000


class Solution
{
  public:
    string newIPAdd (string s)
    {
        //code here.
        string ans = "";
        
        s+=".";
        int n = s.length();
        int i=0;
        
        while(i<n){
            int j=i;
            
            while(s[j] != '.'){
                j++;
            }
            
            string temp = s.substr(i,j-i);
            
            int k=0;
            
            while(temp[k] == '0'){
                k++;
            }
            
            if(k == temp.length()){
                ans += '0';
            }else{
                ans += temp.substr(k);
            }
            ans += ".";
            i=j+1;
        }
        ans.pop_back();
        return ans;
    }
};











