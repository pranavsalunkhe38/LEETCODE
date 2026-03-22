// LC: 1886 Determine Whether Matrix Can Be Obtained By Rotation
// Title: Determine Whether Matrix Can Be Obtained By Rotation
// Difficulty: Easy
// Date: 22 March 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>>& mat){
    int n = mat.size();
        vector<vector<int>> ans(n, vector<int>(n,0));

        for(int i=0; i < n; i++){
            for(int j=0 ; j < n; j++){
                ans[j][n-i-1] = mat[i][j];
            }
        }

        return ans;

    
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {

        if(mat == target){
            return true;
        }

        mat = rotate(mat);

         if(mat == target){
            return true;
        }

                mat = rotate(mat);

         if(mat == target){
            return true;
        }

                mat = rotate(mat);

         if(mat == target){
            return true;
        }

        

        return false;
        
    }
};
