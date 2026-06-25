// LC: 3737 Count Subarrays With Majority Element I
// Title: Count Subarrays With Majority Element I
// Difficulty: Medium
// Date: 25 June 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        int ans = 0;
        int n = nums.size();

        for(int i=0; i < n; i++){
            int cnt = 0;
            for(int j = i; j < n; j++){
                // cout<<nums[j]<<" ";

                cnt += (nums[j] == target);

                ans += (cnt * 2) > (j-i+1);
            }
            cout<<endl;
        }
        

        return ans;
    }
};
