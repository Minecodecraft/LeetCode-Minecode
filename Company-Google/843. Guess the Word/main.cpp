//
//  main.cpp
//  843. Guess the Word
//
//  Created by 边俊林 on 2020/1/9.
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
// Solution 1: Random guess, O(n) time complexity
/*
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        random_shuffle(words.begin(), words.end());
        int cnt = 0;
        for (int i = 0; i < 10; ++i) {
            string& cur = words.back();
            cnt = master.guess(cur);
            if (cnt == 6) return;

            vector<string> newWords;
            for (auto& word: words) {
                if (word != cur && match(cur, word) == cnt) {
                    newWords.push_back(word);
                }
            }
            words = newWords;
        }
    }

private:
    int match(string a, string b) {
        int cnt = 0;
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] == b[i]) ++cnt;
        }
        return cnt;
    }
};
 */

// Solution 2: Minimax algorithm, O(n^2) time complexity
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for (int i = 0; i < 10; ++i) {
            unordered_map<string, int> same;
            for (auto& str1: wordlist) {
                for (auto& str2: wordlist) {
                    if (match(str1, str2) == 0)
                        same[str1]++;
                }
            }
            pair<string, int> minimax = {wordlist[0], INT_MAX};
            for (auto& str: wordlist) {
                if (same[str] < minimax.second)
                    minimax = {str, same[str]};
            }
            int res = master.guess(minimax.first);
            if (res == 6) return;
            vector<string> newlist;
            for (auto& str: wordlist)
                if (str != minimax.first && match(minimax.first, str) == res)
                    newlist.push_back(str);
            wordlist = newlist;
        }
    }

private:
    int match(string& a, string& b) {
        int cnt = 0;
        for (int i = 0; i < a.length(); ++i)
            if (a[i] == b[i]) ++cnt;
        return cnt;
    }
};

int main() {

    return 0;
}
