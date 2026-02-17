// LC: 401 Binary Watch
// Title: Binary Watch
// Difficulty: Easy
// Date: 17 Feb 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int mask = 15;
    int mask2 = 4;
    vector<string> res;
public:
    void func(int temp){
        int min = temp >> mask2;
        int hour = temp & mask;

        if(hour > 11 || min > 59){
            cout<<temp<<endl;
            return;
        }

        string h = to_string(hour);
        string m = min < 10 ? "0":"";
        m += to_string(min);

        string ans = h + ":" + m;
        res.push_back(ans);

    }
    void rec(int i, int& ones,int& temp){
        if(ones == 0){
            func(temp);
            return;
        }
        if( i > 9){
            return;
        }
        //not pick
        rec(i+1,ones,temp);
        // pick
        temp = temp | (1 << i);
        ones--;
        rec(i+1,ones, temp );
        ones++;
        temp = temp & ~(1 << i);

    }
    vector<string> readBinaryWatch(int turnedOn) {
        int temp = 0;
        rec(0, turnedOn, temp);

        return res;
        
    }
};