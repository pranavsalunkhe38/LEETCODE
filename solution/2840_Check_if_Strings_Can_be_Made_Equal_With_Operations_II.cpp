// LC: 2840 Check if Strings Can be Made Equal With Operations II
// Title: Check if Strings Can be Made Equal With Operations II
// Difficulty: Medium
// Date: 30 March 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n= s1.size();
        string s1_even, s1_odd;
        string s2_even, s2_odd;
        map<char,int> mp1,mp2;


        for(int i=0; i < n; i++){
            if(i % 2 == 0){
                mp1[s1[i]]++;
                mp1[s2[i]]--;
            }else{
                mp2[s1[i]]++;
                mp2[s2[i]]--;
            }
        }

        for(auto i: mp1){
            if(i.second != 0) return false;
        }

        for(auto i: mp2){
            if(i.second != 0) return false;
        }
        return true;
        
    }
};
