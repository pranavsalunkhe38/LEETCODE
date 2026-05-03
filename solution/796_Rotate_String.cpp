// LC: 796 Rotate String
// Title: Rotate String
// Difficulty: Easy
// Date: 03 May 2026

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        s += s;

        for(int i=0; i < n; i++){
            if(s.substr(i,n) == goal){
                return true;
            }
        }


        return false;
        
    }
};