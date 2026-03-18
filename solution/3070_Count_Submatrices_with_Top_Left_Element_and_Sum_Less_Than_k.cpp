// LC: 3070 Count Submatrices with Top-Left Element and Sum Less Than k
// Title: Count Submatrices with Top-Left Element and Sum Less Than k
// Difficulty: Medium
// Date: 18 March 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();
         int ans = 0;

        vector<vector<int>> pre(m, vector<int>(n,0));

        for(int i=0 ; i < m; i++){
            int p = 0;
            for(int j=0; j < n; j++){

                int x = i != 0 ? pre[i-1][j]: 0;
                p = p + grid[i][j];

                pre[i][j] = x + p;

                if(pre[i][j] <= k){
                    ans++;
                }else{
                    break;
                }

            }
        }

        // for(auto i: pre){
        //     for(auto j: i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }

       
        return ans;
        
    }
};