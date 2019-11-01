//
//  main.cpp
//  455. Assign Cookies
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
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int l = 0, r = 0;
        while (l < g.size() && r < s.size()) {
            if (s[r] >= g[l])
                ++r, ++l;
            else
                ++r;
        }
        return l;
    }
};

int main() {

    return 0;
}
