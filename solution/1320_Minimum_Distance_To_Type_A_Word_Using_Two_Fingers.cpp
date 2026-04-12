// LC: 1320 Minimum Distance To Type A Word Using Two Fingers
// Title: Minimum Distance To Type A Word Using Two Fingers
// Difficulty: HARD
// Date: 12 April 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<char,pair<int,int>> mp;
    
    void build(){
        int n = 6;
        int letter = 0;

        for(int i=0; letter < 26; i++){

            for(int j=0; j < n && letter < 26; j++){

                mp['A'+letter] = {i,j};
                letter++;

            }
        }

        // for(auto i: mp){
        //     cout<<i.first<<endl;
        //     cout<<i.second.first<<" "<<i.second.second<<endl;
        //     }
    }


int rec(string& word, int f1, int f2, int i,
        vector<vector<vector<int>>>& dp) {

    if (i == word.size()) return 0;

    if (dp[f1+1][f2+1][i] != -1)
        return dp[f1+1][f2+1][i];

    int val1 = (f1 == -1 ? 0 :
        abs(mp[word[i]].first - mp['A'+f1].first) +
        abs(mp[word[i]].second - mp['A'+f1].second));

    int a = val1 + rec(word, word[i]-'A', f2, i+1, dp);

    int val2 = (f2 == -1 ? 0 :
        abs(mp[word[i]].first - mp['A'+f2].first) +
        abs(mp[word[i]].second - mp['A'+f2].second));

    int b = val2 + rec(word, f1, word[i]-'A', i+1, dp);

    return dp[f1+1][f2+1][i] = min(a, b);
}

    int minimumDistance(string word) {
        int n = word.size();

        build();

        vector<vector<vector<int>>> dp(27, vector<vector<int>>(27, vector<int>(n+1,-1)));

        int ans = rec(word, -1,-1,0,dp);
        return ans;
        
    }
};
