// LC: 1871 Jump Game Vii
// Title: Jump Game Vii
// Difficulty: Medium
// Date: 25 May 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.size();
        
        int tally = 0;

        for(int i=n-minJump; i < n-1; i++){
            s[i] = '1';

        }

        for(int i=n-minJump-1; i >= 0; i--){
           
           tally += (s[i+minJump] - '0');
            
            if(i+maxJump+1 < n){
                tally -= (s[i+maxJump+1] - '0');
            }

            int window = min(i+maxJump,n-1) - (i+minJump)+1;
            //     cout<<min(i+maxJump,n-1)<<" "<<(i+minJump)<<endl;
            //  cout<<i<<" "<<tally<<" "<<window<<endl;
            if(tally == window){
                // cout<<"here"<<endl ;
                s[i] = '1';
            }
        }

        // cout<<s<<endl;

        return s[0] == '0';
        
    }
};
