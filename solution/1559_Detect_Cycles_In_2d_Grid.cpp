// LC: 1559 Detect Cycles In 2d Grid
// Title: Detect Cycles In 2d Grid
// Difficulty: Medium
// Date: 26 April 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

    bool isParent(pair<int,int> node1, pair<int,int> node2){
        return (node1.first == node2.first && node1.second == node2.second);
    }
    bool rec(vector<vector<char>>& grid, int i, int j, pair<int,int> parent, vector<vector<int>>& vis){
        if(vis[i][j] == true) return true;

        vis[i][j] = true;


        bool ans = false;

        for(int k=0; k < dir.size(); k++){
            int x = i + dir[k][0];
            int y = j + dir[k][1];

            if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[i][j] != grid[x][y] || isParent({x,y},parent))
            {
                continue;
            }

            ans = rec(grid,x,y,{i,j}, vis);

            if(ans == true) break;
        }

        return ans;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, false));

        for(int i=0; i < n; i++){
            for(int j=0; j < m; j++){

                if(!vis[i][j] && rec(grid, i, j, {-1,-1},vis)){
                    return true;

                }

            }
        }

        return false;
        
    }
};