// LC: 3622 Check Divisibility By Digit Sum And Product
// Title: Check Divisibility By Digit Sum And Product
// Difficulty: Easy
// Date: 22 August 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getDigitSum(int n){
        int sum = 0;
        int prod = 1;

        while(n > 0){
            sum += n%10;
            prod *= n%10;
            n /= 10;
        }

        return sum + prod;
    }
    bool checkDivisibility(int n) {
        int val = getDigitSum(n);
        cout<<val<<endl;

        return n % val == 0;
        
    }
};
