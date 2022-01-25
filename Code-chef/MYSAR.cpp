// Read problems statements in Hindi, Mandarin Chinese, Russian, Vietnamese, and Bengali as well.
// This is an interactive problem.

// Joshua is hiding a sequence A1,A2,…,AN, where N is even. He wants to play a game with you. Your goal is to guess the sequence.

// First, Joshua tells you A1 and AN. Then, you should ask him queries. In each query, you choose four integers L1, R1, L2 and R2 such that 1≤L1<R1≤N and 1≤L2<R2≤N, and Joshua's answer is the maximum of AL1,AL1+1,…,AR1 minus the minimum of AL2,AL2+1,…,AR2.

// Can you find the sequence using no more than 2N queries?

// Interaction
// First, you should read a line containing three space-separated integers N, A1 and AN.
// Then you may ask queries. To ask a query:
// Print a line containing the character 'Q' followed by a space and four space-separated integers L1, R1, L2 and R2.
// Then, read a line containing one integer ― the answer to the query.
// When you think you know the sequence, print a single line containing the character '!' followed by a space and N space-separated integers A1,A2,…,AN describing your guess.
// Don't forget to flush the output after printing each line!

// Constraints
// 2≤N≤105
// N is even
// 1≤Ai≤109 for each valid i
// Example
// You                         Grader
//                             4 1 1
// Q 1 2 3 4
//                             1
// Q 3 4 1 3
//                             2
// ! 1 2 3 1
// Explanation
// Joshua has the sequence [1,2,3,1].

// For the first query, the maximum of A1,A2 is 2 and the minimum of A3,A4 is 1, so the answer to this query is 2−1=1.

// For the second query, the maximum of A3,A4 is 3 and the minimum of A1,A3 is 1, so the answer is 3−1=2.

// Finally, we correctly guess the sequence by printing "! 1 2 3 1".


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    int mod = 1000000007;
	    int B[n];
	    for(int i=0; i<n; i++)
	        cin>>B[i];
	    
	    int flag = 0;
	    for(int i=1; i<n; i++){
	        if((B[i-1] && B[i]) != B[i-1]){
	            cout<<"0"<<endl;
	            flag = i;
	            break;
	        }
	    }
	    
	    if(flag == 0){
	        int count = 0;
	        for(int i=0; i<n-1; i++){
	            int m = B[i];
	            while(m){
	                count += m && 1;
	                m >>= 1;
	            }
	        }
	        int result = 1;
	        
	        for(int i=0; i<count; i++){
	            result = (result *2)%mod;
	        }
	        cout<<result<endl;
	    }
	   
	}
	return 0;
}


















