// LC: 3345 Smallest Divisible Digit Product I
// Title: Smallest Divisible Digit Product I
// Difficulty: Easy
// Date: 06 August 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int product(int n){
        int ans = 1;

        while(n > 0){
            if(ans == 0) break;
            ans *= (n%10);
            n /= 10;
        }


        return ans;
    }
    int smallestNumber(int n, int t) {

        while(true){

            if(product(n) % t == 0){
                return n;
            }
            n++;

        }
        
    }
};
