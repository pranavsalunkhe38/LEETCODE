// LC: 2573 Find the String with LCP
// Title: Find the String with LCP
// Difficulty: Hard
// Date: 28 March 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {

        int n = lcp.size();
        // for(auto i: lcp){
        //     for(auto j: i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }

        string ans(n, '*');

        
        char c = 'a';

        for(int i = 0 ; i < n; i++){

            if(lcp[i][i] != n - i) return "";

            if(ans[i] == '*'){
                if(c > 'z') return "";
             ans[i] = c++;
            }

            for(int j = i+1; j < n ; j++){
                int mn= n - max(i,j);

                if(lcp[i][j] != lcp[j][i] || lcp[i][j] > mn) return "";

                if(lcp[i][j]  != 0){
                    // cout<<"here"<<endl;
                    ans[j] = ans[i];
                }

            }
            // c++;
        }

        vector<vector<int>> check(n, vector<int>(n));

        for(int i=n-1; i >= 0; i--){
            for(int j=n-1; j >= 0; j--){
                // cout<<ans[i]<<" "<<ans[j]<<endl;
                int val = (ans[i] == ans[j]);
//  cout<<ans[i]<<" "<<ans[j]<<" "<<val<<endl;

                if(val == 1 && i+1 < n && j+1 < n){
                    
                    if(ans[i+1] == ans[j+1]){
                        val += check[i+1][j+1];
                    }
                }

                check[i][j] = val;
            }
        }
// 
        // cout<<ans<<endl;

        // for(auto i: check){
        //     for(auto j: i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }


        if(check == lcp) return ans;

        return "";



        return ans;
        
    }
};