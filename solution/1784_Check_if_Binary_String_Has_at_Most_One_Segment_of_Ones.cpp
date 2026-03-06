// LC: 1784 Check if Binary String Has at Most One Segment of Ones
// Title: Check if Binary String Has at Most One Segment of Ones
// Difficulty: Medium
// Date: 06 March 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        int n  = s.size();
        bool flag = false;
        char prev = '0';

       for(int i=0; i <n; i++){

        if(s[i] == '1'){

            if(flag == true){
                return false;
            }

            while(i < n && s[i++] == '1');
            flag = true;

        }

       }

       return true;
        
    }
};
