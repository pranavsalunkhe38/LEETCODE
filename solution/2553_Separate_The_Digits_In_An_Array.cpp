// LC: 2553 Separate The Digits In An Array
// Title: Separate The Digits In An Array
// Difficulty: Easy
// Date: 11 May 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i=n-1; i >= 0; i--){
            int val = nums[i];

            while(val > 0){
                ans.push_back(val%10);
                val /= 10;
            }

        }

        reverse(ans.begin(), ans.end());

        return ans;
        
    }
};