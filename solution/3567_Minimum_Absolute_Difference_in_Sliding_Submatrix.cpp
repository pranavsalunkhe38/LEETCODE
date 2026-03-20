// LC: 3567 Minimum Absolute Difference in Sliding Submatrix
// Title: Minimum Absolute Difference in Sliding Submatrix
// Difficulty: Medium
// Date: 20 March 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int fun(vector<vector<int>>& grid, int k, int x, int y){
        // cout<<x<<" "<<y<<endl;
        vector<int> temp;

        for(int i=0; i < k;i++){
            for(int j=0; j < k;j++){

                temp.push_back(grid[x+i][y+j]);

            }
        }

        sort(temp.begin(), temp.end());

        int ans = INT_MAX;

        for(int i=1; i < temp.size(); i++){
            auto val = temp[i] - temp[i-1];
            if(val == 0) continue;
            ans = min(ans, val);
        }

        // for(auto i: temp){
        //     cout<<i<<" ";
        // }
        // cout<<endl;

        return ans == INT_MAX ? 0 : ans;
        
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans;

        for(int i=0; i <= grid.size()-k; i++){
            vector<int> temp;
            for(int j=0; j <= grid[0].size()-k; j++){
                temp.push_back(fun(grid,k,i,j));
            }
            ans.push_back(temp);
        }

        return ans;
        
    }
};