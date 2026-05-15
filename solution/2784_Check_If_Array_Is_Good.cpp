// LC: 2784 Check If Array Is Good
// Title: Check If Array Is Good
// Difficulty: Easy
// Date: 16 May 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {

        int nOne = nums.size();
        int n = nOne-1;

        map<int,int> mp;
        int mx = 0;
        for(auto& i: nums){
            mx = max(mx, i);
            mp[i]++;
        }

        if(n != mx){
            return false;
        }

        for(int i=1; i <= n-1;i++){
            if(mp[i] != 1) return false;
        }

        return mp[n] == 2;
        
    }
};