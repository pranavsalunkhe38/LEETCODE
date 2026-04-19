// LC: 1855 Maximum Distance Between A Pair Of Values
// Title: Maximum Distance Between A Pair Of Values
// Difficulty: Medium
// Date: 19 April 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // for(auto i: nums1){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for(auto i: nums2){
        //     cout<<i<<" ";
        // }
        // cout<<endl;

        int ans = INT_MIN;
        int l=0, r = 0;

        for(l=0; l < n; l++){
            while(r != m && nums1[l] <= nums2[r]){
                ans = max(ans, r-l);
                r++;
            }
            

        }
        
        return ans < 0  ? 0: ans;
        
    }
};