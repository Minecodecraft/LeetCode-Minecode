//
//  main.cpp
//  C
//
//  Created by 边俊林 on 2019/12/14.
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
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class CombinationIterator {
public:
    CombinationIterator(string chars, int comLen) {
        idx = 0;
        strs = vector<string> ();
        string path = "";
        makePath(path, chars, 0, comLen);
    }

    string next() {
        return strs[idx++];
    }

    bool hasNext() {
        return idx < strs.size();
    }

private:
    vector<string> strs;
    int idx;

    void makePath(string& path, const string& chars, int idx, int tot) {
        if (path.length() == tot) {
            strs.push_back(path);
            return;
        }
        if (chars.length() - idx < tot - path.size()) return;

        for (int i = idx; i < chars.length(); ++i) {
            path.push_back(chars[i]);
            makePath(path, chars, i+1, tot);
            path.pop_back();
        }
    }
};

int main() {
    CombinationIterator sol = CombinationIterator("abc", 2);

    return 0;
}
