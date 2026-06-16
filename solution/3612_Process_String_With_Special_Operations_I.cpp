// LC: 3612 Process String With Special Operations I
// Title: Process String With Special Operations I
// Difficulty: Medium
// Date: 16 June 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for(auto i: s){

            switch(i){
                case '*':
                    ans = ans.substr(0, ans.size()-1);
                    break;
                case '#':
                    ans += ans;
                    break;
                case '%':
                reverse(ans.begin(), ans.end());
                    break;
                default:
                    ans += i;

            }
        }

        return ans;
        
    }
};
