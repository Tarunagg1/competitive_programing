// Firing employees
// MediumAccuracy: 45.52%Submissions: 624Points: 4
// Geek is the founder of Geek Constructions. He always maintains a black-list of potential employees which can be fired at any moment.

// The company has N employees (including Geek), and each employee is assigned a distinct rank (1 <= rank <= N) at the time of joining. The company has a hierarchical  management such that each employee always has one immediate senior.

// Geek has a strange and unfair way of evaluating an employees performance. He sums the employee's rank and the number of seniors the employee has. If it is a prime number, the employee is put up on the black-list.

// Given an array arr[] in order of the rank of company employees. For rank i, arr[i] represents the rank of the immediate senior of the employee with the ith rank. If geek's rank is i, then arr[i] is always equal to 0 as there is noone senior to him. Find out the number of Black-Listed employees.

// Note: The black-list can not contain Geeks name as he is the founder of the company and he is the one that makes the list.

// Example 1:

// Input:
// N = 4
// arr[] = {0, 1, 1, 2}

// Output: 1

// Explanation:
// The hierarchy is as follows

//        (Geek)
//        Rank 1
//         /   \
//   Rank 2     Rank 3
//       /
// Rank 4

// Performance = rank + number of seniors
// Performance for rank 1 = not considered.
// Performance for rank 2 = 2+1 = 3 (prime)
// Performance for rank 3 = 3+1 = 4 (not prime)
// Performance for rank 4 = 4+2 = 6 (not prime)
// Therefore, only employee 2 is black-listed.

// Example 2:

// Input:
// N = 3
// arr[] = {2, 3, 0}

// Output: 2

// Explanation:
// The hierarchy is as follows

//        (Geek)
//        Rank 3
//         /
//   Rank 2
//       /
// Rank 1

// Rank 1 and 2 are both black-listed.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function firingEmployees() which takes the array arr[] and its size N as input parameters. It returns the number of black-listed employees.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= N <= 105
// 1 <= i <= N
// 1 <= arr[i] <= 105

class Solution
{
public:
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        return true;
    }
    int firingEmployees(vector<int> &arr, int n)
    {
        // code here
        map<int, vector<int>> listEdge;
        for (int i = 0; i < n; i++)
            listEdge[arr[i]].push_back(i + 1);
        queue<int> listRank;
        int ans = 0, level = 0;
        listRank.push(listEdge[0][0]);
        while (!listRank.empty())
        {
            listRank.push(-1);
            while (listRank.front() != -1)
            {
                int u = listRank.front();
                listRank.pop();
                if (level != 0 && isPrime(u + level))
                    ans++;
                for (auto &i : listEdge[u])
                    listRank.push(i);
            }
            listRank.pop();
            level++;
        }
        return ans;
    }
};
