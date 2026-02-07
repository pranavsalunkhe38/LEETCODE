// LC: 1653 Minimum Deletions to Make String Balanced
// Title: Minimum Deletions to Make String Balanced
// Difficulty: Medium
// Date: 07 Feb 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();

        vector<int> as(n,0);
        vector<int> bs(n, 0);

        for(int i=0; i < n; i++){
            int val = s[i] == 'a';
            if(i == 0){
                as[i] = val;
            }else{
                as[i] = as[i-1] + val; 
            }
        }


         for(int i=n-1; i >= 0; i--){
            int val = s[i] == 'b';
            if(i == n-1){
                bs[i] = val;
            }else{
                bs[i] = bs[i+1] + val; 
            }
        }
        int ans = INT_MAX;

        for(int i=0 ; i < s.size(); i++){
            ans= min(ans, n - (as[i] + bs[i]));

        }

        return ans;
        
    }
};