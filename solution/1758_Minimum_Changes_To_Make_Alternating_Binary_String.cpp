// LC: 1758 Minimum Changes To Make Alternating Binary String
// Title: Minimum Changes To Make Alternating Binary String
// Difficulty: Easy
// Date: 05 March 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int func(string& s, bool a){
        int n = s.size();
        int cnt = 0;

        for(auto i: s){
            if(a == true){
                cnt += (i != '1');
            }else{
                cnt += (i != '0');
            }

            a = !a;
        }

        return cnt;

    }
    int minOperations(string s) {

       
        int ans = min(func(s,true), func(s,false));

    

        return ans;
        
    }
};
