// LC: 1888 Minimum Number of Flips to Make the Binary String Alternating
// Title: Minimum Number of Flips to Make the Binary String Alternating
// Difficulty: Medium
// Date: 07 March 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

int func(string& s, bool a){
        int n = s.size();
        int cnt = 0;

        for(auto i: s){
            if(a == true){
                cnt += (i != '1');
            }else{
                cnt += (i != '0');
            }

            a = !a;
        }

        return cnt;

    }

    int minFlips(string s) {

         int res1=0, res2 = 0;
         bool x = false;

         for(auto i: s){

            if(x == false)
            {
                if( i == '0'){
                res2++;
            }else{
                res1++;
            }
            }else{
            
             if( i == '1'){
                res2++;
            }else{
                res1++;
            }
            }

            x = !x;
         }

         bool y = false;

         int ans = min(res1,res2);

         for(auto i: s){


            if(y == false)
            {
                if( i == '0'){
                res2--;
            }else{
                res1--;
            }
            }else{
            
             if( i == '1'){
                res2--;
            }else{
                res1--;
            }
            }


            
            
            if(x == false)
            {
                if( i == '0'){
                res2++;
            }else{
                res1++;
            }
            }else{
            
             if( i == '1'){
                res2++;
            }else{
                res1++;
            }

            }
            // cout<<res1<<" "<<res2<<endl;

            x = !x;
            y = !y;
            ans = min(ans,min(res1,res2));
         }
           
    

        return ans;
        
    }
};