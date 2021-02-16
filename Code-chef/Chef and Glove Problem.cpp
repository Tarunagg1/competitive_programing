/////////////////////////////// Chef and Glove Problem Code: CHEGLOVE
#include<iostream>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int len[n+1];
        int glov[n+1];
        for(int i=1; i<=n; i++){
           cin>>len[i];
        }
        for(int i=1; i<=n; i++){
           cin>>glov[i];
        }
        //// front
            int front = 0;
            int rear = 0;
        for(int i=1; i<=n; i++){
            if(len[i] <= glov[i]){
                front++;
            }
        }
        for(int i=1; i<=n; i++){
            if(len[i] <= glov[n+1-i]){
                rear++;
            }
        }

        if(front == n && rear == n){
            cout<<"both"<<endl;
        }else if(front != n && rear != n){
            cout<<"none"<<endl;
        }else if(front == n && rear != n){
            cout<<"front"<<endl;
        }else if(front != n || rear == n){
            cout<<"back"<<endl;
        }
    }
   return 0;
}