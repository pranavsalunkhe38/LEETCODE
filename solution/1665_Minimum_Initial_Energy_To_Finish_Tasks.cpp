// LC: 1665 Minimum Initial Energy To Finish Tasks
// Title: Minimum Initial Energy To Finish Tasks
// Difficulty: HARD
// Date: 12 May 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int minimumEffort(vector<vector<int>>& tasks) {

        int n = tasks.size();

        sort(tasks.begin(), tasks.end(), [](vector<int>& v1, vector<int>& v2){

            return (v1[1] - v1[0]) > (v2[1] - v2[0]);
    });

        


        int ans = 0;
        int curr = 0;

        for(int i=0; i < n; i++){

            if(curr < tasks[i][1]){
                ans += (tasks[i][1] - curr);
                curr = tasks[i][1];
            }

            curr -= tasks[i][0];


        }

        return ans;
        
    }
};
