//
//  main.cpp
//  621. Task Scheduler
//
//  Created by 边俊林 on 2019/10/20.
//  Copyright © 2019 Minecode.Link. All rights reserved.
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
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> cnt;
        int maxnct = 0;
        for (char& ch: tasks) {
            cnt[ch]++;
            maxnct = max(maxnct, cnt[ch]);
        }
        int res = (maxnct-1) * (n+1);
        for (auto& kv: cnt)
            if (kv.second == maxnct) ++res;
        return max((int)tasks.size(), res);
    }
};

int main() {
    Solution sol = Solution();
    string s = "AAAAAABCDEFG";
//    string s = "AAABBB";
    vector<char> tasks (s.begin(), s.end());
//    vector<char> tasks = {
//        'a', 'a', 'a', 'b', 'b', 'b'
//        'a', 'a'
//    };
    int n = 2;
//    int n = 0;
    int res = sol.leastInterval(tasks, n);
    cout << res << endl;
    return 0;
}
