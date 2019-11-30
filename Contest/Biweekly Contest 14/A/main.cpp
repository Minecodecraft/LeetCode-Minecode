//
//  main.cpp
//  A
//
//  Created by 边俊林 on 2019/11/30.
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
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    string toHexspeak(string num) {
        long long n = stoll(num);
        stringstream ss;
        ss << hex << n;
        string rawhex = ss.str();
        for (int i = 0; i < rawhex.length(); ++i) {
            if (rawhex[i] == '0') {
                rawhex[i] = 'O';
            } else if (rawhex[i] == '1') {
                rawhex[i] = 'I';
            } else if (islower(rawhex[i])) {
                rawhex[i] = toupper(rawhex[i]);
            }
        }
        unordered_set<char> ava = {
            'A', 'B', 'C', 'D', 'E', 'F', 'I', 'O'
        };
        for (int i = 0; i < rawhex.length(); ++i) {
            if (ava.count(rawhex[i]) == 0)
                return "ERROR";
        }
        return rawhex;
    }
};

int main() {
    Solution sol = Solution();
//    string num = "257";
//    string num = "3";
//    string num = "262";
    string num = "747823223228";
    auto res = sol.toHexspeak(num);
    cout << res << endl;
    return 0;
}
