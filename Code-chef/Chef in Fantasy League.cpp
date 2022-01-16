// Contest Code:PRACTICE Problem Code:FFL
// Read problem statements in Hindi, Bengali, Mandarin Chinese, Russian, and Vietnamese as well.
// Chef is going to start playing Fantasy Football League (FFL) this season. In FFL, each team consists of exactly 15 players: 2 goalkeepers, 5 defenders, 5 midfielders and 3 forwards. Chef has already bought 13 players; he is only missing one defender and one forward.

// There are N available players (numbered 1 through N). For each valid i, the i-th player is either a defender or a forward and has a price Pi. The sum of prices of all players in a team must not exceed 100 dollars and the players Chef bought already cost him S dollars.

// Can you help Chef determine if he can complete the team by buying one defender and one forward in such a way that he does not exceed the total price limit?

// Input
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first line of each test case contains two space-separated integers N and S.
// The second line contains N space-separated integers P1,P2,…,PN.
// The last line contains N space-separated integers. For each valid i, the i-th of these integers is 0 if the i-th player is a defender or 1 if the i-th player is a forward.
// Output
// For each test case, print a single line containing the string "yes" if it is possible to build a complete team or "no" otherwise (without quotes).

// Constraints
// 1≤T≤100
// 1≤N≤100
// 13≤S≤100
// 1≤Pi≤100 for each valid i
// Subtasks
// Subtask #1 (100 points): original constraints

// Sample Input 1 
// 2
// 4 90
// 3 8 6 5
// 0 1 1 0
// 4 90
// 5 7 6 5
// 0 1 1 0
// Sample Output 1 
// yes
// no
// Explanation
// Example case 1: If Chef buys the 1-st and 3-rd player, the total price of his team is 90+9=99, which is perfectly fine. There is no other valid way to pick two players.

// Example case 2: Chef cannot buy two players in such a way that all conditions are satisfied.


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n,s;
	    cin>>n>>s;
	    int arr[n];
	    
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    
	    int type[n];
	    
	    for(int i=0; i<n; i++){
	        cin>>type[i];
	    }
	    
	    int min0=100000,min1=100000;
	    
	    for(int i=0; i<n; i++){
	        if(type[i] == 0){
	            if(min0 > arr[i]){
	                min0 = arr[i];
	            }
	        }else{
	            if(min1 > arr[i]){
	                min1 = arr[i];
	            }
	        }
	    }
	    
	    if(s+min1+min0 > 100){
	        cout<<"no"<<endl;
	    }else{
	        cout<<"yes"<<endl;
	    }
	    
	}
	
	return 0;
}


























