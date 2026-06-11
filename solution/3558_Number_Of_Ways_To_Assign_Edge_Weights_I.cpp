// LC: 3558 Number Of Ways To Assign Edge Weights I
// Title: Number Of Ways To Assign Edge Weights I
// Difficulty: Medium
// Date: 11 June 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
    static constexpr int mod = 1e9 + 7;

    int qpow(int x, int y) {
        int res = 1;
        for (; y; y >>= 1) {
            if (y & 1) {
                res = 1ll * res * x % mod;
            }
            x = 1ll * x * x % mod;
        }
        return res;
    }

    int dfs(vector<vector<int>>& grid, vector<bool>& vis, int i){
        vis[i] = true;

        int ans = 0;
        for(auto j: grid[i]){
            if(vis[j] == true) continue;
            ans = max(ans, dfs(grid,vis, j));
        }

        return 1 + ans;

    }
    

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<vector<int>> grid(n);
        vector<bool> vis(n, false);

        for(auto edge: edges){
            grid[edge[0]-1].push_back(edge[1]-1);
            grid[edge[1]-1].push_back(edge[0]-1);
        }

        int depth = dfs(grid, vis, 0)-1;
        cout<<depth<<endl;

        return qpow(2, depth - 1);
    }
};
