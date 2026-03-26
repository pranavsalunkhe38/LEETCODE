// LC: 3548 Equal Sum Grid Partition II
// Title: Equal Sum Grid Partition II
// Difficulty: Hard
// Date: 26 March 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;

    vector<vector<int>> transpose(const vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> t(m, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                t[j][i] = grid[i][j];
            }
        }
        return t;
    }

    bool canRemoveFromTop(const vector<vector<int>>& grid, int cutRow, int need,
                          unordered_map<int,int>& pre) {
        int rows = cutRow + 1;
        int cols = grid[0].size();

        if (pre[need] == 0) return false;

        if (rows == 1 && cols == 1) return false; // would make it empty

        if (rows == 1) {
            return grid[0][0] == need || grid[0][cols - 1] == need;
        }

        if (cols == 1) {
            return grid[0][0] == need || grid[cutRow][0] == need;
        }

        return true;
    }

    bool canRemoveFromBottom(const vector<vector<int>>& grid, int cutRow, int need,
                             unordered_map<int,int>& suff) {
        int n = grid.size();
        int cols = grid[0].size();
        int rows = n - cutRow - 1;

        if (suff[need] == 0) return false;

        if (rows == 1 && cols == 1) return false; // would make it empty

        if (rows == 1) {
            return grid[n - 1][0] == need || grid[n - 1][cols - 1] == need;
        }

        if (cols == 1) {
            return grid[cutRow + 1][0] == need || grid[n - 1][0] == need;
        }

        return true;
    }

    bool checkCuts(const vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (n == 1) return false; // no horizontal cut possible

        unordered_map<int,int> pre, suff;
        ll sum = 0;

        for (const auto& row : grid) {
            for (int x : row) {
                suff[x]++;
                sum += x;
            }
        }

        ll presum = 0;

        for (int i = 0; i < n - 1; i++) { // cut between i and i+1
            for (int j = 0; j < m; j++) {
                int val = grid[i][j];
                pre[val]++;
                suff[val]--;
                presum += val;
            }

            ll top = presum;
            ll bottom = sum - presum;

            if (top == bottom) return true;

            if (top > bottom) {
                ll need = top - bottom;
                if (need <= INT_MAX && need >= INT_MIN &&
                    canRemoveFromTop(grid, i, (int)need, pre)) {
                    return true;
                }
            } else {
                ll need = bottom - top;
                if (need <= INT_MAX && need >= INT_MIN &&
                    canRemoveFromBottom(grid, i, (int)need, suff)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        if (checkCuts(grid)) return true;                // horizontal cuts
        vector<vector<int>> tg = transpose(grid);
        return checkCuts(tg);                            // vertical cuts
    }
};