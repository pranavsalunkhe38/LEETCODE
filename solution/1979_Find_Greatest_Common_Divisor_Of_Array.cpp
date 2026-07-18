// LC: 1979 Find Greatest Common Divisor Of Array
// Title: Find Greatest Common Divisor Of Array
// Difficulty: Easy
// Date: 18 July 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = INT_MIN;

        for(auto i: nums){
            mn = min(mn, i);
            mx = max(mx, i);
        }

        return gcd(mx,mn);
        
    }
};
