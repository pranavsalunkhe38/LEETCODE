// LC: 961 N Repeated Element
// Title: N-Repeated Element in Size 2N Array
// Difficulty: Easy
// Date: 02 Jan 2026

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {

        map<int, int> mp;

        for (auto &i : nums)
        {
            if (mp.find(i) != mp.end())
            {
                return i;
            }
            mp[i]++;
        }

        return -1;
    }
};
