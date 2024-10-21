/**
 * AtCoder Beginner Contest 336
 * 
 * => E - Digit Sum Divisible
 * 
 * -> https://atcoder.jp/contests/abc336/tasks/abc336_e
 * 
 * @b Digit-DP
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

    std::string s;
    std::cin >> s;

    ullong ans = 0;

    for (int i = 1; i <= s.size() * 9; ++i)
    {
        std::vector<std::vector<std::vector<ullong>>> dp(s.size(), std::vector<std::vector<ullong>>(s.size() * 9, std::vector<ullong>(s.size() * 9, ullong(-1))));

        std::function<ullong(int, int, int, bool, bool)> dfs = [&dfs, &dp, &s, k = i](int pos, int sum, int num, bool lead, bool limit) -> ullong
        {
            if (pos == s.size())
                return sum == k and num == 0;
            
            if (not lead and not limit and ~dp[pos][sum][num])
                return dp[pos][sum][num];

            ullong cnt = 0;

            for (int i = 0, up = (limit ? s[pos] - '0' : 9); i <= up; ++i)
            {
                cnt += dfs(pos + 1, sum + i, (num * 10 + i) % k, lead and i == 0, limit and i == up);
            }

            if (not lead and not limit)
                dp[pos][sum][num] = cnt;

            return cnt;
        };

        ans += dfs(0, 0, 0, true, true);
    }

    std::cout << ans;

    return 0;
}