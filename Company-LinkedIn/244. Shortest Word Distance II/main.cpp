//
//  main.cpp
//  244. Shortest Word Distance II
//
//  Created by 边俊林 on 2020/1/16.
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
class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i)
            pos[words[i]].push_back(i);
    }

    int shortest(string word1, string word2) {
        int i = 0, j = 0, dst = INT_MAX;
        while (i < pos[word1].size() && j < pos[word2].size()) {
            dst = min(dst, abs(pos[word1][i]-pos[word2][j]));
            pos[word1][i] < pos[word2][j] ? i++ : j++;
        }
        return dst;
    }

private:
    unordered_map<string, vector<int>> pos;
};

int main() {

    return 0;
}
