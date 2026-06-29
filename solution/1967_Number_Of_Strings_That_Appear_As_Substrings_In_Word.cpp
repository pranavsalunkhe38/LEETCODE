// LC: 1967 Number Of Strings That Appear As Substrings In Word
// Title: Number Of Strings That Appear As Substrings In Word
// Difficulty: Easy
// Date: 29 June 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        int n = word.size();

        for(auto pattern: patterns){
            // cout<<pattern.size()<<" "<<n<<endl; 
            int n_ = pattern.size();
            if(n_ > n) continue;

            for(int j=0; j <= n-n_; j++){

                if(pattern == word.substr(j, n_)){
                    count++;
                    break;
                }

            }
        }

        return count;
        
    }
};
