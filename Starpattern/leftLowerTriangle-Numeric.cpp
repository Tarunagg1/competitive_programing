#include<iostream>

using namespace std;

// 6543210
// 543210
// 43210
// 3210
// 210
// 10
// 0


int main(){
    int n = 7;
    int k=0;
    for(int i=1; i<=n; i++){
        k=7-i;
        for(int j=1; j<=n; j++){
            if(j<=8-i){
                cout<<k;
                k--;
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}



