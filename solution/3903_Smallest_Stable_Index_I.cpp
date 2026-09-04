// LC: 3903 Smallest Stable Index I
// Title: Smallest Stable Index I
// Difficulty: EASY
// Date: 04 September 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> pre(n);
        vector<int> suf(n);

        for(int i=0; i < n; i++){
            if(i==0){
                pre[i] = nums[i];
                continue;
            }

            pre[i] = max(nums[i] , pre[i-1]);
        }

        for(int i=n-1; i >= 0; i--){
            if(i==n-1){
                suf[i] = nums[i];
                continue;
            }

            suf[i] = min(nums[i] , suf[i+1]);
        }

        for(int i=0; i < n; i++){

            // cout<<pre[i]<<" "<<suf[i]<<endl;
            int val = pre[i] - suf[i];
            if(val <= k){
                return i;
            }
        }

        return -1;


        
    }
};