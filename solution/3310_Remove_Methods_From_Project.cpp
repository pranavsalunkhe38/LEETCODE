// LC: 3310 Remove Methods From Project
// Title: Remove Methods From Project
// Difficulty: Medium
// Date: 05 August 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rec(vector<vector<int>>& graph, int i, vector<bool>& vis){
        vis[i] = true;

        for(auto j: graph[i]){
            if(vis[j] == true) continue;
            rec(graph, j ,vis);
        }

    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool> sus(n,false);
       
        vector<vector<int>> graph(n);

        for(auto q: invocations){
            graph[q[0]].push_back(q[1]);
        }

        rec(graph, k, sus);

        // for(auto i: sus){
        //     cout<<i<<" ";
        // }
        // cout<<endl;

        bool flag = false;
        for(auto q: invocations){
            if(sus[q[0]] == false &&  sus[q[1]] == true){
                flag = true;
                break;
            }
        }

        
        vector<int> ans;
            for(auto i=0; i < n; i++){
                if(flag == false && sus[i] == true) continue;
                ans.push_back(i);
            }
        
        return ans;
        
    }
};