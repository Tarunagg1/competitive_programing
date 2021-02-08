#include <iostream> 

using namespace std;

int main(){
   int n;
   cin>>n;
   for(int i=0; i<n; i++){
     int num;
     int num2;
     cin>>num>>num2;
     cout<<num%num2<<endl;
   }
   return 0;
}
