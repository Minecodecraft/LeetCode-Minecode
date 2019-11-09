//
//  main.cpp
//  1111. Maximum Nesting Depth of Two Valid Parentheses Strings
//
//  Created by 边俊林 on 2019/11/8.
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
    vector<int> maxDepthAfterSplit(string seq) {
        int depth = 0;
        vector<int> res;
        for (int i = 0; i < seq.size(); ++i) {
            if (seq[i] == '(')
                res.push_back(depth++ % 2);
            else
                res.push_back(--depth % 2);
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "(()())";
    string s = "()(())()";
    auto res = sol.maxDepthAfterSplit(s);
    for_each(begin(res), end(res), [](int ele) { cout << ele << ", "; });
    cout << endl;
    return 0;
}
