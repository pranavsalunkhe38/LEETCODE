// LC: 1727 Largest Submatrix With Rearrangements
// Title: Largest Submatrix With Rearrangements
// Difficulty: Medium
// Date: 17 March 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 1){
                    matrix[i][j] += matrix[i+1][j];
                }

                
            }
        }

       int ans = 0;

        for(auto i: matrix){
            sort(i.begin(), i.end(),greater<int>());
            
            for(int j =0; j < m; j++){
                int val = (j+1) * i[j];
                if(val == 0) break;
                ans = max(ans, val);
            }
            // cout<<endl;
        }

        return ans;
        
    }
};