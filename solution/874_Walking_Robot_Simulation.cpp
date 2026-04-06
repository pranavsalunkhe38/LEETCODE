// LC: 874 Walking Robot Simulation
// Title: Walking Robot Simulation
// Difficulty: Medium
// Date: 06 April 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // N,E,S,W
        vector<vector<int>> dir = {{0,+1},{+1,0},{0,-1},{-1,0}};
        auto curr = 0;

        sort(obstacles.begin(), obstacles.end(),[](vector<int> v1, vector<int> v2){

        if(v1[0] == v2[0]) return v1[1] < v2[1];
        return v1[0] < v2[0];
    });

        set<pair<int,int>> st;

        for(auto i: obstacles){
            st.insert({i[0],i[1]});     
        }
        int x = 0, y = 0;
        int ans = 0;

        for(auto c: commands){
            // cout<<curr<<endl;
            switch(c){
                case -1: curr++; curr = (curr+4)%4;break;
                case -2: curr--; curr = (curr+4)%4;break;
                default:
                    for(int i=0; i < c; i++){
                        x += dir[curr][0];
                        y += dir[curr][1];

                        if(st.find({x,y}) != st.end()){
                            if(dir[curr][0] == 0){
                                y -= dir[curr][1];
                            }else{
                                x -= dir[curr][0];
                            }
                            break;
                        }
                    }
            }

            ans = max(ans, x*x + y*y);

        }

        return ans;
        
    }
};
