// Contest Code:PRACTICE Problem Code:UNITGCD
// Read problem statements in Hindi, Bengali, Mandarin Chinese, Russian, and Vietnamese as well.
// Chef has a recipe book. He wishes to read it completely as soon as possible so that he could try to cook the dishes mentioned in the book.

// The pages of the book are numbered 1 through N. Over a series of days, Chef wants to read each page. On each day, Chef can choose to read any set of pages such that there is no prime that divides the numbers of two or more of these pages, i.e. the numbers of pages he reads on the same day must be pairwise coprime. For example, Chef can read pages 1, 3 and 10 on one day, since (1,3), (3,10) and (1,10) are pairs of coprime integers; however, he cannot read pages 1, 3 and 6 on one day, as 3 and 6 are both divisible by 3. Since chef might get bored by reading the same recipe again and again, Chef will read every page exactly once.

// Given N, determine the minimum number of days Chef needs to read the entire book and the pages Chef should read on each of these days.

// Input
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first and only line of each test case contains a single integer N.
// Output
// For each test case:

// First, print a line containing a single integer D ― the minimum number of days required to read the book. Let's number these days 1 through D.
// Then, print D lines describing the pages Chef should read. For each valid i, the i-th of these lines should contain an integer Ci followed by a space and Ci space-separated integers ― the numbers of pages Chef should read on the i-th day.
// If there are multiple solutions with the minimum number of days, you may print any one.

// Constraints
// 1≤T≤10
// 1≤N≤106
// Subtasks
// Subtask #1 (20 points): N≤100
// Subtask #2 (80 points): original constraints

// Example Input
// 1
// 5
// Example Output
// 2
// 3 1 2 5
// 2 3 4
// Explanation
// Example case 1:

// On the first day, Chef should read three pages: 1, 2 and 5.
// On the second day, Chef should read the remaining two pages: 3 and 4.
// There are other valid solutions as well.




#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    if(n == 1){
	        cout<<"1"<<endl;
	    }
	    else if(n == 2){
	        cout<<"1"<<endl;
	        cout<<"2 1 2"<<endl;
	    }
	    else if (n == 3){
	        cout<<"1"<<endl;
	        cout<<"3 1 2 3"<<endl;
	    }else{
	        int day = n/2;
	        if(n %2 == 0){
	            cout<<day<<endl;
	            for(int i=1; i<n; i++){
	                cout<<"2 "<<i<<" "<<i+1<<endl;
	            }
	        }else{
	            cout<<day<<endl;
	            cout<<"3 "<<"1 2 3"<<endl;
	            for(int i=4; i<n; i+=2){
	                cout<<"2 "<<i<<" "<<i+1<<endl;
	            }
	        }
	    }
	    
	}
	return 0;
}























