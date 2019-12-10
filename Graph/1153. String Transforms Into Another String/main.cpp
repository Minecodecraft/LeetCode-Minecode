//
//  main.cpp
//  1153. String Transforms Into Another String
//
//  Created by 边俊林 on 2019/12/10.
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
class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2) return true;
        unordered_map<char, char> match;
        for (int i = 0; i < str1.length(); ++i) {
            if (match.count(str1[i]) && match[str1[i]] != str2[i])
                return false;
            match[str1[i]] = str2[i];
        }
        return unordered_set(str2.begin(), str2.end()).size() < 26;
    }
};

int main() {

    return 0;
}
