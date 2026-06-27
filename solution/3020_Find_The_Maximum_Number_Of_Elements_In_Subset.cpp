// LC: 3020 Find The Maximum Number Of Elements In Subset
// Title: Find The Maximum Number Of Elements In Subset
// Difficulty: Medium
// Date: 27 June 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<long long,long long> mp;
        for(auto i: nums){
            mp[(long long)i]++;
        }

        int ans = 0;

        for(auto i: mp){

            if(i.first == 1){
                int val = i.second;
                if(val % 2 == 0){
                    ans = max(ans, val-1);
                }else{
                    ans = max(ans, val);
                }
                continue;
            }

            long long val = i.first;
            int cnt = 0;

            while(mp.find(val) != mp.end()){
                ans = max(ans, cnt+1);

                if(mp[val] < 2 || val * val > 1000000001LL){
                    break;
                }
                cnt += 2;
                val *= val;
            }
        
        }

        return ans;
        
    }
};
