// Problem
// Luffy needs to reach grandline ASAP. Lufi's ship is K Kilometers far from Grandline . But luffy consumse 1 unit of food for every kilometer the ship covers and luffy can never be hungry until he reaches grandline. There are N islands between ship's current position and grandline. ithIsland is Di distance apart from grandline and has Ai amount of food. Luffy curently has F amount of food. You need to tell minimum number of islands luffy needs to stop at so that he never is hungary before reaching grandline.

// If its not possible to reach grandline without luffy being hungary, then print -1

 

// Input

// The first line of the input contains a single integer T denoting the number of test cases. The first line of each test case contains a single integer N denoting number of islands. The second line of each test case contains two integers K and F denoting the initial distance of ship from grandline and amount of food ship has initially. Next N lines contain two space separated integers Di and Ai denoting the distance of the island from Grandline and the amount of food in island. Ship can take all the food from any island.

// Output

// For each test case print the minimum number of stops required to reach grandline. If he cannot reach home print "-1".

// Constraints

// 1 ≤  T ≤ 10

// 1≤  N ≤ 104

// 1 ≤  D ≤ K ≤ 106

// 1 ≤  A, F  ≤ 106

// Sample Input
// 2
// 4
// 25 10
// 20 5
// 10 10
// 22 2
// 23 4
// 5
// 25 7
// 12 4
// 11 3
// 3 4
// 17 4
// 2 19
// Sample Output
// 2
// -1
// Time Limit: 2
// Memory Limit: 256
// Source Limit:
// Explanation
// In the first test case, luffy initially has 10 units of food, The ship reaches 4th island(23 distance apart) first and luffy has eaten 2 units of food upto then ship reaches 3rd(22 distance apart) island luffy has eaten 2+1 = 3 units of food. Then ship reaches island one(20 distance apart) and refill ship with 5 units of food and then reaches second(10 distance apart) and refills ship with 10 units of food. Total 


#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        long long f;
        cin>>n>>k>>f;
        vector<pair<int,int>> prs;
        for (int i = 0; i < n; i++)
        {
            int dist,food;
            cin>>dist>>food;
            prs.push_back({k-dist,food});
        }
        int ans = 0;
        multiset<int> food_avl;
        sort(prs.begin(),prs.end());
        bool can_react = true;
        int cur = 0;
        for (int i = 1; i < k; i++)
        {
            f--;
            if(prs[cur].first == i){
                food_avl.insert(prs[cur].second);
                cur++;
            }
            if(f == 0){
                if(food_avl.size() == 0){
                    can_react = false;
                    break;
                }else{
                    auto it = --food_avl.end();
                    f += (*it);
                    food_avl.erase(it);
                    ans++;
                }
            }
        }
        if(can_react){
            cout<<ans<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
}


























