// LC: 1411 Number Of Ways To Paint N × 3 Grid
// Title: Number Of Ways To Paint N × 3 Grid
// Difficulty: Hard
// Date: 03 Jan 2026

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1000000007;
    vector<string> v = {"RYR", "YRY", "GRY", "RYG", "YRG", "GRG", "RGR", "YGR", "GYR", "RGY", "YGY", "GYG"};

    int solve(int n, int prev, vector<vector<long long>> &dp)
    {

        if (n == 0)
        {
            return 1;
        }

        if (dp[n][prev] != -1)
        {
            return dp[n][prev];
        }

        int ans = 0;

        for (int i = 0; i < 12; i++)
        {
            string val1 = v[prev];
            string val2 = v[i];

            if (val1[0] == val2[0] || val1[1] == val2[1] || val1[2] == val2[2])
            {
                continue;
            }

            ans = (ans + solve(n - 1, i, dp)) % mod;
        }
        return dp[n][prev] = ans % mod;
    }

    int numOfWays(int n)
    {

        long long ans = 0;

        vector<vector<long long>> dp(n + 1, vector<long long>(13, -1));

        for (int i = 0; i < 12; i++)
        {

            ans = (ans + solve(n - 1, i, dp)) % mod;
        }

        return ans % mod;
    }
};
