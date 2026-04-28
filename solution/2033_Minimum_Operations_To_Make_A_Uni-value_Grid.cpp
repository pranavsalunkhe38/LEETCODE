// LC: 2033 Minimum Operations To Make A Uni-value Grid
// Title: Minimum Operations To Make A Uni-value Grid
// Difficulty: Medium
// Date: 28 April 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        int ans=0;
        vector<int> vec;


        for(auto& i: grid){
            for(auto& j: i){
                vec.push_back(j);
            }
        }

        sort(vec.begin(), vec.end());

        int mid = vec[(vec.size()-1)/2];

        for(auto& i: vec){
            

            int val = abs(i - mid);
            if(val % x != 0){
                return -1;
            }
            ans += val/x;
        }

        return ans;
        
    }
};