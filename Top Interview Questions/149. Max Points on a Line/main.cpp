//
//  main.cpp
//  149. Max Points on a Line
//
//  Created by 边俊林 on 2019/10/21.
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
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<pair<int, int>, int, hash_key> slocnt;
        if (points.size() <= 2) return points.size();
        int res = 0;
        for (int i = 0; i < points.size()-1; ++i) {
            slocnt.clear();
            int slomax = 1, dupcnt = 0, vercnt = 1;
            for (int j = i+1; j < points.size(); ++j) {
                if (points[j][0] == points[i][0]) {
                    if (points[j][1] == points[i][1])
                        ++dupcnt;
                    else
                        ++vercnt;
                } else {
                    int ydif = points[i][1]-points[j][1];
                    int xdif = points[i][0]-points[j][0];
                    int _gcd = gcd(ydif, xdif);
                    ydif /= _gcd;
                    xdif /= _gcd;
                    pair<int, int> pir = make_pair(xdif, ydif);

                    slocnt[pir] = slocnt[pir] ? slocnt[pir]+1 : 2;
                    slomax = max(slomax, slocnt[pir]);
                }
            }
            int curmax = max(slomax+dupcnt, vercnt+dupcnt);
            res = max(res, curmax);
        }
        return res;
    }

private:
    struct hash_key {
        size_t operator() (const pair<int, int>& pir) const {
            return size_t(pir.first) + size_t(pir.second);
        }
    };
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int >> mat = {
//        {1, 1}, {2, 2}, {3, 3}
//        {4, 0}, {4, -1}, {4, 5}
        {0,0},{94911151,94911150},{94911152,94911151}
    };
    int res = sol.maxPoints(mat);
    cout << res << endl;
    return 0;
}
