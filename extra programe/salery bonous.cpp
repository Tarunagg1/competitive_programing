/*
make a program that reast the saller name his/her fisxed salery and the sale total made by him or her in the month.
consider seller recive 15% over all products sold write a final salery (total) of this seller at the end of month with 2 decimal places

input
tarun
500.00
1230.00

output 
684.54

input 
sid
700.00
0.00

target of question ia:- precision

*/

///////////////////////// salery with bonous

#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    double sal;
    string name;
    double totalsale;
    cin>>name;cin>>sal;cin>>totalsale;
    double tot_benifit = sal + (0.15*totalsale);
    cout<<fixed<<setprecision(2)<<tot_benifit<<endl;
}



