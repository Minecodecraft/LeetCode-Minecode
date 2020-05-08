//
//  main.cpp
//  D
//
//  Created by Jaylen Bian on 4/18/20.
//  Copyright © 2020 Jaylen Bian. All rights reserved.
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
    int minJump(vector<int>& jump) {
        int n = jump.size();
        set<int> st;
        for (int i = 1; i < n; ++i) st.insert(i);

        queue<int> q;
        q.push(0);
        int res = 0;
        while (q.size()) {
            ++res;
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int tar = q.front(); q.pop();
                if (tar + jump[tar] >= n)
                    return res;
                q.push(tar + jump[tar]);
                while (st.size() && *st.begin() <= tar) {
                    q.push(*st.begin());
                    st.erase(*st.begin());
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> jump = {
        2, 5, 1, 1, 1, 1
    };
    int res = sol.minJump(jump);
    cout << res << endl;
    return 0;
}
