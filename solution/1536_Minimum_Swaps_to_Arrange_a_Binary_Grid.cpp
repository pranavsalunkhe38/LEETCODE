// LC: 1536 Minimum Swaps to Arrange a Binary Grid
// Title: Minimum Swaps to Arrange a Binary Grid
// Difficulty: Medium
// Date: 02 March 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<pair<int,int>> vec;
    vector<pair<int,int>> temp;
public:

    bool func(vector<vector<int>>& grid){
        

        for(int i=0; i < grid.size(); i++){

            int res = 0;

            for(int j = grid[i].size()-1; j>= 0 && grid[i][j] == 0; j--){
                res++;
            }

            vec.push_back({res, i});
            temp.push_back({res, i});
        }


        auto comp = [](pair<int,int> a, pair<int,int> b){
        return a.first > b.first;
        };


        sort(temp.begin(), temp.end(),comp);

        for(int i=0; i<grid.size(); i++){
            int val = grid.size() - i - 1;

            if(val > temp[i].first){
                return false;
            }
        }

        return true;
    }

    int simulate(){

        int n = vec.size();
        int ans = 0;


        for(int i=0; i < n; i++){

            int q = n - i - 1;
            int j;

            for( j = i; j < n && vec[j].first < q; j++);

            while(j != i){
                swap(vec[j], vec[j-1]);
                ans++;
                j--;
            }

        }


        return ans;

    }

    int minSwaps(vector<vector<int>>& grid) {
        
    if(!func(grid)){
        return -1;
    }

       

        return simulate();
    }
};
