//
//  main.cpp
//  B
//
//  Created by 边俊林 on 2020/3/8.
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

/// Solution:
//
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int len = light.size();
        set<int> st;
        for (int i = 1; i <= len; ++i) {
            st.insert(i);
        }
        int maxx = 0;
        int res = 0;

        for (int li: light) {
            st.erase(li);
            maxx = max(maxx, li+1);
            if (*st.begin() == maxx || st.empty())
                ++res;
        }

        return res;
    }
};

int main() {
    Solution sol = Solution();
//    vector<int> ls = {2, 1, 3 ,5 ,4};
    vector<int> ls = {2,1,4,3,6,5};
    int res = sol.numTimesAllBlue(ls);
    cout << res << endl;
    return 0;
}
