// LC: 2770 Maximum Number Of Jumps To Reach The Last Index
// Title: Maximum Number Of Jumps To Reach The Last Index
// Difficulty: Medium
// Date: 10 May 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> v(n,-1);
        v[0] = 0;

        for(int i=0; i < n; i++){
            for(int j=i+1; j < n; j++){

                if(i == j) continue;

                if(v[i] != -1 && abs(nums[i] - nums[j]) <= target){
                    v[j] = max(v[j], v[i]+1);
                }
            }
        }

        // for(auto i: v){
        //     cout<<i<<" ";
        // }
        // cout<<endl;

        return v[n-1];
        
    }
};
