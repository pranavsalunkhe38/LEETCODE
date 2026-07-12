// LC: 1331 Rank Transform Of An Array
// Title: Rank Transform Of An Array
// Difficulty: Easy
// Date: 12 July 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        vector<int> temp(arr.begin(), arr.end());
        sort(temp.begin(), temp.end());
        map<int,int> rank;
        int r=1;

        for(int i=0; i < n; i++){
            // cout<<temp[i]<<"*"<<endl;
            if(i == 0){
                rank[temp[i]] = r;
                continue;
            }

            if(temp[i] != temp[i-1]){
                r++;
            }

            rank[temp[i]] = r;

        }

        vector<int> ans;
        
        for(auto i: arr){
            ans.push_back(rank[i]);
        }



        return ans;
        
    }
};