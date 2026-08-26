// LC: 2904 Shortest And Lexicographically Smallest Beautiful String
// Title: Shortest And Lexicographically Smallest Beautiful String
// Difficulty: Medium
// Date: 26 August 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l = 0;
        map<int,int> mp;
        string ans = "";
        for(int r=0; r < n; r++){
            mp[s[r] - '0']++;

            while(mp[1] > k){
                mp[s[l]-'0']--;
                l++;
            }

            while(mp[1] == k && l < r && s[l] == '0') l++;

            if(mp[1] == k ){
                string val = s.substr(l, r-l+1);
                // cout<<val<<" "<<ans<<endl;
                if(ans == ""){
                    ans = val;
                }else if(val.size() < ans.size()){
                    ans = val;
                }
                else if(val.size() == ans.size() && val < ans){
                    // cout<<val<<" "<<ans<<endl;
                    ans = val;
                }
            }

        }

        return ans;
        
    }
};



