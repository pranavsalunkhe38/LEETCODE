// LC: 85 Maximal Rectangle
// Title: Maximal Rectangle
// Difficulty: Hard
// Date: 11 Jan 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int histo(vector<int>& h){
        stack<int> st;
        int n =  h.size();
        int best = 0;

        for(int i=0; i <= n;i++ ){
            auto curr = (i == n) ? 0 : h[i];
            while(!st.empty() && h[st.top()] > curr){
                int height = h[st.top()];st.pop();
                int left = st.empty() ? -1: st.top();
                int width = i - left - 1;
                best = max(best, height * width);
            }
            st.push(i);
        }

        return best;
        
    }

    int solve(vector<vector<char>>& matrix){
        int x = matrix.size();
        int y = matrix[0].size();

        vector<vector<int>> dp(x, vector<int>(y,0));

        for(int i=0; i < y; i++){
            dp[x-1][i] = matrix[x-1][i] - '0';
        }

        for(int i=x-2; i >= 0; i--){
            for(int j = 0; j < y;j++){
                if((matrix[i][j] - '0') == 1)
                    dp[i][j] = 1 + dp[i+1][j];

            }
        }

        int ans = 0;

        for(auto& i: dp){

         ans = max(ans, histo(i));
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        
        return solve(matrix);
        
    }
};
