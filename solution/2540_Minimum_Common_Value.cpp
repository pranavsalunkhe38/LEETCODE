// LC: 2540 Minimum Common Value
// Title: Minimum Common Value
// Difficulty: Easy
// Date: 19 May 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();

        int ptr1 = 0;
        int ptr2 = 0;

        while(ptr1 < n && ptr2 < m){
            if(nums1[ptr1] == nums2[ptr2]) return nums1[ptr1];

            if(nums1[ptr1] < nums2[ptr2]){
                ptr1++;
            }else{
                ptr2++;
            }
        }

        return -1;
        
    }
};
