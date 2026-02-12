// LC: 3713 Longest Balanced Substring I
// Title: Longest Balanced Substring I
// Difficulty: Medium
// Date: 12 Feb 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkMap(map<int,int>& mp){
        int x = -1;
        for(auto i: mp){
            if(x == -1){
                x = i.second;
                continue;
            }

            if(i.second != x){
                return false;
            }

        }

        return true;
    }
    int longestBalanced(string s) {
        auto n = s.size();
        int ans = 0;

        for(int i=0; i < n; i++){
            map<int,int> mp;
            for(int j=i; j >= 0; j--){
                mp[s[j]]++;

                if(checkMap(mp)){
                    ans = max(ans, i-j+1);
                }
            }
        }

        return ans;
        
    }
};