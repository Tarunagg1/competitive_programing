// Read problem statements in Hindi, Bengali, Mandarin Chinese, Russian, and Vietnamese as well.
// There are N people on a street (numbered 1 through N). For simplicity, we'll view them as points on a line. For each valid i, the position of the i-th person is Xi.

// It turns out that exactly one of these people is infected with the virus COVID-19, but we do not know which one. The virus will spread from an infected person to a non-infected person whenever the distance between them is at most 2. If we wait long enough, a specific set of people (depending on the person that was infected initially) will become infected; let's call the size of this set the final number of infected people.

// Your task is to find the smallest and largest value of the final number of infected people, i.e. this number in the best and in the worst possible scenario.

// Input
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first line of each test case contains a single integer N.
// The second line contains N space-seperated integers X1,X2,…,XN.
// Output
// For each test case, print a single line containing two space-separated integers ― the minimum and maximum possible final number of infected people.

// Constraints
// 1≤T≤2,000
// 2≤N≤8
// 0≤Xi≤10 for each valid i
// X1<X2<…<XN
// Subtasks
// Subtask #1 (10 points): N≤3
// Subtask #2 (90 points): original constraints

// Sample Input 1 
// 3
// 2
// 3 6
// 3
// 1 3 5
// 5
// 1 2 5 6 7
// Sample Output 1 
// 1 1
// 3 3
// 2 3
// Explanation
// Example case 1: The distance between the two people is 3, so the virus cannot spread and at the end, there will always be only one infected person.

// Example case 2: The distance between each two adjacent people is 2, so all of them will eventually get infected.

// Example case 3:

// In one of the best possible scenarios, the person at the position 1 is infected initially and the virus will also infect the person at the position 2.
// In one of the worst possible scenarios, the person at the position 5 is infected initially and the virus will also infect the people at the positions 6 and 7.




#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    int arr[n];
	    
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    
	    int diff[n];
	    
	    diff[0]=0;
	    
	    for(int i=1; i<n; i++){
	        diff[i] = arr[i] - arr[i-1];
	    }
	    
	    int min = 100 , max=-1,count=1;
	    
	    for(int i=1; i<n; i++){
	        if(diff[i] <= 2){
	            count++;
	        }else{
	            if(min > count){
	                min = count;
	            }
	            if(max < count)
	                max = count;
	           count = 1;
	        }
	    }
	    
	    if(min > count)
	        min = count;
	    if(max < count)
	        max = count;
	    cout<<min<<" "<<max<<endl;
	    
	}
	
	return 0;
}
















