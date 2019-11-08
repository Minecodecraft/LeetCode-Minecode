//
//  main.cpp
//  1046. Last Stone Weight
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
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq (stones.begin(), stones.end());
        while (pq.size() > 1) {
            int hi = pq.top(); pq.pop();
            int lo = pq.top(); pq.pop();
            hi -= lo;
            if (hi)
                pq.push(hi);
        }
        return pq.size() ? pq.top() : 0;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
        2,7,4,1,8,1
    };
    int res = sol.lastStoneWeight(nums);
    cout << res << endl;
    return 0;
}
