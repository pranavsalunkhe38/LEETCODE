// LC: 3010 Divide an Array Into Subarrays With Minimum Cost I
// Title: Divide an Array Into Subarrays With Minimum Cost I
// Difficulty: Easy
// Date: 01 Feb 2026

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumCost(vector<int> &nums)
    {
        int ans = *nums.begin();

        vector<int> temp(nums.begin() + 1, nums.end());
        sort(temp.begin(), temp.end());

        ans += temp[0];
        ans += temp[1];

        return ans;
    }
};
