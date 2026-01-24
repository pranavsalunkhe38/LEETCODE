// LC: 1877 Minimize Maximum Pair Sum in Array
// Title: Minimize Maximum Pair Sum in Array
// Difficulty: Easy
// Date: 24 Jan 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        for(int i=0; i < n/2;i++){
            ans = max(ans, nums[i] + nums[n-i-1]);
        }

        return ans;
    }
};
