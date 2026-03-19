// LC: 3212 Count Submatrices With Equal Frequency of X and Y
// Title: Count Submatrices With Equal Frequency of X and Y
// Difficulty: Medium
// Date: 19 March 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {

        
        int m = grid.size();
        int n = grid[0].size();
         int ans = 0;

        vector<vector<int>> pre(m, vector<int>(n,0));
         vector<vector<bool>> vis(m, vector<bool>(n,false));

        for(int i=0 ; i < m; i++){
            int p = 0;
            bool b = false;
            for(int j=0; j < n; j++){

                int x = i != 0 ? pre[i-1][j]: 0;
                bool a = i != 0 ? vis[i-1][j]: false;
                int val = 0;
                bool c= false;

                if(grid[i][j] == 'X'){
                    val = 1;
                    c = true;
                }else if(grid[i][j] == 'Y'){
                    val = -1;
                    c = true;
                }
                p = p + val;
                b = b | c;

                pre[i][j] = x + p;
                vis[i][j] = a | b;

                // cout<<grid[i][j]<<" ";

                if(pre[i][j] == 0 && vis[i][j] == true){
                    ans++;
                }

            }
            // cout<<endl;
        }

        
        // for(auto i: grid){
        //     for(auto j: i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;

        // for(auto i: vis){
        //     for(auto j: i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;

        // for(auto i: pre){
        //     for(auto j: i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }

       
        return ans;
        
    }
};
