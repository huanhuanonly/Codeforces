/**
 * The 2022 ICPC Asia Xian Regional Contest
 * 
 * => E. Find Maximum
 * 
 * -> https://codeforces.com/gym/104077/problem/E
 * 
 * @b Digit-DP for find maximum sum of digits in an interval
*/

#include <bits/stdc++.h>

using uint    = unsigned int;
using llong   = long long int;
using ullong  = unsigned long long int;
using ldouble = long double;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __localhost
    ::freopen("Input.txt", "r", stdin);
    ::freopen("Output.txt", "w", stdout);
#endif

    int _;
    std::cin >> _;

    while (_--)
    {
        ullong l, r;
        std::cin >> l >> r;

        std::vector<int> lv;
        std::vector<int> rv;
        
        while (l)
        {
            lv.push_back(l % 3);
            l /= 3;
        }

        while (r)
        {
            rv.push_back(r % 3);
            r /= 3;
        }

        lv.resize(rv.size(), 0);

        std::reverse(lv.begin(), lv.end());
        std::reverse(rv.begin(), rv.end());

        std::vector<int> dp(rv.size(), -1);

        std::function<int(int, bool, bool, bool)> dfs =
            [&](int pos, bool lead, bool low_limit, bool upp_limit) -> int
        {
            if (pos == rv.size())
                return 0;

            if (not low_limit and not upp_limit and ~dp[pos])
                return dp[pos];

            int mx = 0;

            int lo = low_limit ? lv[pos] : 0;
            int up = upp_limit ? rv[pos] : 2;

            for (int i = lo; i <= up; ++i)
            {
                mx = std::max(mx, dfs(pos + 1, lead and i == 0, low_limit and i == lo, upp_limit and i == up) + i + not(lead and i == 0));
            }

            if (not low_limit and not upp_limit)
                dp[pos] = mx;

            return mx;
        };

        std::cout << dfs(0, true, true, true) << '\n';
    }

    return 0;
}