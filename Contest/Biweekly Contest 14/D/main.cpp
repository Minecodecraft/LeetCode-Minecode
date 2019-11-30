//
//  main.cpp
//  D
//
//  Created by 边俊林 on 2019/11/30.
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
class Sea {
public:
    bool hasShips(vector<int> topRight, vector<int> bottomLeft) {
        for (auto& pir: mat) {
            if ((pir[0] >= bottomLeft[0] && pir[0] <= topRight[0])
                && (pir[1] >= bottomLeft[1] && pir[1] <= topRight[1]))
                return true;
        }
        return false;
    }
    
private:
    vector<vector<int>> mat = {
        {1, 1}, {2, 2}, {3, 3}, {5, 5}
    };
 };

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        int res = 0;
        vis = vector<vector<bool>> (1000, vector<bool> (1000, false));
        search(sea, bottomLeft, topRight, res);
        return res;
    }

private:
    vector<vector<bool>> vis;
    bool search(Sea& sea, vector<int> bl, vector<int> tr, int& cnt) {
        if (bl[0] > tr[0] || bl[1] > tr[1])
            return false;
        
        int has = sea.hasShips(tr, bl);
        if (tr == bl) {
            if (has && !vis[bl[0]][bl[1]]) {
                vis[bl[0]][bl[1]] = true;
//                cout << bl[0] << ", " << bl[1] << endl;
                ++cnt;
                return true;
            }
            return false;
        }
        if (!has) return false;
        
        bool flag = false;
        if (tr[0] == bl[0]) {
            int mid = (tr[1] + bl[1]) / 2;
            flag |= search(sea, bl, {bl[0], mid}, cnt);
            flag |= search(sea, {bl[0], mid+1}, tr, cnt);
        } else if (tr[1] == bl[1]) {
            int mid = (tr[0] + bl[0]) / 2;
            flag |= search(sea, bl, {mid, bl[1]}, cnt);
            flag |= search(sea, {mid+1, bl[1]}, tr, cnt);
        } else {
            int xmid = (tr[0] + bl[0]) / 2;
            int ymid = (tr[1] + bl[1]) / 2;
            flag |= search(sea, bl, {xmid, ymid}, cnt);
            flag |= search(sea, {bl[0], ymid}, {xmid, tr[1]}, cnt);
            flag |= search(sea, {xmid+1, bl[1]}, {tr[0], ymid+1}, cnt);
            flag |= search(sea, {xmid+1, ymid+1}, tr, cnt);
        }
        
        return flag;
    }
};

int main() {
    Solution sol = Solution();
    Sea sea = Sea();
    vector<int> tr = {4, 4};
    vector<int> bl = {0, 0};
    auto res = sol.countShips(sea, tr, bl);
    cout << res << endl;
    return 0;
}
