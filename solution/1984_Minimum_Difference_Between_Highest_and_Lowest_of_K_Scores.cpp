// LC: 1984 Minimum Difference Between Highest and Lowest of K Scores
// Title: Minimum Difference Between Highest and Lowest of K Scores
// Difficulty: Easy
// Date: 25 Jan 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for(int i=0; i <= nums.size()-k;i++){
            // cout<<nums[i+k-1]<<"-"<<nums[i]<<endl;
            ans = min(ans, nums[i+k-1] - nums[i]);
        }

        return ans == INT_MAX ? 0: ans;
        
    }
};
