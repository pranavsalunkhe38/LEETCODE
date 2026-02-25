// LC: 1356 Sort Integers by The Number of 1 Bits
// Title: Sort Integers by The Number of 1 Bits
// Difficulty: Easy
// Date: 25 Feb 2026

class Solution {
public:


    vector<int> sortByBits(vector<int>& arr) {

        sort(arr.begin(), arr.end(), [](int a, int b){

            auto ones = [](int v){
    int n = 0;

    while(v > 0){
        n += v%2;
        v /= 2;
    }
    
    return n;
};

                    int x = ones(a);
        int y = ones(b);

        if(x == y) return b > a;

        return y > x;

        });

        return arr;
        
    }
};