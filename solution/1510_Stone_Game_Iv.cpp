// LC: 1510 Stone Game Iv
// Title: Stone Game Iv
// Difficulty: HARD
// Date: 10 August 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;
    
public:
    bool rec(int n, bool turn){

        if(n == 0){
            return turn == false;
        }

        if(dp[n][turn] != -1){
            return dp[n][turn];
        }
        bool ans = false;
            if(turn == true){
            for(int i=1; i*i <= n; i++){
                ans |= rec(n - i*i, !turn);
            }
            }
            else{
            for(int i=1; i*i <= n; i++){
                ans |= !rec(n - i*i, !turn);
            }
            }


            if(turn == true){
                return dp[n][turn] = (ans == true);
            }

            return dp[n][turn] = !(ans == true);
    }
    bool winnerSquareGame(int n) {
        dp.resize(n+1, vector<int>(2,-1));
        return rec(n,true);
        
    }
};
