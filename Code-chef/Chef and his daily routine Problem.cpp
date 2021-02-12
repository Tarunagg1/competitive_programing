#include<iostream>
#include<sstring>

using namespace std;
/////// Chef and his daily routine Problem Code: CHEFROUT
int main(){
  int n;
  cin>>n;
 int count = 0;
  while(n--){
    string s;
    cin>>s;
    for(int i=0; i<s.length()-1; i++){
        if(s[i] == 'C' ){
            if(s[i+1] == 'E' || s[i+1] == 'S' || s[i+1] =='C'){
                count++;
            }
        }else if(s[i] == 'E'){
            if(s[i+1] == 'S' || s[i+1] == 'E'){
                count++;
            }
        }else if(s[i] == 'S'){
            if(s[i+1] == 'S'){
                count++;
            }
        }
    }
    if(count == s.length()-1){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
  }
  return 0;
}
