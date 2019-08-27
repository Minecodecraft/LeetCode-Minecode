//
//  main.cpp
//  264. Ugly Number II
//
//  Created by 边俊林 on 2019/8/27.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/ugly-number-ii/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;
        priority_queue<int, vector<int>, cmp> pq;
        unordered_set<int> vis;
        vector<int> factors = {2, 3, 5};

        int cnt = 1;
        pq.push(1);
        while (cnt < n) {
            int tmp = pq.top();
            pq.pop();
            for (int i = 0; i < factors.size(); ++i) {
                long long newfactor = (long long) tmp * (long long) factors[i];
                if (newfactor <= INT_MAX && !vis.count(newfactor)) {
                    vis.insert(newfactor);
                    pq.push(newfactor);
                }
            }
            ++cnt;
        }
        return pq.top();
    }

private:
    struct cmp {
        bool operator() (const int& a, const int& b) {
            return a > b;
        }
    };
};

int main() {
    Solution sol = Solution();
//    int n = 10;
    int n = 1407;
    int res = sol.nthUglyNumber(n);
    cout << res << endl;
    return 0;
}
