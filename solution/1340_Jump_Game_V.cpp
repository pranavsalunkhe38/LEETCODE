// LC: 1340 Jump Game V
// Title: Jump Game V
// Difficulty: HARD
// Date: 24 May 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int d;
    vector<int> dp;
    int n;
public:
    int rec(vector<int>& arr, int i){

        if(dp[i] != -1) return dp[i];

        int ans = 0;


        for(int j=1; j <= d && i+j < n; j++){
            
            if(arr[i] > arr[i+j]){
                ans = max(ans, rec(arr, i+j));
                
            }else{
                break;
            }

        }


            for(int j=1; j <= d && i-j >= 0; j++){
               
            if(arr[i] > arr[i-j]){
                ans = max(ans, rec(arr, i-j));
                
            }else{
                break;
            }

        }

        return dp[i] = 1 + ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        this->d = d;
        n = arr.size();
        dp.resize(n,-1);
        
        int n = arr.size();
        int ans = 0;

        for(int i=0; i < n; i++){
            ans = max(ans, rec(arr, i));
        }

        return ans;
        
    }
};
