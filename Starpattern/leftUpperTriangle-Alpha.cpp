#include<iostream>

using namespace std;

// A
// BA
// CAB
// DCBA



int main(){
    char c = 'A';
    for(int i=1; i<=4; i++){
        c=64+i;
        for(int j=1; j<=4; j++){
            if(j<=i){
                cout<<c;
                c--;
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}



