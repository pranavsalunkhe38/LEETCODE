// LC: 3660 Jump Game Ix
// Title: Jump Game Ix
// Difficulty: Medium
// Date: 07 May 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> mx(n);
        int m = 0;
        for(int i=0; i <n; i++ ){
            m = max(m, nums[i]);
            mx[i] = m;
        }

        vector<int> ans(n,0);

        int mn = INT_MAX;

        for(int i=n-1; i >= 0; i-- ){
            if(mx[i] > mn){
                ans[i]=ans[i+1];
            }else{
            ans[i]=mx[i];
            }

            mn = min(nums[i], mn);

    
        }



        return ans;
        
    }
};