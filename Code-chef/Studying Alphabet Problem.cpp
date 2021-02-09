#include<iostream>

using namespace std;

/// Studying Alphabet Problem Code: ALPHABET

int main(){
  string s;
  cin>>s;
  int n;
  cin>>n;
  int arr[26] = {0};
  for(int i=0; i<s.length(); i++){
    char sk = s[i];
    int num = int(sk);
    arr[num-97] = 1;
  }
  while(n--){
    string skk;
    cin>>skk;
    int len = skk.length();
    int countt = 0;
    for(int i=0; i<len; i++){
       char r = skk[i];
       int ascii = int(r);
       if(arr[ascii-97]){
            countt++;
       }
    }
    if(len == countt){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
  }
  return 0;
}











