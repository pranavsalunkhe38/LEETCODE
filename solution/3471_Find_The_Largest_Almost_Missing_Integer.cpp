// LC: 3471 Find The Largest Almost Missing Integer
// Title: Find The Largest Almost Missing Integer
// Difficulty: Easy
// Date: 18 August 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if(k == n){
            return *max_element(nums.begin(), nums.end());
        } 

        
       

        if(k == 1){
            // cout<<"here"<<endl;
            int ans = -1;
             map<int,int> mp;
            for(auto i: nums){
                mp[i]++;
            }

            for(auto i: mp){
                if(i.second == 1){
                    ans = max(ans, i.first);
                }
            }

            return ans;
        }

          map<int,int> mp;
            for(auto i: nums){
                mp[i]++;
            }

        int ans = -1;

        if(mp[nums[0]] == 1){
            ans = max(ans, nums[0]);
        }

        if(mp[nums[n-1]] == 1){
            ans = max(ans, nums[n-1]);
        }



        return ans;
    }
};
