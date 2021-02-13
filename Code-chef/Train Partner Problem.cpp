#include<iostream>
#include<sstring>

using namespace std;
//////////////////////////////////////////////// Train Partner Problem Code: ANKTRAIN

int main(){
    int n;cin>>n;
    while(n--){
        int in;
        cin>>in;
        if(in%8 == 0){
            cout<<in-1<<"SL"<<endl;
        }else if(in %8 == 7){
            cout<<in+1<<"SU"<<endl;
        }else if(in %8 == 1){
            cout<<in+3<<"LB"<<endl;
        }else if(in %8 == 4){
            cout<<in-3<<"LB"<<endl;
        }else if(in %8 == 5){
            cout<<in-3<<"MB"<<endl;
        }else if(in %8 == 2){
            cout<<in+3<<"MB"<<endl;
        }else if(in %8 == 6){
            cout<<in-3<<"UB"<<endl;
        }else if(in %8 == 3){
            cout<<in+3<<"UB"<<endl;
        }
    }
    return 0;
}