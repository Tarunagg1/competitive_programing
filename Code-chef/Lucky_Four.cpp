#include<iostream>
#include<sstream>

using namespace std;

// Lucky Four Problem Code: LUCKFOUR
int main(){
  int t;cin>>t;
  while(t--){
    int n;cin>>n;

    ostringstream str1;
    str1<<n;
    string s = str1.str();

    int count = 0;
    int k = (int)s.size();
    for(int i=0; i<k; i++){
        if(s[i] == '4'){
            count++;
        }
    }
    cout<<count<<endl;
  }
  return 0;
}