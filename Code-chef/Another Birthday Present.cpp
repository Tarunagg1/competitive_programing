// Contest Code:PRACTICE Problem Code:SHUFFLE
// Read problem statements in Hindi, Bengali, Mandarin Chinese, Russian, and Vietnamese as well.
// Chef got another sequence as a birthday present. He does not like this sequence very much because it is not sorted. Since you are a good programmer, Chef is asking for your help.

// You are given a sequence A1,A2,…,AN and an integer K. You may perform any number of operations of the following type (in any order): choose a valid integer i and swap Ai with Ai+K. Can you sort the sequence this way?

// Input
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first line of each test case contains two space-separated integers N and K.
// The second line contains N space-separated integers A1,A2,…,AN.
// Output
// For each test case, print a single line containing the string "yes" if the sequence can be sorted or "no" otherwise (without quotes).

// Constraints
// 1≤T≤100
// 1≤K≤N≤105
// 1≤Ai≤109 for each valid i
// the sum of N over all test cases does not exceed 106
// Subtasks
// Subtask #1 (50 points): the sequence A is a permutation of the integers 1 through N
// Subtask #2 (50 points): original constraints

// Sample Input 1 
// 2
// 4 1
// 1 4 2 3
// 4 2
// 1 4 2 3
// Sample Output 1 
// yes
// no
// Explanation
// Example case 1: We may freely swap adjacent elements, so the sequence can be sorted e.g. in the following way: (1,4,2,3)→(1,2,4,3)→(1,2,3,4)


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    
	    for(int i=0; i<n; i++)
	        cin>>arr[n];
	  
	   int brr[n];
	   
	   for(int i=0; i<k; i++){
	       int j=0;
	       
	       for(int p=i; p<n; p+=k){
	           brr[j++]=arr[p];
	       }
	       
	       sort(brr,brr+j);
	       j=0;
	       
	       for(int p=i; p<n; p+=k){
	           arr[p] = brr[j++];
	       }
	   }
	   
	   int flag = 0;
	   
	   for(int i=1; i<n; i++){
	       if(arr[i] < arr[i-1]){
	           flag = 1;
	           break;
	       }
	   }
	   
	   if(flag == 1){
            cout<<"no"<<endl;
	   }else{
	       cout<<"yes"<<endl;
	   }
	    
	}
	return 0;
}





























