// LC: 396 Rotate Function
// Title: Rotate Function
// Difficulty: Medium
// Date: 01 May 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sum = 0;
    int n;
    int f0;
    vector<int> dp;
    int rec(vector<int>& nums,int i){

        if(dp[i] != -1) return dp[i];
        if(i == 0){
            return f0;
        }

        int fi = rec(nums,i-1) + sum - (n * nums[(-i + n)%n]);
        return dp[i] = fi;
    }
    int maxRotateFunction(vector<int>& nums) {
         n = nums.size();

        dp.resize(n,-1);

        for(int i=0; i < nums.size(); i++){
            sum += nums[i];
            f0 += (i * nums[i]);
        }

        

        int ans = dp[0] = f0;

        for(int i=1; i < n ; i++)
            ans = max(ans,rec(nums,i));
        
        
        return ans;

        
    }
};
