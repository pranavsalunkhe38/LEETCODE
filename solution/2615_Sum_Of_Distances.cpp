// LC: 2615 Sum Of Distances
// Title: Sum Of Distances
// Difficulty: Medium
// Date: 24 April 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void func( vector<long long>& v, vector<long long>& ans){
        long long n = v.size();
        long long total = 0;
        for(auto& i: v){
            total += i;
        }
        long long pre = 0;
        for(int i=0; i < n; i++){

            long long val1 = pre;
            long long val2 = v[i] * (i);
            long long val3 = total - pre - v[i];
            long long val4 = v[i] * (n - i -1);

            ans[v[i]] = val3 - val4 + val2 - val1;

            pre += v[i];

        }
    }
    vector<long long> distance(vector<int>& nums) {
       int n = nums.size();
        map<long long, vector<long long>> mp;
        for(long long i=0; i < n; i++){
            mp[nums[i]].push_back((long long)i);
        }
        vector<long long> ans(n);

        for(auto& i: mp){
            func(i.second, ans);
        }

        return ans;
    }
};
