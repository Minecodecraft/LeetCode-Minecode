//
//  main.cpp
//  975. Odd Even Jump
//
//  Created by 边俊林 on 2019/12/29.
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
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size(), res = 0;
        map<int, int> mp;
        vector<pair<int, int>> maxa (n);
        vector<pair<int, int>> mina (n);

        for (int i = n-1; i >= 0; --i) {
            auto it = mp.upper_bound(arr[i]);
            if (it == mp.begin()) {
                maxa[i] = {-1, -1};
            } else {
                it = prev(it);
                maxa[i] = {it->first, it->second};
            }

            it = mp.lower_bound(arr[i]);
            if (it == mp.end()) {
                mina[i] = {-1, -1};
            } else {
                mina[i] = {it->first, it->second};
            }

            mp[arr[i]] = i;
        }

        for (int i = 0; i < n; ++i) {
            if (jump(maxa, mina, i, 0)) ++res;
        }
        return res;
    }

private:
    bool jump(vector<pair<int, int>>& maxa, vector<pair<int, int>>& mina, int index, int mode) {
        if (index == maxa.size()-1) return true;
        mode = 1-mode;
        if (mode == 1 && mina[index].first != -1)
            return jump(maxa, mina, mina[index].second, mode);
        else if (mode == 0 && maxa[index].first != -1)
            return jump(maxa, mina, maxa[index].second, mode);
        return false;
    }
};

int main() {

    Solution sol = Solution();
    vector<int> arr = {
//        10,13,12,14,15
        2,3,1,1,4
    };
    int res = sol.oddEvenJumps(arr);
    cout << res << endl;

    return 0;
}
