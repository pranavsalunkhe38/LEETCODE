// LC: 2833 Furthest Point From Origin
// Title: Furthest Point From Origin
// Difficulty: Easy
// Date: 24 April 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cnt = 0;
        int mov = 0;

        for(auto& i: moves){
            if(i == 'L'){
                cnt++;
            }else if(i == 'R'){
                cnt--;
            }else{
                mov++;
            }
        }

        return max(abs(cnt+mov),abs(cnt-mov));
        
    }
};