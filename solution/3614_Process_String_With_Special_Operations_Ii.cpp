// LC: 3614 Process String With Special Operations Ii
// Title: Process String With Special Operations Ii
// Difficulty: HARD
// Date: 18 June 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getlen(string s){

        long long ans = 0;
        for(auto i: s){

            switch(i){
                case '*':
                    if(ans > 0) ans--;
                    
                    break;
                case '#':
                    ans = 2 * ans;
                    break;
                case '%':
                    break;
                default:
                    ans++;
            }
        }

        return ans;

    }
    char processStr(string s, long long k) {

        long long size = getlen(s);
        char ans = '.';

        if( k < 0 || k >= size) return '.';

                    cout<<size<<" "<<k<<endl;

        for(int i=s.size()-1; i >= 0; i--){

            switch(s[i]){
        
                case '*':
                    size++;
                    break;
                case '#':
                    size /= 2;
                    k = k % size;
                    break;
                case '%':
                    k = size - k - 1;
                    break;
                default:
                    size--;
                    break;
            }

            if(size == k){
                return ans = s[i];
            }

            // cout<<size<<" "<<k<<endl; 
       

        }


        return ans;
        

    }
};