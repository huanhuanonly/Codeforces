/**
 * Codeforces Round 1043 (Div. 3)
 * 
 * => D. From 1 to Infinity ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/2132/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2132/submission/336414681 By huanhuanonly
 * 
 * @b Digit-DP
 * 
 * ----September 01, 2025 [01h:20m:01s]----
*/

#include <bits/stdc++.h>

using int8 = signed char;
using int16 = short;
using int32 = int;
using int64 = long long;

using uint8 = unsigned char;
using uint16 = unsigned short;
using uint32 = unsigned int;
using uint64 = unsigned long long;

#ifdef __GNUC__
using int128 = __int128;
using uint128 = unsigned __int128;
#endif

using real32 = float;
using real64 = double;
using real128 = long double;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    constexpr uint64 inf = std::numeric_limits<uint64>::max();
    constexpr int maxlen = 18;
    
    std::vector len_dp(maxlen, std::vector(maxlen, inf));
    std::vector sum_dp(maxlen, inf);
    std::vector cnt_dp(maxlen, inf);

    int _;
    std::cin >> _;

    while (_--)
    {
        uint64 k;
        std::cin >> k;

        auto calc = [&](uint64 n) -> std::pair<uint64, uint64>
        {
            auto s = std::to_string(n);
            s.insert(0, std::string(maxlen - 1 - s.size(), '0'));

            auto dfs = [&](const auto& self, int pos, bool limit, bool lead, int clen) -> std::tuple<uint64, uint64, uint64>
            {
                if (not limit and not lead and len_dp[pos][clen] != inf)
                {
                    return {len_dp[pos][clen], sum_dp[pos], cnt_dp[pos]};
                }

                if (pos == s.size())
                {
                    return {clen, 0, 1};
                }

                uint64 len = 0, sum = 0, cnt = 0;

                for (uint64 i = 0, up = (limit ? s[pos] - '0' : 9); i <= up; ++i)
                {
                    auto [nlen, nsum, ncnt] = self(self, pos + 1, limit and i == up, lead and i == 0, lead and i == 0 ? 0 : clen + 1);
                    
                    len += nlen;
                    sum += nsum + i * ncnt;
                    cnt += ncnt;
                }

                if (not limit and not lead)
                {
                    len_dp[pos][clen] = len;
                    sum_dp[pos] = sum;
                    cnt_dp[pos] = cnt;
                }

                return {len, sum, cnt};
            };

            auto [len, sum, cnt] = dfs(dfs, 0, true, true, 0);
            return {len, sum};
        };

        auto check = [&](uint64 mid) -> bool
        {
            return calc(mid).first < k;
        };

        uint64 l = 0, r = 1e15, mid;

        while (r - l > 1)
        {
            mid = l + r >> 1;

            if (check(mid))
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }

        auto [len, sum] = calc(l);

        auto s = std::to_string(l + 1);

        for (int i = 0; i < k - len; ++i)
        {
            sum += s[i] - '0';
        }

        std::cout << sum << '\n';
    }

    return 0;
}