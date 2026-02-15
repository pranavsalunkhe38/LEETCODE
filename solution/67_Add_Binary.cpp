// LC: 67 Add Binary
// Title: Add Binary
// Difficulty: Easy
// Date: 15 Feb 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {

        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        string ans = "";

        while(i >= 0 || j >= 0 || carry > 0){
            int x = i >= 0 ? a[i--] - '0' : 0;
            int y  = j >= 0 ? b[j--] - '0' : 0;
            int res = x + y + carry;
            carry = res/2;
            ans = to_string(res%2) + ans;
            

        }
        return ans;

        
    }
};
