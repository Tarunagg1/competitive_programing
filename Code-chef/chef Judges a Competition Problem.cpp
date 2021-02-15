#include<iostream>
#include<algorithm>
////////Chef Judges a Competition Problem Code: CO92JUDG

int main(){
  int t;cin>>t;
  while(t--){
    int n;cin>>n;
    int a[n]; // for alice
    int b[n]; // for bob;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    //// sort in arr
    sort(a,a+n);
    sort(b,b+n);
    int sumofa = 0;
    int sumofb = 0;
    for(int i=0; i<n-1; i++){
        sumofa = sumofa + a[i] ;
        sumofb = sumofb + b[i];
    }
    if(sumofa == sumofb){
        cout<<"Draw"<<endl;
    }
    else if(sumofa < sumofb){
        cout<<"Alice"<<endl;
    }else{
        cout<<"Bob"<<endl;
    }
  }
  return 0;
}
