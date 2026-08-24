// LC: 1872 Stone Game Viii
// Title: Stone Game Viii
// Difficulty: HARD
// Date: 24 August 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    vector<int> dp;
public:
    int solve(vector<int>& pre,int i){
        if(dp[i] != -1) return dp[i];

        if(i == pre.size()-1) return pre[i];

        int take = pre[i] - solve(pre,i+1);
        int skip = solve(pre,i+1);

        return dp[i] = max(take,skip);
        
    }
    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        vector<int> pre(n,0);
        dp.resize(n+1, -1);

        for(int i=0; i < n; i++){
            if(i == 0){
                pre[i] = stones[i];
                continue;
            }
            pre[i] = stones[i] + pre[i-1];
        }

        for(int i=n-1; i >= 1; i--){

            if(i == n-1) {
                dp[i] = pre[i];
                continue;
            }

            dp[i] = max(dp[i+1], pre[i] - dp[i+1]);

        }

        return dp[1];

    
        
    }
};
