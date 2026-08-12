// LC: 2958 Length Of Longest Subarray With At Most K Frequency
// Title: Length Of Longest Subarray With At Most K Frequency
// Difficulty: Medium
// Date: 12 August 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int ans = INT_MIN;
        map<int,int> mp;
        for(int r=0;r < n; r++){
            mp[nums[r]]++;

            while(mp[nums[r]] > k){
                mp[nums[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);

        }

        return ans;
        
    }
};
