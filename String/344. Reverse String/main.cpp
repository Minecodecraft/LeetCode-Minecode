//
//  main.cpp
//  344. Reverse String
//
//  Created by 边俊林 on 2019/8/11.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/reverse-string/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.size() <= 0) return;
        int l = 0, r = s.size()-1;
        while (l < r) {
            swap(s[l++], s[r--]);
        }
    }
};

int main() {
    Solution sol = Solution();
    vector<char> s = {'h','e','l','l','o'};
    sol.reverseString(s);
    for_each(s.begin(), s.end(), [](char ch) { cout << ch << " "; });

    return 0;
}
