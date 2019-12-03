//
//  main.cpp
//  854. K-Similar Strings
//
//  Created by 边俊林 on 2019/12/2.
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
// Solution 1: Backtracking Solution, 4ms, beats 100%
/*
class Solution {
public:
    int kSimilarity(string A, string B) {
        int sz = A.length();
        for (int i = 0; i < sz; ++i) {
            if (A[i] == B[i]) continue;
            vector<int> match;
            for (int j = i+1; j < sz; ++j) {
                if (A[i] == B[j] && A[j] != B[j]) {
                    if (A[j] == B[i]) {
                        swap(B[i], B[j]);
                        return 1+kSimilarity(A.substr(i+1), B.substr(i+1));
                    } else {
                        match.push_back(j);
                    }
                }
            }
            int res = sz-1;
            for (int j : match) {
                swap(B[i], B[j]);
                res = min(res, 1+kSimilarity(A.substr(i+1), B.substr(i+1)));
                swap(B[i], B[j]);
            }
            return res;
        }
        return 0;
    }
};
 */

// Solution 2: BFS Solution
class Solution {
public:
    int kSimilarity(string A, string B) {
        int len = A.length();
        vector<vector<int>> pos(6);
        for (int i = 0; i < len; ++i)
            pos[B[i] - 'a'].push_back(i);

        queue<pair<string, int>> q;
        q.push(make_pair(A, 0));
        while (q.size()) {
            auto& pir = q.front(); q.pop();
            string& str = pir.first;
            int cnt = pir.second;
            if (str == B)
                return cnt;
            int i = 0;
            while (i < len && str[i] == B[i]) ++i;
            for (int j : pos[str[i] - 'a']) {
                if (str[j] == B[j]) continue;
                string newstr = str;
                newstr[i] = str[j];
                newstr[j] = str[i];
                q.push(make_pair(newstr, cnt+1));
            }
        }
        return 0;
    }
};

int main() {
    Solution sol = Solution();
//    string a = "abac";
//    string b = "baca";
    string a = "abccaacceecdeea";
    string b = "bcaacceeccdeaae";
    int res = sol.kSimilarity(a, b);
    cout << res << endl;
    return 0;
}
