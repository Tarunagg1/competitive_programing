// Problem
// Joe has been burdened by the assignments given and continuous evaluations taken by his profs.He wants to go for a trip over this weekend, but he has an assignment.

// Help Joe in his assignment, the problem statement for the assignment is - 

//     You are given two integers n and m , further you are given a sequence of n numbers.

//     Now for several query lets say q number of queries, for each query input lets denote it with x, find the maximum value of (a[i] + x) % m possible.

//     Note - a[i] is the i-th element of the sequence.

// Input Format -

//     First line of input contains an integer , n ,denoting the size of the array, and an integer m.

//     Second line contains n space separated integers of the array.

//     Third line contains the number of queries,q.

//     Next q lines contain a query value x, for which we need to find the output. 

// Output Format -

//     For each query return the maximum value of (a[i]+value of q)%m possible, in separate line.


// Constraints -

//     1 ≤ n ≤ 10^5

//     1 ≤ m ≤ 10^8

//     0 ≤  a[i] ≤ 10^15

//     1 ≤ q ≤ 10^5

//     0 ≤ x ≤ 10^15

// Sample Input
// 5 10
// 0 1 2 3 4
// 3
// 1
// 6
// 9
// Sample Output
// 5
// 9
// 9

// Time Limit: 2
// Memory Limit: 256
// Source Limit:


#include <stdio.h>
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
long long a[N];

int main(){
    int n,m;
    cin>>n>>m;

    for (int i = 0; i < n; i++)
    {   
       cin>>a[i];
       a[i] %= m;
    }

    sort(a,a+n);
    int q;
    cin>>q;

    while (q--)
    {
        long long x;
        cin>>x;
        x %= m;

        long long *ptr = upper_bound(a,a+n,m-x-1);
        if(ptr != a){
            ptr--;
        }
        cout<<max((a[n-1] + x) % m, (*ptr+x) % m)<<endl;
    }
    
    
}













