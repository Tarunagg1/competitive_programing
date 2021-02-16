#include<iostream>
#include<sstream>

using namespace std;

// Sum of Digits Problem Code: FLOW006

int main(){
  int n;
  cin>>n;
  int num;
  while(n--){
    int sum =0;
    cin>>num;
    ostringstream str1;
    str1<<num;
    string s = str1.str();
    for(int i=0; i<s.length(); i++){
        char x = s[i];
        int p = x;
        p -= 48;
        sum+=p;
    }
    cout<<sum;
  }
  return 0;
}
