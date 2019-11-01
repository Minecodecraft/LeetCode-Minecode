//
//  main.cpp
//  412. Fizz Buzz
//
//  Created by 边俊林 on 2019/11/1.
//  Copyright © 2019 Minecode.Link. All rights reserved.
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
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; ++i) {
            if (i % 3 == 0 && i % 5 == 0)
                res.push_back("FizzBuzz");
            else if (i % 3 == 0)
                res.push_back("Fizz");
            else if (i % 5 == 0)
                res.push_back("Buzz");
            else
                res.push_back(to_string(i));
        }
        return res;
    }
};

int main() {

    return 0;
}
