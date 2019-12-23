//
//  main.cpp
//  904. Fruit Into Baskets
//
//  Created by 边俊林 on 2019/12/23.
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
// Solution 1: Only beats 10%, O(2n), has a higher constant time.
/*
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int, int> mp;
        int res = 0, cnt = 0, l = 0;
        for (int i = 0; i < tree.size(); ++i) {
            if (mp[tree[i]]++ == 0) ++cnt;
            while (cnt > 2)
                if (--mp[tree[l++]] == 0) --cnt;
            res = max(res, i - l + 1);
        }
        return res;
    }
};
 */

// Solution 2: A perfect O(n) solution, time & space both O(n)
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int, int> mp;
        int i, j;
        for (i = 0, j = 0; j < tree.size(); ++j) {
            mp[tree[j]]++;
            if (mp.size() > 2) {
                if (--mp[tree[i]] == 0) mp.erase(tree[i]);
                ++i;
            }
        }
        return j - i;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> mat = {
        1, 2, 1
    };
    int res = sol.totalFruit(mat);
    cout << res << endl;
    return 0;
}
