// Pairs of Non Coinciding Points 
// Medium Accuracy: 46.29% Submissions: 2109 Points: 4
// In a given cartesian plane, there are N points. We need to find the Number of Pairs of  points(A, B) such that

// Point A and Point B do not coincide.
// Manhattan Distance and the Euclidean Distance between the points should be equal.
// Note: Pair of 2 points(A,B) is considered same as Pair of 2 points(B ,A).
// Manhattan Distance = |x2-x1|+|y2-y1|
// Euclidean Distance   = ((x2-x1)^2 + (y2-y1)^2)^0.5, where points are (x1,y1) and (x2,y2).

 

// Example 1:

// Input:
// N = 2
// X = {1, 7}
// Y = {1, 5}
// Output:
// 0
// Explanation:
// None of the pairs of points have
// equal Manhatten and Euclidean distance.
// Example 2:

// Input:
// N = 3
// X = {1, 2, 1}
// Y = {2, 3, 3}
// Output:
// 2
// Explanation:
// The pairs {(1,2), (1,3)}, and {(1,3), (2,3)}
// have equal Manhatten and Euclidean distance.
 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function numOfPairs() which takes an Integer N and two arrays X, and Y of length N as input and returns the number of pairs with equal Manhattan and Euclidean Distance. (X[i], Y[i]) denotes a point.

 

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

 

// Constraints:
// 1 <= N <= 105
//  -10^9 <= X[i], Y[i] <= 10^9

// View Bookmarked Problems
// Topic Tags


class Solution {
  public:
    int numOfPairs(int X[], int Y[], int N) {
        // code here
               // Eucledian distance is equal Manhattan distance if and only if x1 = x2 or y1 = y2
       map<int,vector<int>>mp1;  // Storing the frequency of similar x 
       map<int,vector<int>>mp2;  // Storing the frequency of similar y
       map<pair<int,int>,int>mp3;  // Storing the frequency of similar (x,y)
       for(int i = 0; i < N; i++){
           mp1[X[i]].push_back(Y[i]);
           mp2[Y[i]].push_back(X[i]);
           mp3[{X[i],Y[i]}]++;
       }
       int cnt = 0;
       for(auto it : mp1){
           vector<int>temp = it.second;    
           int size = temp.size();
           cnt += ((size)*(size-1))/2;  // Finding the count of pairs having similar x
       }
       for(auto it : mp2){
           vector<int>temp = it.second;
           int size = temp.size();
           cnt += ((size)*(size-1))/2;   // Finding the count of pairs having similar y
       }
       int temp = 0;
       for(auto it : mp3){
           temp += ((it.second)*(it.second-1))/2;  // Finding the count of pairs having similar (x,y)
       }
       return cnt - 2*temp;       
       // code here
    }
};













