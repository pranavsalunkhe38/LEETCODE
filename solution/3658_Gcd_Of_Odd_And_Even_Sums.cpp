// LC: 3658 Gcd Of Odd And Even Sums
// Title: Gcd Of Odd And Even Sums
// Difficulty: Easy
// Date: 15 July 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcdOfOddEvenSums(int n) {

        int even = (n * (2 * 2 + (n-1)*2)) / 2;
        int odd = (n * (2 * 1 + (n-1)*2)) / 2;

        return gcd(even, odd);

        
    }
};