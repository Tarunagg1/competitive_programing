// Read problem statements in Hindi, Bengali, Mandarin Chinese, Russian, and Vietnamese as well.
// Chef went to Australia and saw the destruction caused by bushfires, which made him sad, so he decided to help the animals by feeding them fruits. First, he went to purchase fruits from Pintu.

// Pintu sells M different types of fruits (numbered 1 through M). He sells them in N baskets (numbered 1 through N), where for each valid i, the i-th basket costs Pi and it contains fruits of type Fi. Chef does not have too much money, so he cannot afford to buy everything; instead, he wants to choose one of the M available types and purchase all the baskets containing fruits of that type.

// Help Chef choose the type of fruit to buy such that he buys at least one basket and the total cost of the baskets he buys is the smallest possible.

// Input
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first line of each test case contains two space-separated integers N and M.
// The second line contains N space-separated integers F1,F2,…,FN.
// The third line contains N space-separated integers P1,P2,…,PN.
// Output
// For each test case, print a single line containing one integer ― the minimum price Chef must pay.

// Constraints
// 1≤T≤1,000
// 1≤M,N≤50
// 1≤Fi≤M for each valid i
// 0≤Pi≤50 for each valid i
// Subtasks
// Subtask #1 (30 points): M=2
// Subtask #2 (70 points): original constraints

// Sample Input 1 
// 1
// 6 4
// 1 2 3 3 2 2
// 7 3 9 1 1 1
// Sample Output 1 
// 5
// Explanation
// Example case 1:

// The sum of all baskets with fruits of type 1 is 7.
// The sum of all baskets with fruits of type 2 is 5.
// The sum of all baskets with fruits of type 3 is 10.
// The sum of all baskets with fruits of type 4 is 0 because there are no such baskets.
// Chef can only choose fruits of type 1, 2 or 3. Therefore, the minimum price he has to pay is 5.

#include <iostream>
#include<cstring>
#include<climits>


using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    
	    int f[n],p[n];
	    for(int i=0; i<n; i++){
	        cin>>f[i];
	    }
	    for(int i=0; i<n; i++){
	        cin>>p[i];
	    }
	    
	    int freq[m+1];
	    bool avilable[m+1];
	    memset(avilable,false,sizeof(avilable));
	    memset(freq,false,sizeof(freq));
	       
	       for(int i=0; i<n; i++){
	           freq[f[i]]+=p[i];
	           avilable[f[i]] = true;
	       }
	       int min = INT_MAX;
	       
	       for(int i=0; i<=m; i++){
	           if(freq[i] < min && avilable[i] == true){
	               min = freq[i];
	           }
	       }
	       cout<<min<<endl;
	}
	return 0;
}






































