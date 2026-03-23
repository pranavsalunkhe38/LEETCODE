// LC: 1594 Maximum Non Negative Product in a Matrix
// Title: Maximum Non Negative Product in a Matrix
// Difficulty: Medium
// Date: 23 Marcg

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1000000007;
    int maxProductPath(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<long long>> mx(n, vector<long long>(m,INT_MIN));
        vector<vector<long long>> mn(n, vector<long long>(m,INT_MAX));

        mx[0][0] = grid[0][0];
          mn[0][0] = grid[0][0];

        for(int i = 0 ; i < n; i++){
            for(int j=0; j < m; j++){
                //right

                if(j+1 < m)
             {       mx[i][j+1] = max( {mx[i][j+1], mx[i][j] * grid[i][j+1], mn[i][j] * grid[i][j+1] });
                     mn[i][j+1] = min( {mn[i][j+1], mx[i][j] * grid[i][j+1], mn[i][j] * grid[i][j+1] });
            }
                if(i+1 < n)
                {
                    mx[i+1][j] = max( {mx[i+1][j], mx[i][j] * grid[i+1][j], mn[i][j] * grid[i+1][j] });
                    mn[i+1][j] = min( {mn[i+1][j], mx[i][j] * grid[i+1][j], mn[i][j] * grid[i+1][j] });
                }
            }
        }

        return mx[n-1][m-1] < 0 ? -1: mx[n-1][m-1] % mod;
        
    }
};