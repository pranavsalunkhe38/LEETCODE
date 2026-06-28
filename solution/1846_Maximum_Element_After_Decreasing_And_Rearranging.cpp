// LC: 1846 Maximum Element After Decreasing And Rearranging
// Title: Maximum Element After Decreasing And Rearranging
// Difficulty: Medium
// Date: 28 June 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = 1;
        int n = arr.size();
        int curr=1;

        for(int i=1; i < n; i++){

           curr = min(curr+1, arr[i]);
        }

        return curr;
        
    }
};
