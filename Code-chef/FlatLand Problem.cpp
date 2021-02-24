/* 
In the 2-D world of Flatland, the Circles were having their sports day and wanted to end it with a nice formation. So, they called upon Mr. Sphere from Spaceland for help. Mr Sphere decides to arrange the Circles in square formations. He starts with N Circles and forms the largest possible square using these Circles. He then takes the remaining Circles and repeats the procedure. A square of side S requires S2 Circles to create.

Find the number of squares he will be able to form at the end of the process.

Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single integer N.
Output:
For each testcase, output a single integer denoting the number of squares.

Constraints
1≤T≤1000
1≤N≤1000
Sample Input:
2
85
114

Sample Output:
2
4
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,c=0;
		cin>>n;
		while(n!=0)
		{
			float k = (sqrt(n));
			k=round(k);
			//cout<<k;
			if((k*k)>n)
				k=k-1;
			n = n-(k*k);
			//cout<<n;
			c++;
		}
		cout<<c<<"\n";
	}
	return 0;
}