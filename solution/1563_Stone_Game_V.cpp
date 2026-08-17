// LC: 1563 Stone Game V
// Title: Stone Game V
// Difficulty: HARD
// Date: 17 August 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> pre;
    vector<vector<int>> dp;

    int n;
public:

    int getSum(int i, int j){
        if(i == 0){
            return pre[j];
        }

        return pre[j] - pre[i-1];
    }

    void calculatePre(vector<int>& stones){

    pre.resize(n);

    int sum = 0;
    for(int i=0; i < n ;i++){
            sum += stones[i];
            pre[i] = sum;
    }
      

    }
    
    int rec(vector<int>& stones, int i, int j){

        if(dp[i][j] != -1 ) return dp[i][j];
    
        

        if(i == j){
    return dp[i][j] = 0;
}

        int sum = getSum(i,j);
        int curr = 0;
        int ans = 0;
        int othersum = 0;

        for(auto k = i; k < j; k++){
            curr += stones[k];
            othersum = sum - curr;

            if(curr > othersum){
                ans = max(ans, othersum + rec(stones,k+1,j));
            }else if(curr < othersum){
                ans = max(ans, curr + rec(stones, i,k));
            }else{
                ans = max(ans,  max(othersum + rec(stones,k+1,j), curr + rec(stones,i,k)));
            }
        }

        return dp[i][j] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
         n = stoneValue.size();

         dp.resize(n, vector<int>(n,-1));

         calculatePre(stoneValue);

         int ans =  rec(stoneValue, 0 , n-1);

        //  for(auto i: dp){
        //     for(auto j : i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        //  }
        
         return ans;
    }
};
