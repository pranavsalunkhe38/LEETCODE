// LC: 3069 Distribute Elements Into Two Arrays I
// Title: Distribute Elements Into Two Arrays I
// Difficulty: Easy
// Date: 20 August 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> v1;
        vector<int> v2;
        vector<int> ans;

        int n = nums.size();

        int l = 0;
        int r = 0;

        v1.push_back(nums[0]);
        v2.push_back(nums[1]);

        for(int i=2; i < n; i++){
            if(v1[l] > v2[r]){
                v1.push_back(nums[i]);
                l++;
            }else{
                r++;
                v2.push_back(nums[i]);
            }
        }


        for(auto i: v1){
            ans.push_back(i);
        }

        for(auto i: v2){
            ans.push_back(i);
        }

        return ans;
        
    }
};
