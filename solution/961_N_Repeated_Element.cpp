// LC: 961 N Repeated Element
// Title: N-Repeated Element in Size 2N Array
// Difficulty: Easy
// Date: 02 Jan 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int c = 1;
        vector<int> ans;

       for(int i=digits.size()-1;i>=0;i--){
            int val = c + digits[i];
            // cout<<val<<endl;
            c = val/10;
            ans.push_back(val%10);
       }

        if(c != 0){
            ans.push_back(c);
        }
       reverse(ans.begin(), ans.end());


        return ans;
        
    }
};