// LC: 3532 Path Existence Queries In A Graph I
// Title: Path Existence Queries In A Graph I
// Difficulty: Medium
// Date: 09 July 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> group(n,0);
        for(int i=1; i < n; i++){

            if(nums[i] - nums[i-1] <= maxDiff){
                group[i] = group[i-1];

            }else{
                group[i] = group[i-1]+1;
            }
        }
        // for(auto i: group){
        //     cout<<i<<" ";
        // }
        // cout<<endl;

        vector<bool> ans;
        for(auto q: queries){
            ans.push_back(group[q[0]] == group[q[1]]);
        }

        return ans;
        
    }
};