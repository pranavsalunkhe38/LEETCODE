// LC: 1391 Check If There Is A Valid Path In A Grid
// Title: Check If There Is A Valid Path In A Grid
// Difficulty: Medium
// Date: 27 April 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int n;
int m;
vector<vector<int>> vis;
    map<int,vector<pair<int,int>>> next = {
        {1, {{0,1},{0,-1}}},
        {2, {{1,0},{-1,0}}},
        {3, {{1,0},{0,-1}}},
        {4, {{1,0},{0,1}}},
        {5, {{-1,0},{0,-1}}},
        {6, {{-1,0},{0,1}}},
        };

    bool canMove(int i, int j, int x, int y, vector<vector<int>>& grid){
       
       if(x < 0 || y < 0 || x >= n || y >= m){
                return false;
            }

        auto mov = next[grid[x][y]];
        for(auto m: mov){
            int nx = x + m.first;
            int ny = y + m.second;
            if(nx == i && ny == j){
                return true;
            }
        }

         

        return false;
    }
    bool rec(vector<vector<int>>& grid, int i, int j){
      
      
        if(i == n-1 && j == m-1){
            return true;
        }

        if(vis[i][j] == true){
            return false;
        }

        //   cout<<"func "<<i<<" "<<j<<endl;


        vis[i][j] = true;
        auto mov = next[grid[i][j]];

        for(auto m : mov){
            int x = i + m.first;
            int y = j + m.second;
            // cout<<"func "<<i<<" "<<j<<"-"<<x<<"*"<<y<<endl;



            if(canMove( i, j, x, y, grid)){
                if( rec(grid, x,y) == true){
                    return true;
                }

            }
        }


        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vis.resize(n, vector<int>(m,false));
        

        return rec(grid, 0,0);

        // return false;
        
    }
};
