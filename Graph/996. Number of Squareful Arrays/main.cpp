//
//  main.cpp
//  996. Number of Squareful Arrays
//
//  Created by 边俊林 on 2019/12/3.
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
    int numSquarefulPerms(vector<int>& A) {
        unordered_map<int, int> cnt;
        unordered_map<int, vector<int>> match;
        for (int& i: A) cnt[i]++;
        for (auto& i: cnt) {
            for (auto& j: cnt) {
                if (isPerfectSquare((long long)0 + i.first + j.first))
                    match[i.first].push_back(j.first);
            }
        }

        int res = 0;
        for (auto& pir: cnt) {
            if (pir.second)
                dfs(cnt, match, pir.first, A.size()-1, res);
        }
        return res;
    }

private:
    bool isPerfectSquare(long long num) {
        double sqr = sqrt(num);
        return (sqr-floor(sqr)) == 0;
    }

    void dfs(unordered_map<int, int>& cnt, unordered_map<int, vector<int>>& match, int num, int left, int& res) {
        if (left == 0) {
            res++;
            return;
        }
        cnt[num]--;
        for (int& nxt: match[num]) {
            if (cnt[nxt])
                dfs(cnt, match, nxt, left-1, res);
        }
        cnt[num]++;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> mat = {
//        1,17,8
//        2,2,2
        2,2,2,2,2,2,2,2
    };
    int res = sol.numSquarefulPerms(mat);
    cout << res << endl;
    return 0;
}
