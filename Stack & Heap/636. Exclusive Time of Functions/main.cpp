//
//  main.cpp
//  636. Exclusive Time of Functions
//
//  Created by 边俊林 on 2019/10/9.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/exclusive-time-of-functions/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <sstream>
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
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res (n, 0);
        stack<Range> st;
        for (auto& log: logs) {
            stringstream ss (log);
            string s1, s2, s3;
            getline(ss, s1, ':');
            getline(ss, s2, ':');
            getline(ss, s3, ':');
            Range range = {stoi(s1), stoi(s3)};

            if (s2 == "start") {
                st.push(range);
            } else {
                int diff = range.time - st.top().time + 1;
                res[range.id] += diff;
                st.pop();

                if (st.size())
                res[st.top().id] -= diff;
            }
        }
        return res;
    }

    private:
    struct Range {
        int id;
        int time;
    };
};

int main() {
    Solution sol = Solution();
//    int n = 2;
    int n = 1;
    vector<string> logs = {
//        "0:start:0","1:start:2","1:end:5","0:end:6"
        "0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"
    };
    vector<int> res = sol.exclusiveTime(n, logs);
    cout << res.size() << endl;
    return 0;
}
