// LC: 1009 Complement of Base 10 Integer
// Title: Complement of Base 10 Integer
// Difficulty: Easy
// Date: 11 March 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0){
            return 1;
        }
        int ans=0;
        int index = 0;
        while(n > 0){
            int x = n%2;
            if(x == 0){
                ans = ans | (1 << index);
            }
            n /= 2;
            index++;
        }
        return ans;
        
    }
};
