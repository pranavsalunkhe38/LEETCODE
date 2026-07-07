// LC: 3754 Concatenate Non-zero Digits And Multiply By Sum I
// Title: Concatenate Non-zero Digits And Multiply By Sum I
// Difficulty: Easy
// Date: 07 July 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long temp = n;
        long long x = 0;
        long long mul = 1;
        long long sum = 0;
        while(temp > 0){

            int val = temp%10;
            temp /= 10;

            sum += val;

            if(val == 0) continue;

            x += mul * val;
            mul *= 10;
        }

        return sum * x;
        
    }
};
