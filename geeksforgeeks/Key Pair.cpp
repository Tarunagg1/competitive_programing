// Key Pair 
// Easy Accuracy: 49.96% Submissions: 33476 Points: 2
// Given an array Arr of N positive integers and another number X. Determine whether or not there exist two elements in Arr whose sum is exactly X.

// Example 1:

// Input:
// N = 6, X = 16
// Arr[] = {1, 4, 45, 6, 10, 8}
// Output: Yes
// Explanation: Arr[3] + Arr[4] = 6 + 10 = 16
// Example 2:

// Input:
// N = 5, X = 10
// Arr[] = {1, 2, 4, 3, 6}
// Output: Yes
// Explanation: Arr[2] + Arr[4] = 4 + 6 = 10
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function hasArrayTwoCandidates() which takes the array of integers arr, n and x as parameters and returns boolean denoting the answer.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ Arr[i] ≤ 105

 

class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    unordered_set<int,int> us;
	    
	    for(int i=0; i<n; i++){
	        us[arr[i]]++;
	    }
	    
	    for(auto itr=us.begin(); itr!=us.end(); itr++){
	        int key - itr->first;
	        int val - itr->second;
	        
	        int pair = x-key; 
	        
	        if(pair == key){
	            if(val > 1)
	                return true;
	        }else{
	            if(us.find(pair) != us.end())
	                return true
	        }
	        
	    }
	    return false;
	}
};


































