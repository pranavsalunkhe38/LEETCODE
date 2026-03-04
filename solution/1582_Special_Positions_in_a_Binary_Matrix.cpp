// LC: 1582 Special Positions in a Binary Matrix
// Title: Special Positions in a Binary Matrix
// Difficulty: Easy
// Date: 04 March 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<int> row(m), col(n);

        for(int i=0; i < m; i++){
            for(int j=0; j < n; j++){

                if(mat[i][j] == 1){

                    row[i]++;
                    col[j]++;

                }
            }
        }


        // cout<<" ";
        // for(auto i: col){
        //     cout<<i<<" ";
        // }
        // cout<<endl;

        // for(auto i: row){
        //     cout<<i<<endl;
        // }

        int ans = 0;

        for(int i=0; i < m; i++){
            for(int j=0;j<n;j++){
                ans += (row[i] == 1 && col[j] == 1 && mat[i][j] == 1);
            }
        }

        return ans;
        
    }
};
