// LC: 3121 Count The Number Of Special Characters Ii
// Title: Count The Number Of Special Characters Ii
// Difficulty: Medium
// Date: 27 May 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> lcase(26,-1);
        vector<int> ucase(26,-1);
        int ans = 0;

        for(int j=0; j < n; j++){
            char i = word[j];
        // for(auto& i: word){
            if(i == tolower(i)){
                lcase[i-'a'] = j;
            }else if(ucase[i-'A'] == -1){
                ucase[i - 'A'] = j;
                
            }
        }

        for(int i=0; i < 26; i++){
            // cout<<lcase[i]<<" "<<ucase[i]<<endl;
            if(lcase[i] == -1 || ucase[i] == -1) continue;
            if(lcase[i] < ucase[i]){
                ans++;
            }
        }

        return ans;
        
    }
};
