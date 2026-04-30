// LC: 3742 Maximum Path Score In A Grid
// Title: Maximum Path Score In A Grid
// Difficulty: Medium
// Date: 30 April 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int m;
    int dir[2][2] = {{0,1},{1,0}};
    vector<vector<vector<int>>> dp;
    
    int rec(vector<vector<int>>& grid, int k, int i, int j){
        
        int score = grid[i][j];
        int cost = (score > 0) ? 1 : 0;
        k -= cost;

        if(k < 0){
            return INT_MIN;
        }
        
        if(i == n-1 && j == m-1){
            return score;
        }

        if(dp[k][i][j] != -1) return dp[k][i][j];

        int ans = INT_MIN;
        for(auto& mov: dir){
            int x = i + mov[0];
            int y = j + mov[1];
          
            if( x >= n || y >= m){
                continue;
            }

            int recres = rec(grid, k,x,y);

            

            if(recres != INT_MIN)
                ans = max(ans, score + recres);

            

        }

        return dp[k][i][j] = ans;


    }
    int maxPathScore(vector<vector<int>>& grid, int k) {

        n = grid.size();
        m = grid[0].size();

        dp.resize(k+1, vector<vector<int>>(n+1, vector<int>(m+1,-1)));

        rec(grid,k,0,0);

        int ans = rec(grid,k,0,0);

        if(ans == INT_MIN) return -1;
        return ans;
        
    }
};
