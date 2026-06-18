// LC: 1344 Angle Between Hands Of A Clock
// Title: Angle Between Hands Of A Clock
// Difficulty: Medium
// Date: 18 June 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double val1 = 30 * hour;
        double val2 = 5.5 * minutes;

        double ans = abs(val2 - val1);
        ans = min(ans, 360 - ans);
        return ans;
    }
};
