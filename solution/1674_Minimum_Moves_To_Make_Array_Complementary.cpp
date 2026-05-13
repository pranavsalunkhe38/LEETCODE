// LC: 1674 Minimum Moves To Make Array Complementary
// Title: Minimum Moves To Make Array Complementary
// Difficulty: HARD
// Date: 14 May 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {

        vector<int> x(limit*2+2,0);

        int n = nums.size();
        for(int i=0; i < n/2; i++){
            int a = nums[i];
            int b = nums[n-i-1];

            x[2] += 2;
            x[2*limit+1] -= 2;
            int minval = min(a,b);
            int maxval = max(a,b);
            x[minval+1] -= 1;
            x[maxval+limit+1] += 1;

            x[a+b] -=1;
            x[a+b+1] += 1;

        }

        int ans = INT_MAX;
        int curr = 0;

        for(int i=2; i <= 2*limit; i++){
            curr += x[i];
            ans = min(ans,curr);
        }

        return ans;


        
    }
};
