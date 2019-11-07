//
//  main.cpp
//  1007. Minimum Domino Rotations For Equal Row
//
//  Created by 边俊林 on 2019/11/7.
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
// Solution 1: O(n) with ungly code, 214ms, let's be concise!
/*
class Solution {
public:
    int minDominoRotations(vector<int>& a, vector<int>& b) {
        bool cana = true, canb = true;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != a[0] && b[i] != a[0])
                cana = false;
            if (a[i] != b[0] && b[i] != b[0])
                canb = false;
        }
        if (!cana && !canb)
            return -1;

        int resa = cana ? 0 : INT_MAX;
        int resb = canb ? 0 : INT_MAX;
        if (cana) {
            int same = 0;
            for (int i = 0; i < a.size(); ++i) {
                if (a[i] != a[0]) ++resa;
                else if (b[i] == a[0]) ++same;
            }
            resa = min(resa, (int)a.size()-resa-same);
        }
        if (canb) {
            int same = 0;
            for (int i = 0; i < a.size(); ++i) {
                if (b[i] != b[0]) ++resb;
                else if (a[i] == b[0]) ++same;
            }
            resb = min(resb, (int)a.size()-resb-same);
        }
        return min(resa, resb);
    }
};
 */

int main() {
    Solution sol = Solution();

    int res = sol.minDominoRotations(a, b);
    cout << res << endl;
    return 0;
}
