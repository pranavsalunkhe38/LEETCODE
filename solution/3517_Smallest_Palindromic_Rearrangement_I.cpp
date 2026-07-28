// LC: 3517 Smallest Palindromic Rearrangement I
// Title: Smallest Palindromic Rearrangement I
// Difficulty: Medium
// Date: 28 July 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int> mp;
        for(auto i: s){
            mp[i]++;
        }
        string start = "";
        string mid = "";
        for(int i=0; i < 26; i++){
            char letter = ('a'+i);
            int val = mp[letter];
            if( val == 0){
                continue;
            }

            if(val % 2 != 0){
                    mid += letter;
            }

            for(int j=0; j < val/2;j++){
                start += letter;
            }
        }

        string ans = start + mid;
        reverse(start.begin(), start.end());
        ans += start;
        return ans;
        
    }
};
