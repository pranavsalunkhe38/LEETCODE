// LC: 3120 Count The Number Of Special Characters I
// Title: Count The Number Of Special Characters I
// Difficulty: Easy
// Date: 26 May 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        map<char,int> mp;
        for(auto& i: word){
            mp[i]++;
        }

        for(int i=0; i < 26; i++){
            char lcase = 'a' + i;
            char ucase = 'A' + i;

            if(mp.find(lcase) != mp.end() && mp.find(ucase) != mp.end()){
                ans++;
            }
        }

        return ans;
        
    }
};
