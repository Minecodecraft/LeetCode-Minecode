//
//  main.cpp
//  284. Peeking Iterator
//
//  Created by Jaylen Bian on 12/14/20.
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
class Iterator {
    struct Data;
    Data* data;
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

// Solution 1: Simple solution
/**
class PeekingIterator : public Iterator {
    int current;
    bool exist;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        exist = Iterator::hasNext();
        if (exist)
            current = Iterator::next();
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return current;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int tmp = current;
        exist = Iterator::hasNext();
        if (exist)
            current = Iterator::next();
        return tmp;
    }

    bool hasNext() const {
        return exist;
    }
};
 */

// Solution 2: Use copy constructor
class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) { }

    int peek() {
        return Iterator(*this).next();
    }
};

int main() {

    return 0;
}
