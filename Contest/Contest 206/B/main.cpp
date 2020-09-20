//
//  main.cpp
//  B
//
//  Created by Jaylen Bian on 9/15/20.
//  Copyright © 2020 Jaylen Bian. All rights reserved.
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
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        // pefs[i][j] 代表第j人在第i人好感度列表中的排名
        vector<unordered_map<int, int>> pefs (n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < preferences[i].size(); ++j){
                pefs[i][preferences[i][j]] = j;
            }
        }
        vector<int> pairIndex (n);
        for (auto pir: pairs) {
            pairIndex[pir[0]] = pefs[pir[0]][pir[1]];
            pairIndex[pir[1]] = pefs[pir[1]][pir[0]];
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            int leftIndex = pairIndex[i];
            for (int left = 0; left < leftIndex; ++left) {
                // 每次取出一个与第i人好感度大于当前配对搭档的人right
                int rightPreference = preferences[i][left];
                // 找出right这个人当前搭档在好感度列表中的排名
                int rightIndex = pairIndex[rightPreference];
                // 标记当前这个人是否不开心了
                bool unhappy = false;
                for (int right = 0; right < rightIndex; ++right) {
                    if (preferences[rightPreference][right] == i) {
                        ++res;
                        unhappy = true;
                        break;
                    }
                }
                // 如果已经不开心，则无需再查找
                if (unhappy)
                    break;
            }
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    int n = 2;
    vector<vector<int>> pres = {{1},{0}};
    vector<vector<int>> pirs = {{0, 1}};
    int res = sol.unhappyFriends(n, pres, pirs);
    cout << res << endl;
    return 0;
}
