// Read problems statements in Mandarin Chinese,Vietnamese, and Bengali as well.
// Today is Chef's birthday and he is looking forward to his gift. As usual, the gift is hidden and Chef has to follow a sequence of N instructions to reach it.

// Initially, Chef is standing in the cell (0,0) of a two-dimensional grid. The sequence of instructions is given as a string S. If we denote Chef's current cell by (x,y), each character of S corresponds to an instruction as follows:

// 'L' means to go left, i.e. to the cell (x−1,y)
// 'R' means to go right, i.e. to the cell (x+1,y)
// 'U' means to go up, i.e. to the cell (x,y+1)
// 'D' means to go down, i.e. to the cell (x,y−1)
// In addition, Chef should never perform multiple consecutive moves along the same axis of the grid. If there are multiple consecutive instructions to move along the same axis (left/right or up/down), he should perform only the first of these moves.

// Find the cell (xg,yg) which contains the hidden gift.

// Input
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first line of each test case contains a single integer N.
// The second line contains a single string S with length N.
// Output
// For each test case, print a single line containing two space-separated integers xg and yg.

// Constraints
// 1≤T≤100
// 1≤N≤1,000
// S contains only characters 'L', 'R', 'U' and 'D'
// Sample Input 1 
// 3
// 5
// LLLUR
// 7
// LLLRUUD
// 8
// LRULLUDU
// Sample Output 1 
// 0 1
// -1 1
// -2 2
// Explanation
// Example case 1: Chef's path is (0,0)→(−1,0)→(−1,0)→(−1,0)→(−1,1)→(0,1).



#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    string str;
	    cin>>str;
	    
	    int x=0;
	    int y=0;
	    char cc;
	    
	    if(str[0] == 'L'){
	        x-=1;
	        cc='L';
	    }else if(str[0] == 'R'){
	        cc='R';
	        x+=1;
	    }else if(str[0] == 'U'){
	        y+=1;
	        cc='U';
	    }else{
	        y-=1;
	        cc='D';
	    }
	    
	    for(int i=1; i<n; i++){
	        if(cc == 'L' && cc == 'R'){
	            if(str[i] == 'U'){
	                y+=1;
	                cc='U';
	            }else if(str[i] = 'D'){
	                y-=1;
	                cc='D';
	            }
	        }else{
	             if(str[i] == 'L'){
	                x-=1;
	                cc='L';
	            }else if(str[i] = 'R'){
	                x+=1;
	                cc='R';
	            }
	        }
	    }
	    cout<<x<<" "<<y<<endl;
	}
	
	return 0;
}
































