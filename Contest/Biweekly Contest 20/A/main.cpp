//
//  main.cpp
//  A
//
//  Created by 边俊林 on 2020/2/22.
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
    vector<int> sortByBits(vector<int>& arr) {
        unordered_map<int, int> cnt;

        for (int ele: arr) {
            int raw = ele;
            int tmp = 0;
            while (ele) {
                tmp += ele & 1;
                ele >>= 1;
            }
            cnt[raw] = tmp;
        }
        auto cmp = [&](int a, int b) {
            return cnt[a] == cnt[b] ? a < b : cnt[a] < cnt[b];
        };
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};

int main() {
    Solution sol = Solution();
//    vector<int> arr = {0,1,2,3,4,5,6,7,8};
    vector<int> arr = {1024,512,256,128,64,32,16,8,4,2,1};
    auto res = sol.sortByBits(arr);
    cout << res.size() << endl;
    return 0;
}
