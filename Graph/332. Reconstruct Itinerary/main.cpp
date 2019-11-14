//
//  main.cpp
//  332. Reconstruct Itinerary
//
//  Created by 边俊林 on 2019/11/14.
//  Copyright © 2019 边俊林. All rights reserved.
//

#include <map>
#include <set>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> mp;
        for (auto& ticket: tickets) {
            mp[ticket[0]].insert(ticket[1]);
        }
        
        vector<string> path;
        dfs(mp, path, "JFK");
        return vector<string>(path.rbegin(), path.rend());
    }
    
private:
    void dfs(unordered_map<string, multiset<string>>& mp, vector<string>& path, string curr) {
        while (mp[curr].size()) {
            string str = *mp[curr].begin();
            mp[curr].erase(mp[curr].begin());
            dfs(mp, path, str);
        }
        path.push_back(curr);
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<string>> mat = {
//        {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}
        {"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}
//        {"JFK","ATL"},{"ATL","JFK"}
    };
    auto res = sol.findItinerary(mat);
    for_each(begin(res), end(res), [](string ele) { cout << ele << ",  "; });
    return 0;
}
