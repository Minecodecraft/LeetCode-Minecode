//
//  main.cpp
//  Template
//
//  Created by 边俊林 on 2019/7/12.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
    https://leetcode-cn.com/problems/Sample/description/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//

/// Tips:
//

// Tool Function List
void printVector(vector<string> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printf("%c", it==v.begin() ? '\0' : ' ');
        cout << *it << endl;
    }
    printf("]\n");
}
void printVectors(vector<vector<string>> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printVector(*it);
    }
    printf("]\n");
}

int main() {

    return 0;
}
