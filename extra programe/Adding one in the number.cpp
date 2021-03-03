#include<iostream>
#include<vector>

using namespace std;

int main(){
  printf("Enter the size of vector");
  int n;cin>>n;
  vector<int> v;
  v.push_back(0);
  for(int i=0; i<n; i++){
    int x;cin>>x;
    v.push_back(x);
  }

  int k = (int)v.size()-1;
  if(v[k] < 9){
    v[k]++;
  }else{
    while(v[k] == 9){
        v[k] = 0;
        k--;
    }
    v[k]++;
  }

  int s = 0;
  for(int i=0; i<(int)v.size(); i++){
    if(v[i] != 0){
        s = i;
        break;
    }
  }

  for(int i=s; i<(int)v.size(); i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;

  return 0;
}



