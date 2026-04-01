// LC: 2751 Robot Collisions
// Title: Robot Collisions
// Difficulty:
// Date: 01 April 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> ans;
        vector<pair<int,int>> robos;

        for(int i = 0; i < n ; i++)
        {
            robos.push_back({positions[i], i});
        }

        sort(robos.begin(), robos.end());

        stack<int> st;



        for(auto i: robos){
            int val = i.first;
            int index = i.second;

            // cout<<val<<" "<<index<<" "<<healths[index]<<" "<<directions[index]<<endl;


            while(!st.empty() && directions[st.top()] == 'R' && directions[index] == 'L'){
                if(healths[st.top()] == healths[index]){
                    healths[st.top()] = 0;
                    healths[index] = 0;
                    // cout<<"pop2"<<st.top()<<endl;
                    st.pop();                  
                    break;
                    // remove both
                }

                if(healths[st.top()] >  healths[index]){
                    healths[st.top()]--;
                    healths[index] = 0;
                    break;
                    // remove latest
                }else{
                    healths[index]--;
                    healths[st.top()] = 0;
                    //remove prev
                    // cout<<"pop"<<st.top()<<endl;
                    st.pop();

                }
            }

            if(healths[index] > 0){
                // cout<<"push"<<index<<endl;
                st.push(index);
            }

        }

        for(auto i: healths){
            if(i != 0){
                ans.push_back(i);
            }
        }

        return ans;

        
    }
};
