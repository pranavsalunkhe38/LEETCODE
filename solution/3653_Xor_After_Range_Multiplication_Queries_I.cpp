// LC: 3653 Xor After Range Multiplication Queries I
// Title: Xor After Range Multiplication Queries I
// Difficulty: Medium
// Date: 08 April 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod = 1000000007;
    int calculate(vector<long long>& nums){
        int ans = 0;

        for(auto& i: nums){
            ans ^= i;
        }


        return ans;
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        vector<long long> num;

        for(auto& i: nums){
            num.push_back((long long)i);
        }

        for(auto& i: queries){
            auto l = i[0];
            auto r = i[1];
            auto k = i[2];
            auto v = i[3];

            for(int j=l; j<=r;j+= k){
                num[j] = (num[j] * v) % mod;
                num[j] = num[j] % mod;
            }

        }


            return calculate(num);
        
    }
};
