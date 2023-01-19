// Carpet into Box
// MediumAccuracy: 59.12%Submissions: 3K+Points: 4
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// There is a carpet of a size a*b [length * breadth]. You are given a box of size c*d. The task is, one has to fit the carpet in the box in a minimum number of moves.

// In one move, you can either decrease the length or the breadth of the carpet by half (floor value of its half).

// Note: One can even turn the carpet by 90 degrees any number of times, wont be counted as a move.

// Example 1:

// Input:
// A = 8, B = 13
// C = 6, D = 10
// Output:
// Minimum number of moves: 1
// Explanation:
// Fold the carpet by breadth, 13/2 i.e. 6,
// so now carpet is 6*8 and can fit fine.

// Example 2:

// Input:
// A = 4, B = 8
// C = 3, D = 10
// Output:
// Minimum number of moves: 1
// Explanation: Fold the carpet by length , 4/2 i.e. 2,
// so now carpet is 2*8 and can fit fine.

// Your Task:
// You don't need to read input or print anything. You only need to complete the function carpetBox() that takes an integer A, B, C and D as input and returns an integer denoting the minimum numbers of moves required to fit the carpet into the box.

// Expected Time Complexity: O( max( log(a), log(b) ) ) .
// Expected Auxiliary Space: O(1) .

// Constrains:
// 1<= A,B,C,D <= 109

// View Bookmarked Problems

class Solution
{
public:
    int countMoves(int a, int b, int &lgt, int &brt)
    {

        if (a < b)
            swap(a, b);

        if (a <= lgt && b <= brt)
            return 0;

        // if length doesnot fits

        if (a > lgt)

            return 1 + countMoves(a / 2, b, lgt, brt);

        // if breadth doesnot fit

        return 1 + countMoves(a, b / 2, lgt, brt);
    }

    int carpetBox(int A, int B, int C, int D)
    {

        // code here

        if (C < D)
            swap(C, D);

        return countMoves(A, B, C, D);
    }
};
