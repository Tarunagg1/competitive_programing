#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
   cout<<"Enter number of element in array"<<endl;
   int n;cin>>n;
   cout<<"Ener the subset size"<<endl;
   int k;cin>>k;
   int arr[n];
   cout<<"Enter the numbers"<<endl;
   for(int i=0; i<n; i++){
        cin>>arr[i];
   }
   for(int i=1; i<pow(2,n); i++){
        vector<int> v;
        int x = i;   // x = 8
        while(x > 0){
            int z = x%2;  // 0 0 0 1
            v.push_back(z);
            x = x /2;  // 4 2 1  0
        }

        int p = n- (int)v.size();
        //cout<<p<<" ";
        for(int j=1; j<=p; j++){
            v.push_back(0);
        }
        reverse(v.begin(),v.end());
        int count = 0 ;
        for(int j=0; j<v.size(); j++){
            if(v[j] == 1)
                count++;
        }
        if(count == k){
            for(int j=0; j<v.size(); j++){
                if(v[j] == 1){
                    cout<<arr[j]<<" ";
                }
            }
            cout<<endl;
            v.clear();
        }
   }

}
