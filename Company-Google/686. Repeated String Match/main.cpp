//
//  main.cpp
//  686. Repeated String Match
//
//  Created by 边俊林 on 2020/1/8.
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
    int repeatedStringMatch(string A, string B) {
        for (int i = 0; i < A.length(); ++i) {
            int j = 0;
            while (j < B.length() && A[(i+j) % A.length()] == B[j]) ++j;
            if (j == B.length()) return (i+j+A.length()-1) / A.length();
        }
        return -1;
    }
};

int main() {
    Solution sol = Solution();
    string a = "abcd";
    string b = "cdabcdab";
//    string a = "aa";
//    string b = "a";
    int res = sol.repeatedStringMatch(a, b);
    cout << res << endl;
    return 0;
}
