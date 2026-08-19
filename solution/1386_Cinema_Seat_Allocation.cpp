// LC: 1386 Cinema Seat Allocation
// Title: Cinema Seat Allocation
// Difficulty: Medium
// Date: 19 August 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    map<int,int> mp1 = {{2,1},{3,1},{4,2},{5,2},{6,3},{7,3},{8,4},{9,4}};
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = 0;
        map<int, vector<int>> mp;

        for(auto i: reservedSeats){

            if(i[1] == 1 || i[1] == 10){
                continue;
            }

            mp[i[0]].push_back(i[1]);

        }

        for(auto it: mp){
            int row = it.first;
            auto seats = it.second;

            bool first = false;
            bool second = false;
            bool third = false;

            cout<<"row "<<row<<endl;

            for(auto seat: seats){

                int val = mp1[seat];

                first |= (val == 1 || val == 2);
                second |= (val == 2 || val == 3);
                third |= (val == 3 || val == 4); 

                cout<<seat<<" ";

            }
            cout<<endl;

            ans += (first == false || second == false || third == false);
            cout<<"ans "<<ans<<endl;
        }

        ans += (2 * (n - mp.size()));

        return ans;
    }
};
