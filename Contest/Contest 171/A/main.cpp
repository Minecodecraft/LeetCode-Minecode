//
//  main.cpp
//  A
//
//  Created by 边俊林 on 2020/1/12.
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
    vector<int> getNoZeroIntegers(int n) {
        unordered_map<char, pair<int, int>> mp = {
            {'0', {5, 5}},
            {'1', {5, 6}},
            {'2', {1, 1}},
            {'3', {1, 2}},
            {'4', {1, 3}},
            {'5', {1, 4}},
            {'6', {1, 5}},
            {'7', {1, 6}},
            {'8', {1, 7}},
            {'9', {1, 8}},
        };
        string s = to_string(n);
        int len = s.length();
        string a = "", b = "";
        for (int i = len-1; i >= 0; --i) {
            if (s[i] == '1' && i == 0) {
                b.insert(b.begin(), '1');
            } else if (s[i] == '0' && i == 0) {
                continue;
            } else {
                auto& pir = mp[s[i]];
                a.insert(a.begin(), pir.first + '0');
                b.insert(b.begin(), pir.second + '0');
                if ((s[i] == '1' || s[i] == '0')) {
                    for (int j = i-1; j >= 0; --j)
                        if (s[j] == '0') {
                            s[j] = '9';
                        } else {
                            s[j]--; break;
                        }
                }
            }
        }
        return {stoi(a), stoi(b)};
    }
};

int main() {
    Solution sol = Solution();
//    int n = 2;
//    int n = 11;
//    int n = 1000;
    int n = 2;
    auto res = sol.getNoZeroIntegers(n);
    cout << res[0] << ", " << res[1] << endl;
    return 0;
}
