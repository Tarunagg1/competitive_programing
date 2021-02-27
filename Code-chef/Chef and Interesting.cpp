/*

Chef and Interesting Subsequences Problem Code: CHEFINSQ
 
Read problem statements in Hindi, Bengali, Mandarin Chinese, Russian, and Vietnamese as well.
Chef has a sequence A1,A2,…,AN. This sequence has exactly 2N subsequences. Chef considers a subsequence of A interesting if its size is exactly K and the sum of all its elements is minimum possible, i.e. there is no subsequence with size K which has a smaller sum.

Help Chef find the number of interesting subsequences of the sequence A.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and K.
The second line contains N space-separated integers A1,A2,…,AN.
Output
For each test case, print a single line containing one integer ― the number of interesting subsequences.

Constraints
1≤T≤10
1≤K≤N≤50
1≤Ai≤100 for each valid i
Subtasks
Subtask #1 (30 points): 1≤N≤20
Subtask #2 (70 points): original constraints

Example Input
1
4 2
1 2 3 4
Example Output
1
Explanation
Example case 1: There are six subsequences with length 2: (1,2), (1,3), (1,4), (2,3), (2,4) and (3,4). The minimum sum is 3 and the only subsequence with this sum is (1,2).
All submissions for this 

*/

#include <iostream>
#define ll long long
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

ll int gcd(ll int a,ll int b){
    if(b == 0){
        return 0;
    }else{
        return gcd(b,a%b);
    }
}

void nCr(int n, int r)
{
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;

    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = gcd(p, k);
            p /= m;
            k /= m;

            n--;
            r--;
        }
    }

    else
        p = 1;
     cout << p << endl;
}

int main(){
  int t;cin>>t;
  while(t--){
    vector<int> v;
    int n,k;cin>>n>>k;
    for(int i=0; i<n; i++){
        int x;cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int last_index_ofk = v[k-1];
    int count = 0;
    for(int i=0; i<n; i++){
        if(v[i] == last_index_ofk)
            count++;
    }
    int num = 0;
    for(int i=0; i<n; i++){
        if(v[i] == last_index_ofk)
            num++;
    }
    nCr(count,num);
  }
  return 0;
}



