// LC: 2976 Minimum Cost to Convert String I
// Title: Minimum Cost to Convert String I
// Difficulty: Medium
// Date: 29 Jan 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> dist(26,vector<int>(26,INT_MAX));
        int n = original.size();
         for (int i = 0; i < 26; i++) dist[i][i] = 0;

        for(int i=0; i < n; i++){
            int s = original[i] - 'a';
            int d = changed[i] - 'a';
            dist[s][d] = min(dist[s][d], cost[i]);
        }

        
          // Floyd–Warshall
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                if (dist[i][k] == INT_MAX) continue;
                for (int j = 0; j < 26; j++) {
                    if (dist[k][j] == INT_MAX) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // for(int i=0; i < 26; i++){
        //     for(int j=0; j < 26;j++){
        //         if(dist[i][j] == INT_MAX){
        //             cout<<-1<<" ";
        //             continue;
        //         }
        //         cout<<dist[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        long long ans = 0;

        for(int i=0; i < source.size(); i++){
            int s =  source[i] - 'a';
            int t = target[i] - 'a';

            if(dist[s][t] == INT_MAX) return -1;

            ans += dist[s][t];
        }

        return ans;
        
    }
};
