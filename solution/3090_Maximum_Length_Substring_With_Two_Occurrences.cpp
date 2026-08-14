// LC: 3090 Maximum Length Substring With Two Occurrences
// Title: Maximum Length Substring With Two Occurrences
// Difficulty: Easy
// Date: 14 August 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int l = 0;
        map<char,int> mp;
        int ans = 0;

        for(int r = 0; r < n; r++){
            mp[s[r]]++;

            while(mp[s[r]] > 2){
                mp[s[l++]]--;
            }

            ans = max(ans, r - l +1);

        }

        return ans;
        
    }
};
