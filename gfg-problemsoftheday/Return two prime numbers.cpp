// Return two prime numbers 
// Hard Accuracy: 77.28% Submissions: 5248 Points: 8
// Given an even number N (greater than 2), return two prime numbers whose sum will be equal to given number. There are several combinations possible. Print only the pair whose minimum value is the smallest among all the minimum values of pairs and print the minimum element first.

// NOTE: A solution will always exist, read Goldbachs conjecture. 

// Example 1:

// Input: N = 74
// Output: 3 71
// Explaination: There are several possibilities 
// like 37 37. But the minimum value of this pair 
// is 3 which is smallest among all possible 
// minimum values of all the pairs.
// Example 2:

// Input: 4
// Output: 2 2
// Explaination: This is the only possible 
// prtitioning of 4.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function primeDivision() which takes N as input parameter and returns the partition satisfying the condition.

// Expected Time Complexity: O(N*log(logN))
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 104  


class Solution{
public:
    
    bool isPrime(int n){
        for(int i=0; i<=sqrt(n); i++){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }
    vector<int> primeDivision(int N){
        // code here
        bool primeno[N+1];
        memset(primeno,true,sizeof(primeno));
        
        for(int i=2; i*i<=N; i++){
            if(primeno[i] == true){
                for(int j=i*2; j<=N; j+=i){
                    primeno[j] = false;
                }
            }
        }
        
        for(int i=2; i<=N/2; i++){
            if(primeno[i] && primeno[N-i]){
                return {i,N-i};
            }
        }
        return {};
    }
};




















