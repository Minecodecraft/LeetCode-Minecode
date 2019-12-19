//
//  main.cpp
//  683. K Empty Slots
//
//  Created by 边俊林 on 2019/12/19.
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
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        map<int, int> mp = {
            {-INF, 0}, {INF, 0}
        };
        for (int i = 0; i < n; ++i) {
            auto it = mp.insert({bulbs[i], i}).first;
            if (it->first - prev(it)->first == k+1 || next(it)->first - it->first == k+1)
                return i+1;
        }
        return -1;
    }

private:
    const int INF = 0x3f3f3f3f;
};

int main() {
    Solution sol = Solution();
    vector<int> blubs = {
        1, 3, 2
    };
    int k = 1;
    int res = sol.kEmptySlots(blubs, k);
    cout << res << endl;
    return 0;
}
