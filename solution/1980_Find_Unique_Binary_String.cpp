// LC: 1980 Find Unique Binary String
// Title: Find Unique Binary String
// Difficulty: Medium
// Date: 08 March 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int string2binary(string s){
        int ans = 0;

        for(auto i: s){
            ans = ans << 1;
            ans |= (i == '1') ? 1:0;
        }

        return ans;
    }

    string binary2string(int i,int n){
        string ans = "";

        while(i > 0){ 
            int rem = i%2;
            char q =  (rem == 1) ? '1':'0';
            ans = q + ans;
            i/= 2;
        }

        int x = ans.size();

        for(int i=ans.size(); i < n; i++){
            ans = '0'+ans;
        }


        return ans;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        set<int> st;

        for(auto i: nums){
            auto val = string2binary(i);
            st.insert(val);
            // cout<<val<<endl;
        }

        int lim = pow(2,nums.size()+1);
        for(int i=0; i < lim; i++){
            if(st.count(i) == 0){
                return binary2string(i,nums.size());
            }
        }

        return "";
    }
};
