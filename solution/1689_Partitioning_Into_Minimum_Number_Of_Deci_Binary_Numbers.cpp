// LC: 1689 Partitioning Into Minimum Number Of Deci-Binary Numbers
// Title: Partitioning Into Minimum Number Of Deci-Binary Numbers
// Difficulty: Easy
// Date: 01 March 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {

        int ans = 0;

        for(auto& i: n){
            ans = max(i-'0', ans);
        }


        return ans;
        
    }
};
