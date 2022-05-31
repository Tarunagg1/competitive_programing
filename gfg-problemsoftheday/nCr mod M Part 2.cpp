// nCr mod M | Part 2 
// Medium Accuracy: 16.24% Submissions: 1306 Points: 4
// Given 3 integers n, r and m. You task is to calculate nCr%m.
// Note: m is a square free number and largest prime factor of m <= 50.

 

// Example 1:

// Input: n = 5, r = 2, m = 98697
// Output: 10
// Explanation: 5C2 = 5!/(2!*3!) = 10%98697 = 10
// Example 2:

// Input: n = 3, r = 2, m = 98697
// Output: 3
// Explanation: 3C2 = 3!/(2!*1!) = 3%98697 = 3
 

// Your Task:
// You don't need to read or print anything. Your task is to complete the function nCrModM() which takes n, r and m as input parameter and returns nCr modulo m.
 

// Expected Time Complexity: O(m + logmn) 
// Expected Space Complexity: O(m)
 

// Constraints:
// 1 <= n <= r <= 109
// 1 <= m <= 105






class Solution {
public:
vector<int> findPrimeFactors(int n){
       set<int> factors;
       vector<int> ans;
       int c=2;
       while(n>1){
           if(n%c==0){
               factors.insert(c);
               n/=c;
           }
           else
               c++;
       }
       for(auto i:factors){
           ans.push_back(i);
       }
       return ans;
   }
   int findByCrt(const vector<int> x, const vector<int> r){
       const int kN=x.size();
       int min_x=0;
       while(true){
           bool found=true;
           for(int i=0;i<kN;i++){
               if(min_x%x[i]!=r[i]){
                   found=false;
                   break;
               }
           }
           if(found){
               return min_x;
           }
           min_x++;
       }
   }
   int rCnModP(int n, int r, int p){
       if(r==0||r==n){
           return 1;
       }
       int nCr[r+1];
       memset(nCr, 0, sizeof(nCr));
       nCr[0]=1;
       for(int i=1;i<=n;i++){
           for(int j=min(i,r);j>0;j--){
               nCr[j]=(nCr[j]+nCr[j-1])%p;
           }
       }
       return nCr[r];
   }
   int rCnModPrimeLucas(int n, int r, int p){
       if(r==0) {
           return 1;
       }
       return (rCnModPrimeLucas(n/p, r/p, p)*rCnModP(n%p, r%p, p))%p;
   }
   
int nCrModM(int n, int r, int m) {
    // Code here
    const auto primes=findPrimeFactors(m);
       vector<int> rem;
       for(const int p:primes){
           rem.push_back(rCnModPrimeLucas(n, r, p));
       }
       return findByCrt(primes, rem);
}
};

























