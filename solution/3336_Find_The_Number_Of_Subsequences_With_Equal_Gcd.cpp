// LC: 3336 Find The Number Of Subsequences With Equal Gcd
// Title: Find The Number Of Subsequences With Equal Gcd
// Difficulty: HARD
// Date: 15 July 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int mod = 1000000007;
public:
    int rec(vector<int>& nums, int i, int gcd1, int gcd2, vector<vector<vector<int>>>& dp){
        if(i == nums.size()){
            bool x = (gcd1 != 0) && (gcd2 != 0);
            bool y = (gcd1 == gcd2);

            return x && y ? 1: 0;
        }

        if(dp[i][gcd1][gcd2] != -1) return dp[i][gcd1][gcd2] % mod;

        int a = rec(nums,i+1,gcd1,gcd2,dp) % mod;
        a = (a + rec(nums,i+1, gcd(gcd1, nums[i]),gcd2,dp)) % mod;
        a = (a + rec(nums,i+1, gcd1, gcd(gcd2, nums[i]),dp)) % mod;

        return dp[i][gcd1][gcd2] = (a % mod);
    }
    int subsequencePairCount(vector<int>& nums) {

        vector<vector<vector<int>>> dp(201, vector<vector<int>>(201, vector<int>(201,-1)));


        return rec(nums, 0,0,0,dp) % mod;
        
    }
};