//
//  main.cpp
//  1090. Largest Values From Labels
//
//  Created by 边俊林 on 2019/11/8.
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
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        int n = values.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < values.size(); ++i)
            mp[labels[i]].push_back(values[i]);

        for (auto& kv: mp) {
            sort(kv.second.begin(), kv.second.end(), [](int& a, int& b) { return a > b; });
        }
        vector<int> list;
        for (auto& kv: mp) {
            for (int i = 0; i < min(use_limit, (int)kv.second.size()); ++i) {
                list.push_back(kv.second[i]);
            }
        }
        nth_element(begin(list), begin(list)+num_wanted, end(list), [](int& a, int& b) { return a > b; });
        return accumulate(begin(list), begin(list)+min((int)list.size(), num_wanted), 0);
    }
};

int main() {
    Solution sol = Solution();
    vector<int> vs = {
//        5,4,3,2,1
        9,8,8,7,6
    };
    vector<int> ls = {
//        1,3,3,3,2
        0,0,0,1,1
    };
//    int num_wanted = 3, use_limit = 2;
    int num_wanted = 3, use_limit = 1;
//    int num_wanted = 3, use_limit = 2;
    int res = sol.largestValsFromLabels(vs, ls, num_wanted, use_limit);
    cout << res << endl;
    return 0;
}
