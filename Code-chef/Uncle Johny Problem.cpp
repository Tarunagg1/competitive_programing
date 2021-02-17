////////////////////////////////Uncle Johny Problem Code: JOHNY
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
   int t;cin>>t;
   while(t--){
    int n;cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int x;cin>>x;
        v.push_back(x);
    }
    int uniqueval;cin>>uniqueval;
    int val = v[uniqueval-1];
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++){
        if(v[i] == val){
            cout<<i+1<<endl;
            break;
        }
    }
   }
   return 0;
}

