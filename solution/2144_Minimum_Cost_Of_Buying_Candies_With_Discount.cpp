// LC: 2144 Minimum Cost Of Buying Candies With Discount
// Title: Minimum Cost Of Buying Candies With Discount
// Difficulty: Easy
// Date: 02 June 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(),greater<int>());
        int n = cost.size();
        int cnt= 0;
        int ans = 0;

        for(int i=0; i < n; i++){

            if(cnt < 2){
                cnt++;
                ans += cost[i];
            }else{
                cnt = 0;

            }

        }

        return ans;
        
    }
};
