// LC: 1345 Jump Game Iv
// Title: Jump Game Iv
// Difficulty: HARD
// Date: 18 May 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
  
public:

    int minJumps(vector<int>& arr) {
    int n = arr.size();
    vector<bool> added(n,false);
    queue<int> q;


    auto add = [&](int i){

        if(i < 0 || i >= n) return;
        if(added[i] == true) return;
        q.push(i);
        added[i] = true;
    };
        
        add(0);

        map<int,vector<int>> mp;

        for(int i=0; i < n; i++){
            mp[arr[i]].push_back(i);
        }

        int level = 0;

        while(!q.empty()){
            int sz = q.size();

            for(int i=0; i < sz; i++){
                int top = q.front();
                q.pop();

                if(top == n-1) return level;

                //add children

                //add prev
                    add(top-1);
                
                //add next
                    add(top+1);
                
                //add from map
                for(auto& idx: mp[arr[top]]){
                    add(idx);
                }

                mp[arr[top]].clear();

            }

            level++;
        }


        return level;

        
    }
};
