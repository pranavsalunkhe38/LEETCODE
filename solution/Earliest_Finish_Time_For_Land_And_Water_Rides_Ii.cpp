// LC: Earliest Finish Time For Land And Water Rides Ii
// Title: Finish Time For Land And Water Rides Ii
// Difficulty: Medium
// Date: 03 June 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        vector<pair<int,int>> v1,v2;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        for(int i=0; i <n ; i++){
            v1.push_back({landStartTime[i], landDuration[i]});

        }

        for(int i=0; i <m ; i++){
            v2.push_back({waterStartTime[i], waterDuration[i]});
        }

            auto comp = [](pair<int,int> v1, pair<int,int> v2){
        int end1 = v1.first + v1.second;
        int end2 = v2.first + v2.second;

        if(end1 == end2){
            return v1.first < v2.first;
        }

        return end1 < end2;
    };

        sort(v1.begin(), v1.end(),comp);
        sort(v2.begin(), v2.end(),comp);
        int ans = INT_MAX;
        auto w = v2[0];
        auto l = v1[0];
        for(int i=0; i < n; i++){
            ans = min(ans, max(w.first + w.second, v1[i].first) + v1[i].second);
        }

        for(int i=0; i < m; i++){
            ans = min(ans, max(l.first + l.second, v2[i].first) + v2[i].second);
        }

        return ans;
    }
};
