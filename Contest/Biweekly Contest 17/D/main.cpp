//
//  main.cpp
//  D
//
//  Created by 边俊林 on 2020/1/11.
//  Copyright © 2020 边俊林. All rights reserved.
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
    int distinctEchoSubstrings(string text) {
        int len = text.length();
        unordered_set<string> st;
        for (int i = 0; i < len; ++i) {
            for (int j = 1; j <= (len-i) / 2; ++j) {
                if (check(i, i+j, j, text))
                    st.insert(text.substr(i, j));
            }
        }
        return st.size();
    }

private:
    inline bool check(int i, int j, int len, const string& str) {
        for (int p = 0; p < len; ++p) {
            if (str[i+p] != str[j+p]) return false;
        }
        return true;
    }
};

int main() {
    Solution sol = Solution();
//    string str = "abcabcabc";
    string str = "leetcodeleetcode";
    int res = sol.distinctEchoSubstrings(str);
    cout << res << endl;
    return 0;
}
