// LC: 2463 Minimum Total Distance Traveled
// Title: Minimum Total Distance Traveled
// Difficulty: HARD
// Date: 14 April 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const long long mx = 1e12;
public:
    long long rec(vector<int>& robot, vector<int>& factory, int i, int j,vector<vector<long long>>& dp){
        if(i == robot.size()){
            return 0;
        }

        if(j  == factory.size()){
            return mx;
        }

        if(dp[i][j] != -1) return dp[i][j];

        //assign factory
        long long a = abs(robot[i] - factory[j]) + rec(robot,factory, i+1,j+1,dp);
        //use next one
        long long b = rec(robot,factory, i, j+1,dp);

        return dp[i][j] = min(a,b);


    }

    vector<int> getFac(vector<vector<int>> factory){
        int m = factory.size();
        vector<int> factorypos;
        for(int i=0; i < m; i++)
        {
            for(int j = 0; j < factory[i][1]; j++){
                factorypos.push_back(factory[i][0]);
            }
        }

        return factorypos;

    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<int> factorypos = getFac(factory);
        
        int n = robot.size();
        int m = factorypos.size();

        sort(robot.begin(), robot.end());
        sort(factorypos.begin(), factorypos.end());
        // for(auto i: factorypos){
        //     cout<<i<<" ";
        // }
        vector<vector<long long>> dp(n, vector<long long>(m,-1));
        long long ans = rec(robot,factorypos, 0,0,dp);

        return ans;
        
    }
};