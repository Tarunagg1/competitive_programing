#include <iostream>
#include<vector>
////////////////////////////////  Chef and Eid Problem Code: EID
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
    sort(v.begin(),v.end());
    //////
    vector<int> diff;
    for(int i=0; i<n-1; i++){
        diff.push_back(v[i+1] -v[i]);
    }
    sort(diff.begin(),diff.end());
    cout<<diff[0]<<endl;
  }
  return 0;
}
