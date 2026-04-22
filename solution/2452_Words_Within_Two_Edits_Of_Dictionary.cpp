// LC: 2452 Words Within Two Edits Of Dictionary
// Title: Words Within Two Edits Of Dictionary
// Difficulty: Medium
// Date: 22 April 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possible(const string& a, const string& b){
        int diff = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]) diff++;
            if(diff > 2) return false;
        }
        return true;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        for(auto &q : queries){
            for(auto &d : dictionary){
                if(possible(q, d)){
                    ans.push_back(q);
                    break; // no need to check further
                }
            }
        }

        return ans;
    }
};