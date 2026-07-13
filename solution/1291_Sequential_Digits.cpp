// LC: 1291 Sequential Digits
// Title: Sequential Digits
// Difficulty: Medium
// Date: 13 July 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void func(set<int>& ans, int n, int low, int high){
        long long mask = pow(10, n);

        long long temp{};

        for(int i=1; i < 10; i++){
            temp *= 10;
            temp += i;
            temp = temp % mask;
            // cout<<temp<<endl;

            if(low <= temp && temp <= high){
                ans.insert(temp);
            }

        }

    }

    int digits(int n){
        int ans{};

        while(n > 0){
            ans++;
            n /= 10;
        }

        return ans;
    }
    vector<int> sequentialDigits(int low, int high) {
        set<int> ans;
       auto d1 = digits(low);
       auto d2 = digits(high);
    //    cout<<d1<<" "<<d2<<endl;

       for(int i = d1 ; i <= d2; i++){
            func(ans,i,low,high);
       }

       vector<int> result;

       for(auto i: ans){
            result.push_back(i);
       }



        return result;
        
    }
};