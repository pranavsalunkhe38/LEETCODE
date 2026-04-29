// LC: 3225 Maximum Score From Grid Operations
// Title: Maximum Score From Grid Operations
// Difficulty: Hard
// Date: 29 April 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n,m;
    vector<vector<long long>> pre;
    vector<vector<vector<long long>>> dp;
public:
    long long rec(vector<vector<int>>& grid, int x, int y, int z){
        // cout<<x<<" "<<y<<" "<<z<<endl;
        if(dp[x][y+1][z+1] != -1) return dp[x][y+1][z+1];
        if(x == grid[0].size()){
            return 0;
        }

        long long ans = 0;
        for(int i=-1; i < n; i++){
            int val = max(y,z);
            long long res = 0;
            
            if(i > val && x > 0){
                
                if(val == -1){
                    res = pre[i][x-1];
                }else{
                    res = pre[i][x-1] - pre[val][x-1];
                }

            }
            
            else if(i < y){
                if(i == -1){
                    res = pre[y][x];
                }else{
                    res = pre[y][x] - pre[i][x];
                }

            }
            ans = max(ans, res + rec(grid,x+1,i,y));
            
            // rec(grid,x+1,i,y);
        }

        return dp[x][y+1][z+1] = ans;


    }
    long long maximumScore(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        pre.resize(n, vector<long long>(m));
        dp.resize(m+1, vector<vector<long long>>(n+1, vector<long long>(n+1,-1)));

        for(int i=0; i < m; i++){
            for(int j=0; j < n; j++){
                if(j == 0){
                    pre[j][i] = (long long)grid[j][i];
                    continue;
                }
                pre[j][i] = pre[j-1][i] + (long long)grid[j][i];
            }
        }

        // for(auto i: pre){
        //     for(auto j: i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }

        long long ans = rec(grid, 0,-1,-1);
        

        return ans;
    }
};
