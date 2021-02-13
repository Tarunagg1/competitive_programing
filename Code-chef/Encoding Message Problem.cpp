#include<iostream>
#include<sstream>

using namespace std;
////////////////////////////////// Encoding Message Problem Code: ENCMSG
int main(){
   int n;cin>>n;
   while(n--){
     int len;
     cin>>len;
     string s;
     cin>>s;

     //// first stem of incoding
     if(len%2 == 0){
        /// even
        for(int i=0; i<len; i+=2){
            char temp = s[i];
            s[i] = s[i+1];
            s[i+1] = temp;
        }
     }else{
         /// odd
        for(int i=0; i<len-1; i+=2){
            char temp = s[i];
            s[i] = s[i+1];
            s[i+1] = temp;
        }
     }

     ///////////// step encoding
        for(int i=0; i<len; i++){
            int index = s[i]-97;  // 1
            int res = 25-index;  // 24
            res+=97;
            char y = (char)res;
            cout<<y;
        }
        cout<<endl;
   }
}
