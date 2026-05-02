// LC: 788 Rotated Digits
// Title: Rotated Digits
// Difficulty: Easy
// Date: 02 May 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> dp;
    
    map<int,int> mp = 
    {
        {0,0},
        {1,0},
        {2,1},
        {3,-1},
        {4,-1},
        {5,1},
        {6,1},
        {7,-1},
        {8,0},
        {9,1},
    };

    int check(int n){
        int val = 0;

        while(n > 0){
            
            int x = mp[n%10];

            if(x == -1){
                return 0;
            }
            val += x;

            n /= 10;
        }

        return val > 0 ? 1: 0;

    }

    void build(){

        for(int i=1; i < dp.size(); i++){
            int res = check(i);
            // cout<<i<<" "<<res<<endl;
            dp[i] = res + dp[i-1];
        }

    }

    int rotatedDigits(int n) {
        dp.resize(n+1);
       
        build();

        // for(auto i: dp){
        //     cout<<i<<" ";
        // }
        
        return dp[n] - dp[0];
        
    }
};
