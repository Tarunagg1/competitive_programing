/*
A. MUH and Sticks
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Two polar bears Menshykov and Uslada from the St.Petersburg zoo and elephant Horace from the Kiev zoo got six sticks to play with and assess the animals' creativity. Menshykov, Uslada and Horace decided to make either an elephant or a bear from those sticks. They can make an animal from sticks in the following way:

Four sticks represent the animal's legs, these sticks should have the same length.
Two remaining sticks represent the animal's head and body. The bear's head stick must be shorter than the body stick. The elephant, however, has a long trunk, so his head stick must be as long as the body stick. Note that there are no limits on the relations between the leg sticks and the head and body sticks.
Your task is to find out which animal can be made from the given stick set. The zoo keeper wants the sticks back after the game, so they must never be broken, even bears understand it.

Input
The single line contains six space-separated integers li (1 ≤ li ≤ 9) — the lengths of the six sticks. It is guaranteed that the input is such that you cannot make both animals from the sticks.

Output
If you can make a bear from the given set, print string "Bear" (without the quotes). If you can make an elephant, print string "Elephant" (wıthout the quotes). If you can make neither a bear nor an elephant, print string "Alien" (without the quotes).

Examples
input
4 2 5 4 4 4
output
Bear
input
4 4 5 4 4 5
outputCopy
Elephant
input
1 2 3 4 5 6
output
Alien
Note
If you're out of creative ideas, see instructions below which show how to make a bear and an elephant in the first two samples. The stick of length 2 is in red, the sticks of length 4 are in green, the sticks of length 5 are in blue.
*/

#include<iostream>
using namespace std;

int main(){
    int arr[10] = {0};
    int a;
    for(int i=0; i<6; i++){
        cin>>a;
        arr[a]++;
    }
    int leg = 0;
    int legval = 0;
    for(int i=0; i<10; i++){
        if(arr[i] >= 4){
            leg = 1;
            legval = i;
            arr[i] = arr[i]-4;
            break;
        }
    }
    int body = 0;
    int bodyval = 0;
    for(int i=0; i<10; i++){
        if(arr[i] >= 1){
            body = 1;
            bodyval = i;
            arr[i] = arr[i]-1;
            break;
        }
    }

    int head = 0;
    int headval = 0;
    for(int i=0; i<10; i++){
        if(arr[i] >= 1){
            head = 1;
            headval = i;
            arr[i] = arr[i]-1;
            break;
        }
    }

    ////////////////// we got head body and leg value
    if(leg == 1 && body == 1 && head == 1){
        if(legval != headval && legval != bodyval && headval != bodyval){
            cout<<"Bear"<<endl;
        }else if(bodyval != headval && (legval != headval || legval != bodyval)){
            cout<<"Elephant";
        }else if(legval != headval && legval != bodyval && headval != bodyval){
            cout<<"Elephant";
        }else if(legval == headval && legval == bodyval && headval == bodyval){
            cout<<"Elephant";
        }
    }else{
        cout<<"Alien"<<endl;
    }
    return 0;
}


