// LC: 3650 Minimum Cost Path with Edge Reversals
// Title: Minimum Cost Path with Edge Reversals
// Difficulty: Medium
// Date: 27 Jan 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> mp(n);

        for(auto i: edges){
            auto u = i[0];
            auto v = i[1];
            auto w = i[2];

            mp[u].push_back({v,w});
            mp[v].push_back({u,2*w});

        }

        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
        vector<int> dist(n,INT_MAX);
        dist[0] = 0;
        q.push({0,0});

        while(!q.empty()){
            auto x = q.top();q.pop();
            auto node = x.second;
            

            for(auto it: mp[x.second]){

                if(dist[node] + it.second < dist[it.first]){
                    dist[it.first] = dist[node] + it.second;

                    q.push({dist[it.first], it.first});
                }

            }
        }


    if(dist[n-1] == INT_MAX) return -1;
        return dist[n-1];
        
    }
};
