//
//  main.cpp
//  42. Trapping Rain Water
//
//  Created by 边俊林 on 2018/7/17.
//  Copyright © 2018 minecode. All rights reserved.
//

/* -------------------------------------------------------------- *\
 https://leetcode-cn.com/problems/trapping-rain-water/description/
\* -------------------------------------------------------------- */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//

/// Tips:
//

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = (int)height.size()-1;
        int sum = 0;
        
        while (l < r) {
            int minn = min(height[l], height[r]);
            if (height[l] == minn) {
                ++l;
                while (l<r && height[l]<minn) {
                    sum += minn - height[l++];
                }
            } else {
                --r;
                while (l<r && height[r]<minn) {
                    sum += minn - height[r--];
                }
            }
        }
        return sum;
    }
};

// Tool Function List
void printVector(vector<int> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printf("%c%d", it==v.begin() ? '\0' : ' ', *it);
    }
    printf("]\n");
}
void printVectors(vector<vector<int>> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printVector(*it);
    }
    printf("]\n");
}

int main() {
    
    Solution sol = Solution();
    
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    size_t size = sizeof(arr) / sizeof(int);
    vector<int> v = vector<int>(arr, arr+size);
    
    int res = sol.trap(v);
    cout << res << endl;
    
    return 0;
}
