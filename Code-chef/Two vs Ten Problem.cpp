#include<iostream>
#include<sstring>

using namespace std;
//// Two vs Ten Problem Code: TWOVSTEN

int main(){
    int n;
    cin>>n;
    while(n--){
        int num;
        cin>>num;
        if(num %10 == 0){
            cout<<"0"<<endl;
        }else if(num %5 == 0){
            cout<<"1"<<endl;
        }else{
            cout<<"-1"<<endl;
        }
    }
    return 0;
}
