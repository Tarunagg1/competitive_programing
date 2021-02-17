////////////////////////////////////////////// Making a Meal Problem Code: CFMM
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int bowl[26] = {0};
        for(int i=0; i<n; i++){
           string s;cin>>s;
           for(int j=0; j<s.size(); j++){
              int x = s[j]-97;
              bowl[x]++;
           }

        }
        vector<int> v;
        v.push_back(bowl[2]/2);  // fro 'c'
        v.push_back(bowl[3]/1); // for 'd'
        v.push_back(bowl[4]/2);  // for 'e'
        v.push_back(bowl[5]/1);  //for 'f'
        v.push_back(bowl[7]/1);  //for 'h'
        v.push_back(bowl[14]/1);  //for 'o'

        sort(v.begin(),v.end());
        cout<<v[0]<<endl;
    }
   return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int bowl[26] = {0};
        for(int i=0; i<n; i++){
           string s;cin>>s;
           for(int j=0; j<s.size(); j++){
              int x = s[j]-97;
              bowl[x]++;
           }

        }
        vector<int> v;
        v.push_back(bowl[2]/2);  // fro 'c'
        v.push_back(bowl[3]/1); // for 'd'
        v.push_back(bowl[4]/2);  // for 'e'
        v.push_back(bowl[5]/1);  //for 'f'
        v.push_back(bowl[7]/1);  //for 'h'
        v.push_back(bowl[14]/1);  //for 'o'

        sort(v.begin(),v.end());
        cout<<v[0]<<endl;
    }
   return 0;
}

