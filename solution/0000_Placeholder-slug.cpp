// LC: 0000 Placeholder-slug
// Title: Placeholder-slug
// Difficulty:
// Date: 04 May 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void print(vector<vector<int>>& matrix){
        for(auto& i: matrix){
            for(auto& j: i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        for(int i=0; i < n; i++){
            for(int j= i; j < n; j++){
                // cout<<i<<" "<<j<<endl;
                swap(matrix[i][j], matrix[j][i]);
                // print(matrix);
            }

            reverse(matrix[i].begin(), matrix[i].end());
        }
        
    }
};