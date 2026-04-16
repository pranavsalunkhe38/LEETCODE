// LC: 0000 Placeholder-slug
// Title: Placeholder-slug
// Difficulty:
// Date: 16 April 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int func(vector<int>& v, int& idx, int& n){
            // cout<<idx<<"*"<<endl;

            // for(auto i: v){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
    
        int sz = v.size();
        if(sz == 1){
            return -1;
        }

        int prev = (idx - 1 + sz) % sz;
        int nxt = (idx + 1) % sz;

        int curr = v[idx];
        int back = v[prev];
        int next = v[nxt];

        int ans = INT_MAX;

        // if(curr - back < ans || n - (curr - back) < ans){
        //     ans = back;
        // }

        // if(next - curr < ans || n - (next - curr) < ans){
        //     ans = next;
        // }

        // cout<<back<<" "<<next<<endl;
        


        ans = min(ans, min(abs(curr - back),(n - abs(curr - back))));
        ans = min(ans, min(abs(next - curr),(n - abs(next - curr))));

        return ans == INT_MAX ? -1 : ans;

    }

    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        map<int, vector<int>> mp;
        int n = nums.size();

        for(int i=0; i < nums.size(); i++){
            mp[nums[i]].push_back(i);
        }

        // for(auto i: mp){
        //     cout<<i.first<<endl;
        //     for(auto j: i.second){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }

        vector<int> ans;

        for(auto i: queries){
            vector<int>& vec = mp[nums[i]];
            int idx = lower_bound(vec.begin(), vec.end(), i) - vec.begin();


        int sz = vec.size();
        if(sz == 1){
            ans.push_back(-1);
            continue;
        }

        int prev = (idx - 1 + sz) % sz;
        int nxt = (idx + 1) % sz;

        int curr = vec[idx];
        int back = vec[prev];
        int next = vec[nxt];

        int res = INT_MAX;


        res = min(res, min(abs(curr - back),(n - abs(curr - back))));
        res = min(res, min(abs(next - curr),(n - abs(next - curr))));

        
            ans.push_back(res == INT_MAX ? -1 : res);

        }

        return ans;
        
    }
};