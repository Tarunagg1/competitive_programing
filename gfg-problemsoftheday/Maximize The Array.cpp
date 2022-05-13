// Maximize The Array 
// Medium Accuracy: 53.89% Submissions: 2790 Points: 4
// Given two integer arrays Arr1 and Arr2 of size N. Use the greatest elements from the given arrays to create a new array of size N such that it consists of only unique elements and the sum of all its elements is maximum.
// The created elements should contain the elements of Arr2 followed by elements of Arr1 in order of their appearance.


// Example 1:

// Input:
// N = 5
// Arr1 = {7, 4, 8, 0, 1}
// Arr2 = {9, 7, 2, 3, 6}
// Output: 9 7 6 4 8
// Explanation: 9, 7, 6 are from 2nd array
// and 4, 8 from 1st array.

// Example 2:

// Input: N = 4
// Arr1 = {6, 7, 5, 3}
// Arr2 = {5, 6, 2, 9} 
// Output: 5 6 9 7 
// Explanation: 5, 6, 9 are from 2nd array
// and 7 from 1st array.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function maximizeArray() which takes the array arr1[], arr2[] and n as input parameters and returns the desired array of integers.


// Expected Time Complexity: O(NlogN)
// Expected Auxiliary Space: O(N)


// Constraints:
// 1 <= N <= 105
// 0 <=| Arr1[i] |<= 109
// 0 <= |Arr2[i] |<= 109

// View Bookmarked Problems





class Solution {
public:
int binarySearch(vector<int>v,int k)
{
   int s=0;
   int e=v.size()-1;
   while(s<=e)
   {
       int mid=s+(e-s)/2;
       if(v[mid]==k)
       {
           return mid;
       }
       else if(v[mid]<k)
       {
           s=mid+1;
       }
       else{
           e=mid-1;
       }
   }
   return -1;
   
}

    vector<int> maximizeArray(int arr1[], int arr2[], int n) {
            // code here 
                 set<int>s;
          for(int i=0;i<n;i++)
          {
              s.insert(arr1[i]);
          }
          for(int i=0;i<n;i++)
          {
              s.insert(arr2[i]);
          }
          int count=1;
          set<int>::reverse_iterator it;
          vector<int>search;
          for(it=s.rbegin();it!=s.rend();it++)
          {
              search.push_back(*it);
              if(count==n)
              {
                  break;
              }
              count++;
          }
          sort(search.begin(),search.end());
          map<int,bool>m;
          vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(m[arr2[i]]!=true){
           int c=binarySearch(search,arr2[i]);
           if(c!=-1)
           {
               ans.push_back(arr2[i]);
           }
            }
            m[arr2[i]]=true;
        }
        for(int i=0;i<n;i++)
        {
           if(m[arr1[i]]!=true){
           int c=binarySearch(search,arr1[i]);
           if(c!=-1)
           {
               ans.push_back(arr1[i]);
           }
            }
            m[arr1[i]]=true;
            
        }
          return ans;
    }
};
























