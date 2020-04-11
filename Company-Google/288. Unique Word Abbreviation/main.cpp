//
//  main.cpp
//  288. Unique Word Abbreviation
//
//  Created by Jaylen Bian on 4/10/20.
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
// Solution 1: faster solution
/*
class ValidWordAbbr {
private:
    vector<vector<unordered_map<int, int>>> vec;
    unordered_set<string> strs;

public:
    ValidWordAbbr(vector<string>& words) {
        vec = vector<vector<unordered_map<int, int>>> (26, vector<unordered_map<int, int>> (26) );
        for (auto word: words) {
            if (word.length() < 2) continue;
            if (strs.count(word) == 0) {
                vec[word[0]-'a'][word[word.length()-1]-'a'][word.length()-2]++;
                strs.insert(word);
            }
        }
    }

    bool isUnique(string word) {
        if (word.length() < 2)
            return true;
        int cnt = vec[word[0]-'a'][word[word.length()-1]-'a'][word.length()-2];
        if (cnt == 0) return true;
        if (cnt == 1) return strs.count(word);
        return false;
    }
};
 */

// Solution 2: Easier solution with only 8 lines of code
class ValidWordAbbr {
    unordered_map<string, unordered_set<string>> mp;

public:
    ValidWordAbbr(vector<string>& words) {
        for (auto& w: words) {
            string key = w.length() > 2 ? w[0] + to_string(w.length()-2) + w.back() : w;
            mp[key].insert(w);
        }
    }

    bool isUnique(string w) {
        string key = w.length() > 2 ? w[0] + to_string(w.length()-2) + w.back() : w;
        return mp[key].count(w) == mp[key].size();
    }
};

int main() {
    vector<string> words = {
        "deer","door","cake","card"
    };
    ValidWordAbbr sol = ValidWordAbbr(words);
    cout << sol.isUnique("dear") << endl;

    return 0;
}
