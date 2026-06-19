// LC: 1732 Find The Highest Altitude
// Title: Find The Highest Altitude
// Difficulty: Easy
// Date: 19 June 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int curr = 0;

        for(auto i: gain){
            curr += i;
            ans = max(ans,curr);
        }
        return ans;
        
    }
};
