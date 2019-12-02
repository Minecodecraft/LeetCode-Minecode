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

int main() {
    Solution sol = Solution();
    string a = "abac";
    string b = "baca";
    int res = sol.kSimilarity(a, b);
    cout << res << endl;
    return 0;
}
