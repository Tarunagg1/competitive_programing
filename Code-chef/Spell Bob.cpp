#include<iostream>

using namespace std;

//Spell Bob Problem Code: SPELLBOB
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        string s1;
        string s2;
        cin>>s1;
        cin>>s2;
        int a[3]={0};
        int countb=0;
        int counto =0;
        for(int i=0;i<3;i++){
            if(s1[i]=='b'||s2[i]=='b'){
                a[i]=1;
                countb++;
            }
        }
        if(countb<2){
            cout<<"no"<<endl;
        }
        else if(countb==2){
            int index;
            for(int i=0;i<3;i++){
                if(a[i]==0){
                    index=i;
                }
            }
            if(s1[index]=='o'||s2[index]=='o'){
                cout<<"yes"<<endl;
            }
            else{
                cout<<"no"<<endl;
            }
        }
        else{
            for(int i=0;i<3;i++){
                if(s1[i]=='o'||s2[i]=='o'){
                    counto++;
                }
            }
            if(counto==0){
                cout<<"no"<<endl;
            }
            else{
                cout<<"yes"<<endl;
            }
        }
    }
    return 0;
}