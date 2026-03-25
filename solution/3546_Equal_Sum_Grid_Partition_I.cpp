// LC: 3546 Equal Sum Grid Partition I
// Title: Equal Sum Grid Partition I
// Difficulty: Medium
// Date:25 March 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // write here
};
class Solution {
public:

    bool H(vector<long long>& row){
        int n = row.size();
        vector<long long> suff(n);

        for(int i = n-1; i >= 0; i--){
            if(i == n-1) suff[i] = row[i];
            else{
                suff[i] = row[i] + suff[i+1];
            }
        }
        long long pre = 0;
        for(int i=0 ;i < n; i++){
            if(pre == suff[i]) return true;
            pre += row[i];
        }

        return false;

    }
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<long long> row,col;

        for(int i=0; i < n; i++){
            long long temp = 0;
            for(int j=0; j < m; j++){
                temp += grid[i][j];

            }
            row.push_back(temp);
        }

        for(int i=0; i < m; i++){
            long long temp = 0;
            for(int j=0; j < n; j++){
                temp += grid[j][i];

            }
            col.push_back(temp);
        }
        return H(row) || H(col);
    }
};