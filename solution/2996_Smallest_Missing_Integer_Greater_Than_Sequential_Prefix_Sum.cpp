// LC: 2996 Smallest Missing Integer Greater Than Sequential Prefix Sum
// Title: Smallest Missing Integer Greater Than Sequential Prefix Sum
// Difficulty: Easy
// Date: 11 August 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int mxlen = 1;
        int mxsum =  nums[0];
       
        for(int i=1; i < n; i++){
           if(nums[i] - nums[i-1] != 1) break;
           mxsum += nums[i];
        }
        sort(nums.begin(),nums.end());

        cout<<mxsum<<endl;

        for(auto i: nums){
            if(i < mxsum) continue;

            if(i == mxsum) mxsum++;

        }

        return mxsum;
        
    }
};
