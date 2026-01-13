// LC: 3453 Separate SquaresI
// Title: Separate Squares
// Difficulty: Hard *
// Date: 13 Jan 2026

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    double separateSquares(vector<vector<int>>& squares) {

        double t_area = 0, max_y = 0;
        for(auto i: squares){
            t_area += (double)i[2] * i[2];
            max_y = max(max_y,(double)i[2] + i[1]);
        }

        auto check = [&](double limit_y) -> bool {
            double area = 0;
            for(auto& sq: squares){
                int y = sq[1];
                int l = sq[2];

                if(y < limit_y){
                    area += l * min(limit_y - y, (double)l);
                }
            }
            return area >= t_area/2;
        };

        double lo = 0, hi = max_y;
        double eps = 1e-5;
        while(abs(hi - lo) > eps){
            // cout<<x<<endl;
            double mid = (hi + lo) / 2;
            if(check(mid)){
                hi = mid;
            }else{
                lo = mid;
            }
        }
    
        return hi;
        
    }
};
