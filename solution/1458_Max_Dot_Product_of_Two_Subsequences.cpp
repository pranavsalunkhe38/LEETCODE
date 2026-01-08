// LC: 1458 Max Dot Product of Two Subsequences
// Title: Max Dot Product of Two Subsequences
// Difficulty: Hard
// Date: 08 Jan 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const long long NEG = (long long)-4e18;
    vector<vector<long long>> memo;
    vector<vector<char>> vis;

    long long solve(vector<int>& a, vector<int>& b, int i, int j) {
        if (i < 0 || j < 0) return NEG;
        if (vis[i][j]) return memo[i][j];
        vis[i][j] = 1;

        long long prod = 1LL * a[i] * b[j];

        long long best = prod; // start subsequence here

        // skip one element
        best = max(best, solve(a, b, i-1, j));
        best = max(best, solve(a, b, i, j-1));

        // extend subsequence
        long long diag = solve(a, b, i-1, j-1);
        if (diag != NEG) best = max(best, prod + max(0LL, diag));

        return memo[i][j] = best;
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = (int)nums1.size(), m = (int)nums2.size();
        memo.assign(n, vector<long long>(m, 0));
        vis.assign(n, vector<char>(m, 0));
        return (int)solve(nums1, nums2, n-1, m-1);
    }
};
