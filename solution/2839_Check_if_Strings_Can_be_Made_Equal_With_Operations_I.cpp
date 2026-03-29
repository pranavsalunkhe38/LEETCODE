// LC: 2839 Check if Strings Can be Made Equal With Operations I
// Title: Check if Strings Can be Made Equal With Operations I
// Difficulty: 29 March 2026
// Date: 29 March 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) 
    {
        for(auto i=0; i < 2; i++){

            if(!(s1[i] == s2[i] && s1[i+2] == s2[i+2] || s1[i+2] == s2[i] && s1[i] == s2[i+2])){
                return false;

            }

        }

        return true;
        
    }
};