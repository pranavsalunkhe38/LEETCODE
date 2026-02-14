// LC: 799 Champagne Tower
// Title: Champagne Tower
// Difficulty: Medium
// Date: 14 Feb 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
          vector<vector<double>> glasses(query_row+2, vector<double>(query_row+2));
      
        glasses[0][0] = poured;

        for(int i = 0; i < query_row+1 ;i++){
            for(int j = 0; j <= i; j++){
                double val = glasses[i][j];
                if(val > 1.0){
                    val -= 1.0;
                    glasses[i][j] = 1.0;
                double x = val/2.0;
                glasses[i+1][j] += x;
                glasses[i+1][j+1] += x;
                }

            }
        }

        for(auto i: glasses){
            for(auto j: i){
                cout<<j<<" ";
            }
            cout<<endl;
        }

        return glasses[query_row][query_glass];
    }
};
