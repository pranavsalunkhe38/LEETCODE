// LC: 1406 Stone Game Iii
// Title: Stone Game Iii
// Difficulty: HARD
// Date: 03 August 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rec(vector<int>& stoneValue, int i, bool turn,vector<vector<int>>& dp){
       
        if(i >= stoneValue.size()){
            return 0;
        }

        if(dp[i][turn] != -1) return dp[i][turn];
        int ans = turn == true ? INT_MIN: INT_MAX;
        int temp = 0;
        for(int j=0; j < 3; j++){
            
            if((i+j) >= stoneValue.size()) continue;

            if(turn == true){
                temp += stoneValue[i+j];
                ans = max(ans, temp + rec(stoneValue,i+j+1,!turn,dp));
            }else{
                temp -= stoneValue[i+j];
                ans = min(ans, temp + rec(stoneValue,i+j+1,!turn,dp));

            }

        }
        return dp[i][turn] = ans;

    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));



        int ans = rec(stoneValue, 0,true,dp);

        if(ans == 0) return "Tie";

        if(ans < 0) return "Bob";

        return "Alice";
        
    }
};