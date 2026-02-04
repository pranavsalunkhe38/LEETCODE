// LC: 3640 Trionic Array II
// Title: Trionic Array II
// Difficulty: Hard
// Date: 04 Feb 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long solve(vector<int>& nums, int i, int t,vector<vector<long long>>& dp){

        if(i == nums.size()){
            if(t == 3){
                return 0;
            }else{
                return LLONG_MIN/2;
            }
        }
        if(dp[i][t] != LLONG_MIN){
            return dp[i][t];
        }
        long long take = LLONG_MIN/2;
        long long skip = LLONG_MIN/2;
        
        if(t == 0){
            skip = solve(nums,i+1,t,dp);
        }
        if(t == 3){
            take = nums[i];
        }

        if(i+1 < nums.size()){

        if(t == 0 && nums[i] < nums[i+1]){
            take = max(take,nums[i] + solve(nums,i+1,1,dp));
        }else if(t == 1){
            if( nums[i] < nums[i+1]){
            take = max(take, nums[i] + solve(nums,i+1,1,dp));
            }else{
            take = max(take,nums[i] + solve(nums,i+1, 2,dp));
            }
        }else if(t == 2){
              if(nums[i] > nums[i+1]){
            take = max(take, nums[i] + solve(nums,i+1, 2,dp));
            }else{
               take = max(take, nums[i] + solve(nums,i+1,3,dp));
            }

        }else{

            if(nums[i] < nums[i+1]){
                take = max(take, nums[i] + solve(nums,i+1,3,dp));
            }

        }


        }


        return dp[i][t] = max(take,skip);
    }
    long long maxSumTrionic(vector<int>& nums) {

        vector<vector<long long>> dp(nums.size()+1,vector<long long>(4,LLONG_MIN));

        return solve(nums,0,0,dp);
        
    }
};

// memo.assign(n+1,vetor<int>(4,-1));
