// LC: 1358 Number Of Substrings Containing All Three Characters
// Title: Number Of Substrings Containing All Three Characters
// Difficulty: Medium
// Date: 30 June 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {

        map<char,int> mp;
        int ans = 0;
        int l = 0;
        int n = s.size();
        for(int i=0; i < n; i++){
            // cout<<mp.size()<<" "<<ans<<endl;
            mp[s[i]]++;

            while(mp.size() == 3){

                ans += (n - i);

                char last = s[l++];
                mp[last]--;
                if(mp[last] == 0){
                    mp.erase(last);
                }
            }

        }

        return ans;
        
    }
};
