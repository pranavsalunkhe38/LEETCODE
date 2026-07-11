// LC: 2685 Count The Number Of Complete Components
// Title: Count The Number Of Complete Components
// Difficulty: Medium
// Date: 12 July 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& graph, int i, vector<int>& vis, int c){
        int cnt = 1;
        vis[i] = c;

        for(auto j: graph[i]){
            if(vis[j] == -1){
                cnt += dfs(graph, j, vis,c);
            }
        }

        return cnt;

    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> vis(n, -1);
        vector<int> comp;
        
        for(auto i: edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }

        int cnt = 0;
        for(int i=0; i < n; i++){
            if(vis[i] == -1){
                comp.push_back(dfs(graph, i, vis, comp.size()));
            }

        }

        // for(auto i: comp){
        //     cout<<i<<endl;
        // }

        vector<int> ed(comp.size(),0);

        for(auto i: edges){
            int com = vis[i[0]];  
            ed[com]++;         
        }

        // for(auto i: ed){
        //     cout<<i<<endl;
        // }

        for(int i = 0; i < comp.size(); i++){
            int nodes = comp[i];
            int edges = ed[i];

            if(edges == ((nodes * (nodes-1)) / 2)) cnt++;
        }


        return cnt;
        
    }
};