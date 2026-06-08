// LC: 2161 Partition Array According To Given Pivot
// Title: Partition Array According To Given Pivot
// Difficulty: Medium
// Date: 08 June 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n,pivot);

        int l=0, r = n-1;

        for(int i=0; i < n; i++){
            if(nums[i] < pivot){
                ans[l++] = nums[i];
            }
            
            if(nums[n-i-1] > pivot){
                ans[r--] = nums[n-i-1];
            }
        }


        return ans;
        
    }
};
