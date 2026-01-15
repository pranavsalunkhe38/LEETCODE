// LC: 2943 Maximize Area of Square Hole in Grid
// Title: Maximize Area of Square Hole in Grid
// Difficulty: Medium
// Date: 15 Jan 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(), vBars.end());

        int v=1,h=1,mv=1,mh=1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i] - vBars[i-1] == 1){
                v++;
            }else{
                v= 1;
            }

            mv = max(mv,v);
        }

        for(int i=1;i<hBars.size();i++){
            if(hBars[i] - hBars[i-1] == 1){
                h++;
            }else{
                h = 1;
            }
            mh = max(mh,h);
        }

        return pow(min(mh,mv)+1,2);
        
    }
};