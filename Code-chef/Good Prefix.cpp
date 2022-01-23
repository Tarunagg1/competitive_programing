// Contest Code:PRACTICE Problem Code:PRFXGD
// Read problem statements in Hindi, Bengali, Mandarin Chinese, Russian, and Vietnamese as well.
// Chef got a string S with length N as his birthday gift. A prefix of this string is good if each character occurs in it at most X times.

// Chef can delete at most K characters from this string. He wants to maximise the number of good prefixes in the resulting string. Can you help him?

// Input
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first line of each test case contains a single string S.
// The second line contains two space-separated integers K and X.
// Output
// For each test case, print a single line containing one integer ― the maximum number of good prefixes.

// Constraints
// 1≤T≤100
// 1≤N,X≤10,000
// |S|=N
// 0≤K≤10,000
// S contains only lowercase English letters
// Subtasks
// Subtask #1 (50 points): K=0
// Subtask #2 (50 points): original constraints

// Sample Input 1 
// 3
// abcdefagahai
// 0 1
// abcdefagahai
// 1 1
// abcdefagahai
// 2 1
// Sample Output 1 
// 6
// 7
// 8
// Explanation
// Example case 1: Chef cannot delete any characters and each character may occur only once in a good prefix, so there are only six good prefixes.


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    string str;
	    cin>>str;
	    
	    int k,x;
	    cin>>k>>x;
	    int count = 0;
	    int freq[26]={0};
	    
	    for(int i=0; i<str.length(); i++){
	        freq[str[i]-'a']++;
	        if(freq[str[i]-'a'] > x){
	            if(k>0){
	                freq[str[i]-'a']--;
	                k--;
	            }else{
	                break;
	            }
	        }else{
	            count++;
	        }
	    }
	    cout<<count<<endl;
	}
	
	return 0;
}
























