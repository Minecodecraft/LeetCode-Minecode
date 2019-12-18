//
//  main.cpp
//  388. Longest Absolute File Path
//
//  Created by 边俊林 on 2019/12/17.
//  Copyright © 2019 边俊林. All rights reserved.
//

#include <map>
#include <set>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <cstdio>
#include <sstream>
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
    int lengthLongestPath(string s) {
        vector<string> strs;
        size_t pos = 0, prepos = 0;
        s += '\n';
        while ((pos = s.find('\n', pos)) != string::npos) {
            strs.push_back(s.substr(prepos, pos-prepos));
            pos = prepos = pos + 1;
        }
        stack<int> st;
        st.push(0);
        int maxlen = 0;
        for (auto& str: strs) {
            pos = str.rfind('\t');
            int level = pos == string::npos ? 0 : (pos + 1);
            while (st.size() > level + 1) st.pop();
            st.push(st.top() + str.length() - level + 1);
            if (str.find('.') != string::npos) maxlen = max(maxlen, st.top());
        }
        return maxlen == 0 ? 0 : maxlen-1;
    }
};

int main() {
    Solution sol = Solution();
//    string s = R"(dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext)";
//    string s = R"(dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext)";
    string s = R"(dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext)";
    int res = sol.lengthLongestPath(s);
    cout << res << endl;
    return 0;
}
