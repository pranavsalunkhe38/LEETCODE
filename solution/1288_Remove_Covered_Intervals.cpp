// LC: 1288 Remove Covered Intervals
// Title: Remove Covered Intervals
// Difficulty: Medium
// Date: 06 July 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans = 0;

        auto comp = [](vector<int> v1, vector<int> v2){
        if(v1[0] == v2[0]){
            return v1[1] > v2[1];
        }

        return v1[0] < v2[0];
        };


        sort(intervals.begin(), intervals.end(),comp);
        int prev_end = -1;
        int prev_start = -1;

        for(auto i: intervals){
            // cout<<i[0]<<" "<<i[1]<<endl;

            if(i[0] != prev_start && prev_end < i[1]){
                ans++;
                prev_start = i[0];
                prev_end = i[1];
            }
        }

        return ans;
        
    }
};