//
//  main.cpp
//  418. Sentence Screen Fitting
//
//  Created by 边俊林 on 2020/1/7.
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
// Solution 1: Brute Force, 4ms, beats 90%
/*
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string pattern = "";
        for (auto& str: sentence)
            pattern += str, pattern += ' ';
        int p = 0, len = pattern.length();
        for (int i = 0; i < rows; ++i) {
            p += cols;
            if (pattern[p % len] == ' ') {
                ++p;
            } else {
                while (p > 0 && pattern[p % len] != ' ') {
                    --p;
                }
                ++p;
            }
        }
        return p / len;
    }
};
 */

// Solution 2: Memo solution, 28ms beats 30%
/*
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        unordered_map<int, int> cnt;
        int p = 0, n = sentence.size();
        for (int i = 0; i < rows; ++i) {
            if (cnt.count(p % n) > 0) {
                p += cnt[p % n];
            } else {
                int begp = p, cp = 0, tmp = 0;
                while (cp + sentence[p % n].length() <= cols) {
                    cp += sentence[p % n].length() + 1;
                    ++p;
                    ++tmp;
                }
                p = begp + (cnt[begp % n] = tmp);
            }
        }
        return p / n;
    }
};
 */



int main() {

    return 0;
}
