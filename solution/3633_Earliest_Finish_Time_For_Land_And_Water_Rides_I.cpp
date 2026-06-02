// LC: 3633 Earliest Finish Time For Land And Water Rides I
// Title: Earliest Finish Time For Land And Water Rides I
// Difficulty: 
// Date: 02 June 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {


        int n = landStartTime.size();
        int m = waterStartTime.size();

        int ans = INT_MAX;

        for(int i = 0; i < n; i++){
            for(int j=0; j < m; j++){

                vector<pair<int,int>> temp{{landStartTime[i],0},{landStartTime[i]+landDuration[i],1},{waterStartTime[j],0},{waterStartTime[j]+waterDuration[j],1}};

                sort(temp.begin(), temp.end());
                // for(auto ii: temp){
                //     cout<<ii.first<<"*"<<ii.second<<" ";
                // }
                // cout<<endl;

                if(temp[0].second == temp[1].second){
                    // cout<<"overlap"<<endl;
                    ans = min(ans, min(landStartTime[i], waterStartTime[j]) + (waterDuration[j] + landDuration[i]));
                }else{
                    ans = min(ans, max(landStartTime[i]+landDuration[i], waterStartTime[j]+waterDuration[j]));
                }

            }
        }
        
        return ans;
    }
};