//
//  main.cpp
//  1202. Smallest String With Swaps
//
//  Created by Jaylen Bian on 12/2/20.
//  Copyright © 2020 边俊林. All rights reserved.
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

/// Solution 1 :
/**
class Solution {
    int Find(vector<int>& f, int idx) {
        return f[idx] == idx ? idx : f[idx] = Find(f, f[idx]);
    }

    void Union(vector<int>& f, int u, int v) {
        int pu = Find(f, u);
        int pv = Find(f, v);
        if (pu == pv) return;
        f[pu] = pv;
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int len = s.length();
        vector<int> f (len);
        vector<vector<char>> pos (len);
        vector<int> p (len, 0);
        for (int i = 0; i < len; ++i) {
            f[i] = i;
        }

        // Union Find
        for (int i = 0; i < pairs.size(); ++i)
            Union(f, pairs[i][0], pairs[i][1]);
        for (int i = 0; i < len; ++i)
            pos[Find(f, i)].push_back(s[i]);
        for (int i = 0; i < len; ++i)
            sort(pos[i].begin(), pos[i].end());

        // Result
        string res = "";
        for (int i = 0; i < len; ++i) {
            int idx = Find(f, i);
            res += pos[idx][p[idx]++];
        }
        return res;
    }
};
 */

class Solution {
    int Find(vector<int>& f, int idx) {
        return f[idx] < 0 ? idx : f[idx] = Find(f, f[idx]);
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int len = s.length();
        vector<int> f (len, -1);
        vector<vector<int>> pos (len);

        for (auto& pir: pairs) {
            int pu = Find(f, pir[0]), pv = Find(f, pir[1]);
            if (pu != pv)
                f[pu] = pv;
        }
        for (int i = 0; i < s.length(); ++i)
            pos[Find(f, i)].push_back(i);
        for (auto& idxs: pos) {
            string tmps = "";
            for (int idx: idxs)
                tmps += s[idx];
            sort(tmps.begin(), tmps.end());
            for (int i = 0; i < idxs.size(); ++i)
                s[idxs[i]] = tmps[i];
        }
        return s;
    }
};

int main() {
    Solution sol = Solution();
    string s = "ibhbxvxwsucbanfpamugijzajkvhdrjvshsftajbhmzjebxyecdfogrcubmljzoqxonberhobfozvzhhxtxypsybhqbvjzbhvkbh";
    vector<vector<int>> pirs = {
        {15,13},{73,99},{27,33},{88,11},{63,96},{70,98},{34,44},{45,1},{15,88},{12,58},{30,40},{79,52},{68,84},{18,72},{0,14},{66,2},{87,84},{27,32},{36,13},{4,6},{18,78},{44,58},{9,39},{9,61},{35,69},{41,96},{51,37},{4,11},{16,90},{95,68},{75,42},{97,32},{14,92},{56,28},{79,5},{31,36},{56,32},{5,27},{1,69},{68,40},{98,50},{57,21},{48,37},{3,62},{18,15},{80,40},{71,88},{30,13},{12,36},{2,44},{62,78},{14,8},{98,47},{65,67},{4,59},{98,6},{31,63},{43,8},{19,42},{6,63},{62,74},{96,11},{94,61},{90,10},{50,69},{86,5},{83,7},{37,51},{14,23},{39,64},{70,38},{36,73},{20,21},{0,79},{42,32},{98,34},{15,73},{12,14},{31,77},{65,6},{15,28},{68,64},{66,84},{89,21},{50,93},{32,71},{36,46},{92,53},{40,51},{27,18},{98,2},{44,9},{10,99},{62,21},{27,53},{23,28},{52,66},{57,60},{39,43},{24,94}
    };
    string res = sol.smallestStringWithSwaps(s, pirs);
    cout << res << endl;
    return 0;
}
