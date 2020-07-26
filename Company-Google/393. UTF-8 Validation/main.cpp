//
//  main.cpp
//  393. UTF-8 Validation
//
//  Created by Jaylen Bian on 7/26/20.
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
    bool validUtf8(vector<int>& data) {
        int cnt = 0;
        for (int& n: data) {
            if (cnt == 0) {
                if ((n >> 3) == 0b11110) cnt = 3;
                else if ((n >> 4) == 0b1110) cnt = 2;
                else if ((n >> 5) == 0b110) cnt = 1;
                else if ((n >> 7) == 0b1) return false;
            } else {
                if ((n >> 6) != 0b10)
                    return false;
                --cnt;
            }
        }
        return cnt == 0;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> data = {197, 130, 1};
    bool res = sol.validUtf8(data);
    cout << res << endl;
    return 0;
}
