//
//  main.cpp
//  1146. Snapshot Array
//
//  Created by Jaylen Bian on 10/18/20.
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
// Solution 1: Use Vector + HashMap
/*
class SnapshotArray {
    vector<map<int, int>> arr;
    int _id;

public:
    SnapshotArray(int length) {
        arr = vector<map<int, int>> (length, {{0, 0}});
        _id = 0;
    }

    void set(int index, int val) {
        arr[index][_id] = val;
    }

    int snap() {
        return _id++;
    }

    int get(int index, int snap_id) {
        auto& mp = arr[index];
        auto it = prev(mp.upper_bound(snap_id));
        return it->second;
    }
};
 */

// Solution 2: Use HashMap
class SnapshotArray {
    map<int, map<int, int>> mp;
    int _id;

public:
    SnapshotArray(int length) {
        for (int i = 0; i < length; ++i) {
            mp[i] = map<int, int> ();
            mp[i][0] = 0;
        }
        _id = 0;
    }

    void set(int index, int val) {
        mp[index][_id] = val;
    }

    int snap() {
        return _id++;
    }

    int get(int index, int snap_id) {
        auto& submp = mp[index];
        auto it = prev(submp.upper_bound(snap_id));
        return it->second;
    }
};

int main() {
    SnapshotArray sol = SnapshotArray(3);
    sol.set(0, 5);
    int snap_id = sol.snap();
    cout << "snap_id = " << snap_id << endl;
    sol.set(0, 6);
    int res = sol.get(0, 0);
    cout << "res = " << res << endl;

    return 0;
}
