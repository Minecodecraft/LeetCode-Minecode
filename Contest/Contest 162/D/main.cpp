//
//  main.cpp
//  D
//
//  Created by 边俊林 on 2019/11/10.
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
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> lcnt (26, 0);
        vector<vector<int>> wcnt ((int)words.size(), vector<int> (26, 0));
        for (char& ch: letters) lcnt[ch-'a']++;
        for (int i = 0; i < words.size(); ++i) {
            for (char& ch: words[i]) {
                wcnt[i][ch-'a']++;
            }
        }

        int res = 0;
        for (int i = 0; i < words.size(); ++i) {
            backtracking(wcnt, score, lcnt, i, 0, res);
        }
        return res;
    }

private:
    void backtracking(vector<vector<int>>& wcnt, vector<int>& score, vector<int>& lcnt, int idx, int sum, int& res) {
        if (idx >= wcnt.size()) return;

        for (int i = 0; i < 26; ++i)
            if (wcnt[idx][i] > lcnt[i]) return;

        // minus
        int cursum = 0;
        for (int i = 0; i < 26; ++i) {
            lcnt[i] -= wcnt[idx][i];
            cursum += score[i] * wcnt[idx][i];
        }

        sum += cursum;
        res = max(res, sum);

        for (int nxt = idx+1; nxt < wcnt.size(); ++nxt) {
            backtracking(wcnt, score, lcnt, nxt, sum, res);
        }

        for (int i = 0; i < 26; ++i)
            lcnt[i] += wcnt[idx][i];
    }
};

int main() {
    Solution sol = Solution();
    vector<string> ws = {
        "dog","cat","dad","good"
    };
    string lsraw = "aacdddgoo";
    vector<char> ls (lsraw.begin(), lsraw.end());
    vector<int> scs = {
        1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0
    };
    int res = sol.maxScoreWords(ws, ls, scs);
    cout << res << endl;
    return 0;
}
