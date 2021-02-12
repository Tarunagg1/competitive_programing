#include<iostream>
#include<sstream>

using namespace std;

// print prime number to n number

int main(){
  int n;
  cin>>n;
  for(int i=2; i<=n; i++){
    bool isprime = true;
    int x = i;
    for(int j=2; j<x; j++){
       if(x%j == 0){
            isprime = false;
       }
    }
    if(isprime){
        cout<<x<<endl;
    }
  }
}
