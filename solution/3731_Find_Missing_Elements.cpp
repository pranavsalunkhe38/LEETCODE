// LC: 3731 Find Missing Elements
// Title: Find Missing Elements
// Difficulty: Easy
// Date: 04 August 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
       int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = nums[0];
        int r = nums[n-1];

        int ptr = 0;
        vector<int> ans;
        for(int i=l; i < r; i++){
            if(ptr < n && nums[ptr] == i){
                ptr++;
                continue;
            }

            ans.push_back(i);
        }

        return ans;
        
        
    }
};