//
//  main.cpp
//  681. Next Closest Time
//
//  Created by 边俊林 on 2019/12/21.
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
    string nextClosestTime(string time) {
        set<int> st;
        for (int i = 0; i < time.size(); ++i) {
            if (i == 2) continue;
            st.insert(time[i]-'0');
        }
        for (int i = 0; i < time.size(); ++i) {
            if (i == 2) continue;
            int cur = time[i] - '0';
            auto it = st.upper_bound(cur);
            if (it != st.end()) {
                time[i] = *it + '0';
                return time;
            }
        }
        for (int i = 0; i < time.size(); ++i) {
            if (i == 2) continue;
            time[i] = *st.begin() + '0';
        }
        return time;
    }
};

int main() {

    return 0;
}
