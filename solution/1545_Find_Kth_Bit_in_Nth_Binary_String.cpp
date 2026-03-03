// LC: 1545 Find Kth Bit in Nth Binary String
// Title: Find Kth Bit in Nth Binary String
// Difficulty: Medium
// Date: 03 March 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

string invert(string s){
    for(auto& i: s){
        if(i == '1'){
            i = '0';
        }else{
            i = '1';
        }
    }

    return s;
}
string rev(string s){
    reverse(s.begin(),s.end());
    return s;
}

    int rec( int k, string s){

        if(s.size() < k) {
            s = s + '1' + rev(invert(s));
            return rec(k,s);
        }


        return s[k-1];
    }
    char findKthBit(int n, int k) {
        string ans = "0";


        return rec(k,ans);
    }
};
