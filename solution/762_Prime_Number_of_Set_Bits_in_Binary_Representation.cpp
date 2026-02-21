// LC: 762 Prime Number of Set Bits in Binary Representation
// Title: Prime Number of Set Bits in Binary Representation
// Difficulty: Easy
// Date: 21 Feb 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPrime(long long n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
    }

    int bits(int i){

        int x = 0;
        while(i > 0){
            x += i%2;
            i /= 2;
        }

        return x;
    }

    bool func(int i){
        return isPrime(bits(i));
    }
    int countPrimeSetBits(int left, int right) {

        int ans = 0;
        for(int i=left; i <= right; i++){
            ans += func(i);
        }

        return ans;
        
    }
};
