// LC: 1081 Smallest Subsequence Of Distinct Characters
// Title: Smallest Subsequence Of Distinct Characters
// Difficulty: Medium
// Date: 19 July 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;
        map<char,int> mp;
        set<char> ss;

        for(auto i: s){
            mp[i]++;
        }


        for(auto i: s){
            mp[i]--;

            if(ss.find(i) != ss.end()) continue;

            

            while(!st.empty() && st.top() > i){

                int tp = st.top();
                if(mp[tp] > 0){
                    ss.erase(tp);
                    st.pop();
                }else{
                    break;
                }

            }

            st.push(i);
            ss.insert(i);
        }

        string ans = "";

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;

        
    }
};