// LC: 1722 Minimize Hamming Distance After Swap Operations
// Title: Minimize Hamming Distance After Swap Operations
// Difficulty: Medium
// Date: 21 April 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void rec(vector<vector<int>>& graph, vector<bool>& vis, int i, vector<int>& index){
        vis[i] = true;
        index.push_back(i);

        for(auto node: graph[i]){
            if(vis[node] != true){
                rec(graph, vis, node,index);
            }
        }
    }

    int solve(vector<int>& source, vector<int>& target, int i, vector<bool>& vis, vector<vector<int>>& graph){
        vector<int> index;
        int res = 0;
        rec(graph, vis, i,index);
        map<int,int> mp;
        for(auto i: index){
            mp[source[i]]++;
        }

        for(auto i: index){
            
            if(mp.find(target[i]) != mp.end()){
                mp[target[i]]--;
                if(mp[target[i]] == 0){
                    mp.erase(target[i]);
                }
                continue;
            }
            res++;
        
        }

        return res;


    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {

        int n = source.size();

        vector<vector<int>> graph(n);

        for(vector<int>& i: allowedSwaps){
            int v1 = i[0];
            int v2 = i[1];
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        vector<bool> vis(n, false);
        int ans = 0;
        for(int i=0; i < n; i++){
            if(vis[i] == true){
                continue;
            }
            ans += solve(source,target, i , vis, graph);
        }



        return ans;
        
    }
};