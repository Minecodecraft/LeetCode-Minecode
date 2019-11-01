//
//  main.cpp
//  649. Dota2 Senate
//
//  Created by 边俊林 on 2019/11/1.
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
    string predictPartyVictory(string senate) {
        int n1 = 0, n2 = 0;
        for (char& ch: senate) {
            if (ch == 'R') n1++;
            else n2++;
        }
        if (n1 == 0) return "Dire";
        if (n2 == 0) return "Radiant";
        
        int n = senate.size();
        int banr = 0, band = 0;
        bitset<10010> bt;
        while (true) {
            for (int i = 0; i < n; ++i) {
                if (bt[i]) continue;
                char ch = senate[i];
                if (ch == 'R') {
                    if (banr) {
                        banr--;
                        bt[i] = 1;
                    } else {
                        band++;
                        n2--;
                    }
                } else { // D
                    if (band) {
                        band--;
                        bt[i] = 1;
                    } else {
                        banr++;
                        n1--;
                    }
                }
                if (n1 == 0) return "Dire";
                if (n2 == 0) return "Radiant";
            }
        }
    }
};

int main() {
    Solution sol = Solution();
    string s = "DRDRR";
    string res = sol.predictPartyVictory(s);
    cout << res << endl;
    return 0;
}
