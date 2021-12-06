#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

int main(){
    unordered_map<string, int> umap;
    umap["tarun"] = 44;
    umap["arun"] = 487;
    umap["gfg"] = 4445;

    // for (auto x : umap)
    // {
    //     cout << x.first << " " << x.second << endl;
    // }

    for (auto itr = umap.begin(); itr != umap.end(); itr++)
    {
        cout << itr->first << " " << itr->second << endl;
    }

    // if (umap.find("tarun") != umap.end())
    //     cout << "Key found" << endl;
    // else
    //     cout << "key not found";


    
}
