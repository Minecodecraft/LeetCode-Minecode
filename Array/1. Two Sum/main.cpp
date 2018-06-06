//
//  main.cpp
//  1. Two Sum
//
//  Created by 边俊林 on 2018/6/6.
//  Copyright © 2018 minecode. All rights reserved.
//

#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

/// Solution:
// Use hashtable, the key is value of the vector "nums", and the value is the index of the item in vector "nums"
// So we can query value directly, and then the value we get is the index of it in the source vector.

/// Tips:
// unordered_map: inner implement a hashtable. So compared to map, it unordered, but faster that map.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash = {{nums[0], 0}};
        
        for (int i = 1; i < nums.size(); ++i) {
            if (hash.find(target-nums[i]) != hash.end()) {
                vector<int> res = {hash[target-nums[i]], i};
                return res;
            }
            hash[nums[i]] = i;
        }
        return vector<int>();
    }
};

void printVector(vector<int> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printf("%c%d", it==v.begin() ? '\0' : ' ', *it);
    }
    printf("]\n");
}

int main() {
    Solution sol = Solution();
    
    int arr[] = {2, 7, 11, 15};
    size_t size = sizeof(arr) / sizeof(int);
    vector<int> v = vector<int>(arr, arr+size);
    int target = 9;
    
    auto res = sol.twoSum(v, target);
    
    printVector(res);
    return 0;
}
