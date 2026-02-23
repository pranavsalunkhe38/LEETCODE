// LC: 1461 Check If a String Contains All Binary Codes of Size K
// Title: Check If a String Contains All Binary Codes of Size K
// Difficulty: Medium
// Date: 23 Feb 2026

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        map<string, int> mp;
        for (int i = k; i <= s.size(); i++)
        {
            auto x = s.substr(i - k, k);
            mp[x]++;
            // cout<<x<<endl;
        }

        int val = pow(2, k);

        for (int i = 0; i < val; i++)
        {

            string temp = "";
            //    if(i != 0) continue;
            for (int j = 0; j < k; j++)
            {

                int x = i & (1 << j);
                // cout<<x<<"*"<<endl;

                if (x > 0)
                {
                    temp = '1' + temp;
                }
                else
                {
                    temp = '0' + temp;
                }
            }

            if (mp.find(temp) == mp.end())
            {
                return false;
            }
            // cout<<temp<<endl;
        }

        return true;
    }
};
