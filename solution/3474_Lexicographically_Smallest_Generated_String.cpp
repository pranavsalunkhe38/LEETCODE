// LC: 3474 Lexicographically Smallest Generated String
// Title: Lexicographically Smallest Generated String
// Difficulty: Hard
// Date: 31 March 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isSame(string ans, string str2,int i){
        for(int k = 0; k < str2.size();k++){
            if(ans[i+k] != str2[k]){
                return false;
            }
        }

        return true;
    }
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        string ans(n+m-1,'*');
        vector<bool> change(n+m-1);

        for(int i=0; i < n; i++){

            if(str1[i] == 'T'){

                for(int j = 0; j < m; j++){
                    if(ans[i+j] == '*'){
                        change[i+j] = false;
                        ans[i+j] = str2[j];
                    }else if(ans[i+j] != str2[j]){
                        return "";
                    }
                }
            }
        }

        for(int i=0; i < ans.size(); i++){
            if(ans[i] == '*'){
                ans[i] = 'a';
                change[i] = true;
            }
        }

        for(int i=0; i < n; i++){
            if(str1[i] == 'F'){

                if(isSame(ans, str2,i)){
                    bool changed = false;
                    for(auto k = i +m -1; k >= i; k--){
                        if(change[k] == true){
                            changed = true;
                            ans[k] = 'b';
                            break;
                        }
                    }

                    if(!changed) return "";
                }
            }
        }
      


        return ans;
    }
};
