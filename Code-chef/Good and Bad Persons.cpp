#include<iostream>

using namespace std;
// Good and Bad Persons Problem Code: GOODBAD

int main(){
   int n;
   cin>>n;
   while(n--){
      int ssize;
      int k;
      string str;

      cin>>ssize;
      cin>>k;
      cin>>str;
      int cap = 0;
      int small = 0;

      for(int i=0; i<ssize; i++){
        char x = str[i];
        int p = int(x);
        /// cap == 65 ---> 90
        /// small == 97 ----> 122
        //////////// count no of small and capital letter
        if(p>=65 && p<=90){
            cap++;
        }else{
            small++;
        }
      }

        if(cap==small){
            if(k>=cap){
                cout<<"both"<<endl;
            }else if(k<cap){
                cout<<"none"<<endl;
            }
        }else if(small > cap){
            if(k>=small){
                cout<<"both"<<endl;
            }else if(k<cap){
                cout<<"none"<<endl;
            }else{
                cout<<"chef"<<endl;
            }
        }else if(cap >small){
            if(k>=cap){
                cout<<"both"<<endl;
            }else if(k<small){
                cout<<"none"<<endl;
            }else{
                cout<<"brother"<<endl;
            }
        }
   }
}
