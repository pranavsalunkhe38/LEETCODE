// LC: 2946 Matrix Similarity After Cyclic Shifts
// Title: Matrix Similarity After Cyclic Shifts
// Difficulty: Easy
// Date: 27 March 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {

        k = k % mat[0].size();

        vector<vector<int>> mod = mat;

        for(int i=0 ; i < mat.size(); i++){
            auto& x = mod[i];

            reverse(x.begin(), x.begin()+k);
            reverse(x.begin()+k, x.end());
            reverse(x.begin(), x.end());

            for(auto i: x){
                cout<<i<<" ";
            }
            cout<<endl;
        }



        return mod == mat;
        
    }
};
