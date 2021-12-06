#include<iostream>
#include<unordered_set>


using namespace std;

int main(){
    unordered_set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(4);
    s.insert(3);
    s.insert(2);
    s.insert(1);

    // for(auto it=s.begin(); it!=s.end(); it++)
    //     cout<<(*it)<<endl;
  
    

    // s.clear();
    // cout<<s.size()<<endl;

    // cout<<s.count(10)<<endl;

}

