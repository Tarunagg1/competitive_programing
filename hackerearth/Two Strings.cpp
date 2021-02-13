#include<iostream>
#include<sstring>

using namespace std;

//////////////////////////////////////////////////// Two Strings
int main(){
   int n;cin>>n;
   while(n--){
       int arr1[26] = {0};
       int arr2[26] = {0};
       string s1,s2;cin>>s1;cin>>s2;

       int ls1 = (int) s1.length();

       int count = 0;

        for(int i=0; i<ls1; i++){
            int x = s1[i]-97;
            int y = s2[i]-97;
            arr1[x]++;
            arr2[y]++;
        }
          ///////// we get a complete array a and b;

          for(int i=0; i<26; i++){
            if(arr1[i] != arr2[i]){
                count++;
            }
          }

        if(count == 0){
             cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
   }
   return 0;
}



