// LC: 1975 Maximum Matrix Sum
// Title: Maximum Matrix Sum
// Difficulty: Medium
// Date: 05 Jan 2026

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {

        int cnt = 0;
        int mn = INT_MAX;
        long long ans = 0;
        for (auto i : matrix)
        {
            for (auto j : i)
            {

                if (j > 0)
                {
                }
                else
                {
                    cnt++;
                }
                ans += abs(j);

                mn = min(mn, abs(j));
            }
        }

        if (cnt % 2 != 0)
        {
            ans -= mn;
            ans -= mn;
        }

        return ans;
    }
};
