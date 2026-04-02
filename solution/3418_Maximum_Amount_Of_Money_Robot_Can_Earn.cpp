// LC: 3418 Maximum Amount Of Money Robot Can Earn
// Title: Maximum Amount Of Money Robot Can Earn
// Difficulty: Medium
// Date: 02 April 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rec(vector<vector<int>>& coins , int i, int j, int pow,vector<vector<vector<int>>>& dp){
        if(i < 0 || j < 0) return 0;

        if(dp[i][j][pow] != -1) return dp[i][j][pow];
        int ans = INT_MIN;

        if(i == 0 && j == 0) {
            ans = max(ans,coins[i][j]);

            if(coins[i][j] < 0 && pow > 0){
                ans = max(ans,0);
            }
            return dp[i][j][pow] = ans;
        }
        if(i-1 >= 0) ans = max(ans,coins[i][j] + rec(coins,i-1,j,pow,dp));
        if(j-1 >= 0) ans = max(ans,coins[i][j] + rec(coins,i,j-1,pow,dp));

        if(coins[i][j] < 0 && pow > 0){
            if(i-1 >= 0) ans = max(ans, rec(coins,i-1,j,pow-1, dp));
            if(j-1 >= 0) ans = max(ans, rec(coins,i,j-1,pow-1,dp));
        }

        return dp[i][j][pow] = ans;
    }
    int maximumAmount(vector<vector<int>>& coins) {

        int m = coins.size();
        int n = coins[0].size();

        vector<vector<vector<int>>> dp (m, vector<vector<int>>(n,vector<int>(3,-1)));

        for(int i=0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int pow=0; pow <= 2; pow++){
                   
                    int ans = INT_MIN;
                    
                    if(i == 0 && j == 0) {
                        ans = max(ans,coins[i][j]);

                        if(coins[i][j] < 0 && pow > 0)
                         ans = max(ans,0);
                    }else{

                        if(i-1 >= 0) ans = max(ans,coins[i][j] + dp[i-1][j][pow]);
                        if(j-1 >= 0) ans = max(ans,coins[i][j] + dp[i][j-1][pow]);

                        if(coins[i][j] < 0 && pow > 0){
                            if(i-1 >= 0) ans = max(ans, dp[i-1][j][pow-1]);
                            if(j-1 >= 0) ans = max(ans, dp[i][j-1][pow-1]);
                        }

                    }
                
                 dp[i][j][pow] = ans;
                }
                
            }
        }

        return dp[m-1][n-1][2];
        
    }
};
