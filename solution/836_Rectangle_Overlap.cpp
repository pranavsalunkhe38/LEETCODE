// LC: 836 Rectangle Overlap
// Title: Rectangle Overlap
// Difficulty: Easy
// Date: 14 September 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> getPoints(vector<int>& rec){
        int x1 = rec[0];
        int y1 = rec[1];
        int x2 = rec[2];
        int y2 = rec[3];

        return {{x1,y1},{x1,y2},{x2,y1},{x2,y2}};
    }

    long long intersection(vector<pair<int,int>> points){
        sort(points.begin(), points.end());

        if(points[0].second == points[1].second) return 0;

        return (points[2].first - points[1].first);
    }

    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

        vector<pair<int,int>> x = {{rec1[0],0}, {rec1[2],0},{rec2[0],1}, {rec2[2],1} };
        vector<pair<int,int>> y = {{rec1[1],0}, {rec1[3],0},{rec2[1],1}, {rec2[3],1} };

        long long lenght = intersection(x);
        long long breadth = intersection(y);

        return ((lenght * breadth) != 0);
        
    }
};

// TC O(1)
// SC O(1)