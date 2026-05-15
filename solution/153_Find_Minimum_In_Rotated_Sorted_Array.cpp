// LC: 153 Find Minimum In Rotated Sorted Array
// Title: Find Minimum In Rotated Sorted Array
// Difficulty: Medium
// Date: 16 May 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;

        int ans;

        while(l < r){
            int mid = l + (r - l)/2;

            // cout<<l<<" "<<r<<" "<<mid<<endl;

            if( nums[r] > nums[mid]){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        return nums[l];
    }
};
