//////////////////////////////////////////// The Great Run Problem Code: PROC18A
#include <iostream>
using namespace std;


int main(){
    int t;cin>>t;
    while(t--){
        int n,l;
        cin>>n;cin>>l;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int max = 0;
        for(int i=0; i<=n-l; i++){
            int sum = 0;
            for(int j=i; j<i+l; j++){
                sum +=arr[j];
            }
            if(max<sum)
                max = sum;
        }
        cout<<max<<endl;
    }
}

