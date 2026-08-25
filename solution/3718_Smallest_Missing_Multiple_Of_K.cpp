// LC: 3718 Smallest Missing Multiple Of K
// Title: Smallest Missing Multiple Of K
// Difficulty: Easy
// Date: 25 August 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
         
         set<int> st;

         for(auto i: nums){
            st.insert(i);
         }

         for(int i=1;; i++)
         {
            if(st.find(i*k) == st.end()){
                return i*k;
            }
         }

         return -1;
    }
};
