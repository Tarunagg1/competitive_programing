// Chef, Chefina and Their Friendship Problem Code: CHEFSHIP
// Add problem to Todo list
// Submit
// Read problems statements in Hindi, Mandarin Chinese, Russian, Vietnamese, and Bengali as well.
// In Chefland, each person has their own non-empty personal string. When two people with personal strings T1 and T2 (possibly identical) become friends in Chefland, their strings are replaced by a new string S=T1+T1+T2+T2, where + denotes string concatenation.

// Chef recently became friends with Chefina. However, Chefina's personal string was her favourite and she got upset when it was replaced by S. She wanted her personal string back. Chef does not remember T1 and T2 now, he only knows S.

// Find the number of ways in which Chef can retrieve valid strings T1 and T2 from the given string S. It is also possible that Chef does not remember S correctly, in which case there is no way to retrieve T1 and T2.

// Input
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first and only line of each test case contains a single string S.
// Output
// For each test case, print a single line containing one integer ― the number of ways to retrieve T1 and T2 from S.

// Constraints
// 1≤T≤104
// 4≤|S|≤105
// |S| is divisible by 2
// S contains only lowercase English letters
// the sum of |S| over all test cases does not exceed 2⋅106
// Sample Input 1 
// 3
// abcd
// aaaa
// ababcdccdc
// Sample Output 1 
// 0
// 1
// 1
// Explanation
// Example case 1: There is no way to choose T1 and T2.

// Example case 2: Both T1 and T2 must be "a".




#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int count = 0;
	    int n = s.length();
	    for(int i=2; i<n; i++){
	        string t1 = s.substr(0,i/2);
	        string t2 = s.substr(i/2,i/2);
	        string t3 = s.substr(i,(n-i)/2);
	        string t4 = s.substr(i+(n-i)/2,(n-i)/2);
	        
	        if(t1 == t2 && t3 == t4)
	            count++;
	    }
	    cout<<count<<endl;
	}
	return 0;
}



















