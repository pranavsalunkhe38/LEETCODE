// LC: 2812 Find The Safest Path In A Grid
// Title: Find The Safest Path In A Grid
// Difficulty: Medium
// Date: 02 July 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
       vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
public:

    int maximumSafenessFactor(vector<vector<int>>& grid) {
     
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m,INT_MAX));
        vector<vector<bool>> vis(n, vector<bool>(m,false));
       
        queue<pair<int,int>> q;

        for(auto i= 0; i < n; i++){
            for(auto j= 0; j < m; j++){
                if(grid[i][j] == 1){
                    dis[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            int x = p.first;
            int y = p.second;

            for(auto i: dir){
                int nx = x + i.first;
                int ny = y + i.second;

                if(nx < 0 || nx >= n || ny < 0 || ny >= m || dis[nx][ny] <= dis[x][y]+1) continue;

                dis[nx][ny] = dis[x][y]+1;
                q.push({nx,ny});
            }
        }

        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({dis[0][0],{0,0}});
        vis[0][0] = true;

        while(!pq.empty()){
            auto ds = pq.top().first;
            auto x = pq.top().second.first;
            auto y = pq.top().second.second;
            pq.pop();

            if(x == n-1 && y == m-1) return ds;

            for(auto i: dir){
                int nx = x + i.first;
                int ny = y + i.second;

                if(nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] == true || grid[nx][ny] == 1)              
                    continue;

                int ds1 = dis[nx][ny];
                vis[nx][ny] = true;
                pq.push({min(ds,ds1),{nx,ny}});



            }
        }



        return 0;


        
    }
};
