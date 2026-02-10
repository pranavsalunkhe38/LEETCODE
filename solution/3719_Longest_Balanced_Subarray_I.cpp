// LC: 3719 Longest Balanced Subarray I
// Title: Longest Balanced Subarray I
// Difficulty: Medium
// Date: 10 Feb 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
       for(int i=0; i < n ;i++){
        map<int,int> even,odd;
       
        for(int j=i; j < n; j++){

            if(nums[j] % 2 == 0){
                even[nums[j]]++;
            }else{
                odd[nums[j]]++;    
            }
            // cout<<even.size()<<" "<<odd.size()<<endl;

            if(even.size() == odd.size()){
                ans = max(ans,j-i+1);
            }
        }
       }
       
        
        return ans;
    }
};
