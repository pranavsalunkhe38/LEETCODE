// LC: 3740 Minimum Distance Between Three Equal Elements 2
// Title: Minimum Distance Between Three Equal Elements 2
// Difficulty: Easy
// Date: 11 April 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        map<int,vector<int>> mp;

        for(int i=0;i<n; i++){

            mp[nums[i]].push_back(i);
        
        }

        int ans = INT_MAX;

        for(auto i: mp){
            if(i.second.size()>2){

                auto x = i.second;

                for(int i=1; i <= x.size()-2; i++){
                    int val = (x[i] - x[i-1]) + (x[i+1] - x[i]) + (x[i+1] - x[i-1]);
                    // cout<<val<<endl;
                    ans = min(ans,val);
                }
                // cout<<i.first<<endl;
            }
        }

        if(ans == INT_MAX){
            ans = -1;
        }

        return ans;
        
    }
};
