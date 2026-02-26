// LC: 1404 Number of Steps to Reduce a Number in Binary Representation to One
// Title: Number of Steps to Reduce a Number in Binary Representation to One
// Difficulty: Medium
// Date: 26 Feb 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSteps(string s) {

        int  carry = 0;
        int ans = 0;

        for(int i= s.size()-1;i >= 0; i--){

            int val = carry + (s[i] - '0');

            // cout<<val<<endl;
            
            if(val == 2){
                carry = 1;
                val = 0;
            }
            
            if(val == 1){

                if(i == 0) continue;

                ans += 2;
                carry = 1;
            }else{
                ans += 1;
            }



        }

        return ans;
        
    }
};