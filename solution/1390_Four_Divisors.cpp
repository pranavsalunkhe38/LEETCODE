// LC: 1390 Four Divisors
// Title: Four Divisors
// Difficulty: Easy
// Date: 04 Jan 2025

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rec(int num)
    {

        int cnt = 2;
        int ans = 1 + num;
        for (int i = 2; i * i <= num; i++)
        {

            if (num % i == 0)
            {

                ans += i;
                if (i != num / i)
                {
                    ans += num / i;
                    cnt += 2;
                }
                else
                {
                    cnt += 1;
                }
            }

            if (cnt > 4)
            {
                return 0;
            }
        }

        if (cnt == 4)
        {
            return ans;
        }

        return 0;
    }
    int sumFourDivisors(vector<int> &nums)
    {
        int ans = 0;

        for (auto i : nums)
        {
            ans += rec(i);
        }

        return ans;
    }
};