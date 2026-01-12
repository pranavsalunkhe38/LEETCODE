// LC: 1266 Minimum Time Visiting All Points
// Title: Minimum Time Visiting All Points
// Difficulty: Easy
// Date: 12 Jan 2026

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {

        int n= points.size();
        int ans = 0;

        for(int i=1; i < n; i++){
            auto p1 = points[i-1];
            auto p2 = points[i];

            int l1 = abs(p1[0] - p2[0]);
            int l2 = abs(p1[1] - p2[1]);
            int mn = min(l1,l2);
            int res = l1 - mn + l2;
            ans += res;
        }

        return ans;

        
    }
};