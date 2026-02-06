// LC: 3634 Minimum Removals to Balance Array
// Title: Minimum Removals to Balance Array
// Difficulty: Medium
// Date: 06 Feb 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
       sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = INT_MAX;
       for(int i=0,j = 0; i < n; i++){
        
        while(j < n && (nums[j]+k-1)/k <= nums[i]){
            j++;
        }
        ans = min(ans, n - (j - i));
       }
        return ans;
    }
};
