// LC: 3867 Sum Of Gcd Of Formed Pairs
// Title: Sum Of Gcd Of Formed Pairs
// Difficulty: Medium
// Date: 16 July 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> gcds(n);

        gcds[0] = nums[0];
        int mx = nums[0];

        for(int i=1; i < n; i++){
            mx = max(mx,nums[i]);
            gcds[i] = gcd(mx, nums[i]);

        }

        sort(gcds.begin(), gcds.end());
        long long ans = 0;

        // for(auto i: gcds){
        //     cout<<i<<" ";
        // }
        // cout<<endl;

        for(int i=0; i < n/2; i++){
            ans += gcd(gcds[i], gcds[n-1-i]);
        }

        return ans;

        
    }
};
