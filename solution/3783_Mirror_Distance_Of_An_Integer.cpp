// LC: 3783 Mirror Distance Of An Integer
// Title: Mirror Distance Of An Integer
// Difficulty: Easy
// Date: 18 April 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rev(int n){
        int ans = 0;

        while(n > 0){
            ans *= 10;
            ans += n%10;
            n /= 10;
        }

        return ans;
    }
    int mirrorDistance(int n) {
        cout<<rev(n)<<endl;

        return abs(n - rev(n));
        
    }
};