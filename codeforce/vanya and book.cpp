/*

B. Vanya and Books
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vanya got an important task — he should enumerate books in the library and label each book with its number. Each of the n books should be assigned with a number from 1 to n. Naturally, distinct books should be assigned distinct numbers.

Vanya wants to know how many digits he will have to write down as he labels the books.

Input
The first line contains integer n (1 ≤ n ≤ 109) — the number of books in the library.

Output
Print the number of digits needed to number all the books.

Examples
input
13
output
17
input
4
output
4
Note
Note to the first test. The books get numbers 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, which totals to 17 digits.

Note to the second sample. The books get numbers 1, 2, 3, 4, which totals to 4 digits.
*/

#include<iostream>
#include<math.h>

using namespace std;

int main(){
  long long int n;cin>>n;
  long long  int arr[13] = {0};
  for(int i=1; i<13; i++){
    arr[i] = pow(10,i)-1;
  }
  for(int i=2; i<13; i++){
    for(int j=1; j<=i-1; j++){
        arr[i] = arr[i] - arr[j];
    }
  }
  long long Count = 0;
  for(int i=1; i<13; i++){
    if(n-arr[i] >=0 ){
        Count += arr[i] * i;
        n -= arr[i];
    }else{
        Count += n*i;
        break;
    }
  }
  cout<<Count<<endl;
  return 0;
}
