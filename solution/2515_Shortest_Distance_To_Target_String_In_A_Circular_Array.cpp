// LC: 2515 Shortest Distance To Target String In A Circular Array
// Title: Shortest Distance To Target String In A Circular Array
// Difficulty: Easy
// Date: 15 April 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = INT_MAX;
        int n = words.size();
        for(int i=0; i < n ;i++){
            
            if(words[i] == target){
                int val1 = abs(startIndex - i);
                int val2 = n - val1;
                ans = min(ans, val1);
                ans = min(ans, val2);

            }
        }

        return ans == INT_MAX ? -1: ans;
        
    }
};
