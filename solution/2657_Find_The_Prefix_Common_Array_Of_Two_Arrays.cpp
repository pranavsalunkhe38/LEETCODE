// LC: 2657 Find The Prefix Common Array Of Two Arrays
// Title: Find The Prefix Common Array Of Two Arrays
// Difficulty: Easy
// Date: 20 May 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int> st1;
        set<int> st2;
        int n = A.size();
        int ans =0;
        vector<int> res;
        for(int i=0; i < n; i++){

            if(A[i] == B[i]){
                ans++;
            }else{
                if(st2.find(A[i]) != st2.end()){
                    ans++;
                }

                if(st1.find(B[i]) != st1.end()){
                    ans++;
                }
            }

            st1.insert(A[i]);
            st2.insert(B[i]);
            res.push_back(ans);

        }

        return res;
        
    }
};
