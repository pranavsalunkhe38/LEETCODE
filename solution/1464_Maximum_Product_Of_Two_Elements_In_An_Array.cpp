// LC: 1464 Maximum Product Of Two Elements In An Array
// Title: Maximum Product Of Two Elements In An Array
// Difficulty: Easy
// Date: 27 July 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m1 = INT_MIN;
        int m2 = INT_MIN;

        for(auto i: nums){

            if(i > m1){
                m2 = m1;
                m1 = i;
                continue;
            }

            m2 = max(m2, i);
        }

        return (m1-1) * (m2-1);
        
    }
};
