#include<iostream>
#include<bits/stdc++.h>

using namespace std;


void display(int arr[],int n){
    for(int i=0; i<n; i++){
        cout << arr[i] <<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);

    display(arr,n);
}















