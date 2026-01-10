// LC: 712 Minimum ASCII Delete Sum for Two Strings
// Title: Minimum ASCII Delete Sum for Two Strings
// Difficulty: Medium
// Date: 10 Jan 2026

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rec(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
    {

        if (i == s1.size() || j == s2.size())
        {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];
        int ans;

        if (s1[i] == s2[j])
        {
            ans = int(s1[i]) + rec(s1, s2, i + 1, j + 1, dp);
        }
        else
        {
            int x = rec(s1, s2, i + 1, j, dp);
            int y = rec(s1, s2, i, j + 1, dp);
            ans = max(x, y);
        }

        return dp[i][j] = ans;
    }

    int minimumDeleteSum(string s1, string s2)
    {

        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
        auto mx = rec(s1, s2, 0, 0, dp);
        int t1 = 0, t2 = 0;

        for (auto i : s1)
        {
            t1 += int(i);
        }

        for (auto i : s2)
        {
            t2 += int(i);
        }

        auto ans = t1 + t2 - (2 * mx);

        return ans;
    }
};