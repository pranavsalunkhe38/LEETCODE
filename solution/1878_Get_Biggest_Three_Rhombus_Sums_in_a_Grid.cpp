// LC: 1878 Get Biggest Three Rhombus Sums in a Grid
// Title: Get Biggest Three Rhombus Sums in a Grid
// Difficulty: Medium
// Date: 16 March 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int get(vector<vector<int>>& grid, int x, int y, int size){
        if(size == 1){
            return grid[x][y];
        }

        if((x + size - 1) >= grid.size()) return 0;
        if((y + size - 1) >= grid[0].size()) return 0;
        int ans = 0;

        int mid =  size/2;
           set<pair<int,int>> st;

        for(int i=0; i < (mid+1); i++){

         
            st.insert({x+mid+i,y + i});
            st.insert({x+mid-i,y + i});
            st.insert({x+mid+i,y + size -1 - i});
            st.insert({x+mid-i,y + size -1 - i});
          
        }


          for(auto i: st){
                //   cout<<i.first<<" "<<i.second<<endl;
                // cout<<grid[i.first][i.second]<<endl;
                ans += grid[i.first][i.second];
            }
            // cout<<endl;



        return ans;

        
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {

    
       
        int m = grid.size();
        int n = grid[0].size();
        int mn = min(m,n);

        priority_queue<int, vector<int>, greater<int>> pq;
        map<int,int> mp;


        for(int i=0; i < m; i++){
            for(int j=0; j < n; j++){
                for(int sz=1; sz <= mn; sz += 2){
                    int x = get(grid, i,j, sz);

                    if(x == 0){
                        break;
                    }

                    if((pq.size() < 3 || pq.top() < x) && mp[x] == 0){
                        mp[x]++;
                        pq.push(x);
                    }

                    while(pq.size() > 3){
                        mp.erase(pq.top());
                        pq.pop();
                    }


                }
            }
        } 

        vector<int> ans;

        while(!pq.empty()){
            auto x  = pq.top();
            pq.pop();
            // cout<<x<<endl;
            ans.push_back(x);
        }

        reverse(ans.begin(), ans.end());

        return ans;
        
    }
};
