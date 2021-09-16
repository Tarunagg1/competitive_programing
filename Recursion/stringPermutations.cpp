#include <iostream>


using namespace std;


void printPremutation(string str,string permutation){
      if(str.length() == 0){
        cout <<permutation <<endl;
        return;
    }
    for(int i=0; i<str.size(); i++){
        char currcarr = str[i];
        string newstr = str.substr(i);
        printPremutation(newstr,permutation);
    }
}

int main(){
    printPremutation("ABC","");
}


