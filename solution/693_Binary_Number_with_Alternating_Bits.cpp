// LC: 693 Binary Number with Alternating Bits
// Title: Binary Number with Alternating Bits
// Difficulty: Easy
// Date: 18 Feb 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {

        int prev = -1;

        while(n > 0){
            int x = n%2;
            n/=2;

            if(prev == x){
                return false;
            }
            prev = x;
        }

        return true;
        
    }
};
