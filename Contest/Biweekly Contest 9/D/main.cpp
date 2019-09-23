//
//  main.cpp
//  D
//
//  Created by 边俊林 on 2019/9/21.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/Sample/description/
 \* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        // Huffman Tree
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &elem: blocks) pq.push(elem);
        while (pq.size() > 1) {
            pq.pop();
            int largest = pq.top();
            pq.pop();
            pq.push(largest + split);
        }
        return pq.top();
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
        1, 2, 3
//        1, 2
//        1
//        94961,39414,41263,7809,41473
    };
//    int split = 5;
    int split = 1;
//    int split = 90;
    int res = sol.minBuildTime(nums, split);
    cout << res << endl;
    return 0;
}
