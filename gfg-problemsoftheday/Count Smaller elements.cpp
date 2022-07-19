// Count Smaller elements
// HardAccuracy: 44.37%Submissions: 5931Points: 8
// Given an array Arr of size N containing positive integers. Count number of smaller elements on right side of each array.

// Example 1:

// Input:
// N = 7
// Arr[] = {12, 1, 2, 3, 0, 11, 4}
// Output: 6 1 1 1 0 1 0
// Explanation: There are 6 elements right
// after 12. There are 1 element right after
// 1. And so on.
// Example 2:

// Input:
// N = 5
// Arr[] = {1, 2, 3, 4, 5}
// Output: 0 0 0 0 0
// Explanation: There are 0 elements right
// after 1. There are 0 elements right after
// 2. And so on.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function constructLowerArray() which takes the array of integers arr and n as parameters and returns an array of integers denoting the answer.

// Expected Time Complexity: O(N*logN)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 106
// 0 ≤ Arri  ≤ 108

class Solution{
public:	
	void merge(vector<pair<int,int>> &v,vector<int> &ans,int left,int mid,int right)
{
        int i=left,j=mid+1,k=0;
        vector<pair<int,int>> temp(right-left+1);
        // sorting in descending order
        while(i<=mid && j<=right)
        {
            if(v[i].first>v[j].first)
            {
                ans[v[i].second]+=(right-j+1);
                temp[k++]=v[i++];
            }
            else
                temp[k++]=v[j++];
        }
        while(i<=mid)
            temp[k++]=v[i++];
        while(j<=right)
            temp[k++]=v[j++];
        k=0;
        for(i=left;i<=right;i++)
            v[i]=temp[k++];
    }
    void mergeSort(vector<pair<int,int>> &v,vector<int> &ans,int left,int right)
    {
        if(left<right)
        {
            int mid=left+(right-left)/2;
            mergeSort(v,ans,left,mid);
            mergeSort(v,ans,mid+1,right);
            merge(v,ans,left,mid,right);
        }
    }
	vector<int> constructLowerArray(int *arr, int n) {
	    // code here
	    vector<int> ans(n,0);
	    vector<pair<int,int>> v;
	    for(int i=0;i<n;i++)
	    {
	        v.push_back({arr[i],i});
	    }
	    mergeSort(v,ans,0,n-1);
	    return ans;
	}
};





































