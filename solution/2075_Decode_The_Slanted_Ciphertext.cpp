// LC: 2075 Decode The Slanted Ciphertext
// Title: Decode The Slanted Ciphertext
// Difficulty: Medium
// Date: 04 April 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string func(string encodedText, int rows,int cols){
        string ans;
       
        for(int i = 0; i < cols; i++){
            for(int j=0; j< rows;j++){
                // cout<<(cols * j)<<" "<<(i+j)<<endl;
                int val = (cols * j) + (i+j);
                // cout<<val<<endl;
                if(val > encodedText.size()-1){
                 break;
                 }
                ans += encodedText[val];
                // cout<<ans<<endl;
                
            }
        }

        int x = ans.size()-1;
        while(x >= 0 && ans[x] == ' '){
            x--;
        }

        // cout<<x<<endl;

        ans = ans.substr(0, x+1);

        return ans;
    }
    string decodeCiphertext(string encodedText, int rows) {
        int cols = encodedText.size()/rows;

        return func(encodedText, rows, cols);

        
    }
};