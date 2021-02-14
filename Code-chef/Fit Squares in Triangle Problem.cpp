#include<iostream>
#include<sstream>

using namespace std;
////////////////////  Fit Squares in Triangle Problem Code: TRISQ
int main(){
   int t;cin>>t;
   while(t--){
     int b;
     cin>>b;
     if(b == 1 || b==2 || b==3){
        cout<<"0"<<endl;
     }else{
        if(b%2 == 0){
            // even
            int area = 0.5 * b*b;
            int res = (area-b) /4;
            cout<<res<<endl;
         }else{
            /// odd
            b=b-1;
            int area = 0.5 * b*b;
            int res = (area-b) /4;
            cout<<res<<endl;
         }
     }
   }
} 