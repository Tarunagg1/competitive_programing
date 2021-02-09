#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){
  vector<int> v;
  v.push_back(11);
  v.push_back(127);
  v.push_back(03);
  v.push_back(54);
  v.push_back(25);

  //sort(v.begin(),v.end());
  int k = (int) v.size();

  for(int i=0; i<k; i++){
    cout<<v[i]<<" ";
  }

  return 0;
}