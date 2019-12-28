//
//  main.cpp
//  482. License Key Formatting
//
//  Created by 边俊林 on 2019/12/28.
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
    string licenseKeyFormatting(string s, int k) {
        stack<char> st;
        for (char ch: s)
            if (ch != '-') st.push(toupper(ch));
        int cnt = (st.size() + k - 1) / k;
        if (cnt == 0) return "";
        string res = string(st.size() + cnt - 1, '-');
        for (int i = res.length()-1; i >= 0; --i) {
            if ((res.length()-i) % (k+1) == 0) continue;
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "5F3Z-2e-9-w";
//    int k = 4;
//    string s = "2-5g-3-J";
//    int k = 2;
    string s = "---";
    int k = 3;
    string res = sol.licenseKeyFormatting(s, k);
    cout << res << endl;
    return 0;
}
