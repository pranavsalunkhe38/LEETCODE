// LC: 190 Reverse Bits
// Title: Reverse Bits
// Difficulty: Easy
// Date: 16 Feb 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;

      for(int i=0;i < 32;i++){
        int val = n & (1 << i);
        if(val != 0){
            int index = (31 - i);
            ans |= (1<<index);
        }
      }

        return ans;
        
    }
};
