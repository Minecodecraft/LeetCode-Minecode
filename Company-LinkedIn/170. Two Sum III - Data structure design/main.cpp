//
//  main.cpp
//  170. Two Sum III - Data structure design
//
//  Created by 边俊林 on 2020/1/17.
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
class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {

    }

    /** Add the number to an internal data structure.. */
    void add(int number) {
        st[number]++;
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto it = st.begin(); it != st.end(); ++it) {
            if (it->first > value / 2) break;
            if (it->first * 2 == value)
                return it->second >= 2;
            if (st.find(value - it->first)!= st.end())
                return true;
        }
        return false;
    }

private:
    map<int, int> st;
};

int main() {

    return 0;
}
