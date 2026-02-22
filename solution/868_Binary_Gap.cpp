// LC: 868 Binary Gap
// Title: Binary Gap
// Difficulty: Easy
// Date: 22 Feb 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {

        int prev = -1;
        int index=0;
         int ans = 0;
        while(n > 0){

            if(n%2 == 1){
               if(prev != -1){
                ans = max(ans, index-prev);
               } 

                prev = index;
            }
            index++;
            n /= 2;
        }
       

        return ans;
        
    }
};
