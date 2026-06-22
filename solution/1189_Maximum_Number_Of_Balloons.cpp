// LC: 1189 Maximum Number Of Balloons
// Title: Maximum Number Of Balloons
// Difficulty: Easy
// Date: 22 June 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> v(26,0);
        map<char,int> mp = {{'b',1},{'a',1},{'l',2},{'o',2},{'n',1}};
        for(auto i: text){
            v[i - 'a']++;
        }
        int ans = INT_MAX;
        for(auto i: mp){
            ans = min(ans,v[i.first - 'a'] / i.second);
        }

        return ans;
        
    }
};
