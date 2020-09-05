//
//  main.cpp
//  299. Bulls and Cows
//
//  Created by Jaylen Bian on 9/5/20.
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
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        vector<int> cnt(10, 0);
        for (char ch: secret) {
            cnt[ch-'0']++;
        }
        for (int i = 0; i < secret.size(); ++i) {
            if (guess[i] == secret[i]) {
                ++a;
                cnt[secret[i]-'0']--;
            }
        }
        for (int i = 0; i < secret.size(); ++i) {
            if (guess[i] != secret[i] && cnt[guess[i]-'0'] > 0) {
                ++b;
                cnt[guess[i]-'0']--;
            }
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};

int main() {
    Solution sol = Solution();
    string a = "1807";
    string b = "7810";
    auto res = sol.getHint(a, b);
    cout << res << endl;
    return 0;
}
