// LC: 1861 Rotating The Box
// Title: Rotating The Box
// Difficulty: Medium
// Date: 06 May 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(vector<char>& row){

        int n = row.size();
        int t = n-1;

        for(int i=n-1; i >= 0 && t >= 0; i--){
            if(row[i] == '#') {
                row[t--] = row[i];
                if(t+1 != i)
                    row[i] = '.';
            }

            if(row[i] == '*'){
                t = i-1;
            }

        }

    }
    void fall(vector<vector<char>>& boxGrid){

        for(auto& row: boxGrid){
            solve(row);
           
            }

    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

        
        fall(boxGrid);
        int n = boxGrid.size();
        int m = boxGrid[0].size();

        
        vector<vector<char>> ans(m, vector<char>(n));

        for(auto i: boxGrid){
            for(auto j: i){
                cout<<j<<" ";
            }
            cout<<endl;
        }

        for(int i=0; i < m; i++){
            for(int j=0; j < n; j++){
                ans[i][j] = boxGrid[n-j-1][i];
            }
        }

        return ans;
        
    }
};