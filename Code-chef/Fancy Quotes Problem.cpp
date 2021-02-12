#include<iostream>
#include<sstring>

using namespace std;
//Fancy Quotes Problem Code: FANCY

#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		getline(cin>>ws,s); 
		bool flag=false;string word="";
		 for(auto x: s){
		 	if(x==' '){
		 		 if(word=="not"){flag=true;break;}word="";
		 	}else{
		 		word+=x;
		 		
		 	}
		 }
		 if(s=="not" || word=="not"){
		 	cout<<"Real Fancy"<<endl;
		 }
		else if(flag  ){
			cout<<"Real Fancy"<<endl;
		}
		else{
			cout<<"regularly fancy"<<endl;
		}
	}
}

