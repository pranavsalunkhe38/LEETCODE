// LC: 2906 Construct Product Matrix
// Title: Construct Product Matrix
// Difficulty: Medium
// Date: 24 March 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<long long>> pre(n, vector<long long>(m,1));
        vector<vector<long long>> suf(n, vector<long long>(m,1));
        vector<vector<int>> ans(n, vector<int>(m,1));

        for(int i=0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0) {}
                else{
                if(j == 0) pre[i][j] = pre[i-1][m-1] * grid[i-1][m-1];
                else pre[i][j] = pre[i][j-1] * grid[i][j-1];
                }

                pre[i][j] = pre[i][j] % mod;
            }
        }


          for(int i=n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(i == n-1 && j == m-1) {}
                else{
                if(j == m-1) suf[i][j] = suf[i+1][0] * grid[i+1][0];
                else suf[i][j] = suf[i][j+1] * grid[i][j+1];
                }

                
                suf[i][j] = suf[i][j] % mod;
                
                }
        }

         for(int i=0; i < n; i++){
            for(int j = 0; j < m; j++)
            {

                ans[i][j] = (pre[i][j] * suf[i][j])%mod;
         
            }
        }

        return ans;
        
    }
};
