#include<iostream>
#include<sstream>

using namespace std;

// prenthesis problem

bool isBalancedParenthesis(string s){
    int n = s.size();
    stack<char> st;
    bool isbal = true;
    for(int i=0; i<n; i++){
        if(s[i] == '{' || s[i] == '(' || s[i] == '['){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            if(st.top() == '('){
                st.pop();
            }else{
                isbal = false;
                break;
            }
        }
         else if(s[i] == '}'){
            if(st.top() == '{'){
                st.pop();
            }else{
                isbal = false;
                break;
            }
        }
         else if(s[i] == ']'){
            if(st.top() == '['){
                st.pop();
            }else{
                isbal = false;
                break;
            }
        }
    }
    return isbal;
}

int main(){
   string s = "{[()]}";
   if(isBalancedParenthesis(s)){
        cout<<"balance"<<endl;
   }else{
      cout<<"not balance"<<endl;
   }
  return 0;
}