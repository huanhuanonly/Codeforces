/**
 * Codeforces Round 1042 (Div. 3)
 * 
 * => G. Wafu! ( @c 2000 )
 * 
 * -> https://codeforces.com/contest/2131/problem/G
 * 
 * Submissions ~> https://codeforces.com/contest/2131/problem/G By huanhuanonly
 * 
 * @b DP and @b Dfs
 * 
 * ----August 13, 2025 [01h:53m:32s]----
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

    constexpr uint64 mod = 1e9 + 7;

    std::vector<uint64> dp(1), cnt(1);

    for (int i = 1; cnt.back() <= 1e9; ++i)
    {
        dp.push_back(i);
        cnt.push_back(1);

        for (int j = 1; j < i; ++j)
        {
            dp.back() *= dp[j];
            dp.back() %= mod;

            cnt.back() += cnt[j];
        }
    }

    int _;
    std::cin >> _;

    while (_--)
    {
        uint64 n, k;
        std::cin >> n >> k;

        std::vector<uint64> v(n);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> v[i];
        }

        std::ranges::sort(v);

        auto iota = std::views::iota(1);

        uint64 ans = 1;

        auto dfs = [&](const auto& self, const auto& s) -> void
        {
            if (k == 0)
            {
                return;
            }

            for (const auto& i : s)
            {
                if (i < dp.size() and k >= cnt[i])
                {
                    (ans *= dp[i]) %= mod;

                    if ((k -= cnt[i]) == 0)
                    {
                        break;
                    }
                }
                else
                {
                    (ans *= i) %= mod;
                    --k;

                    self(self, iota);
                    break;
                }
            }
        };

        dfs(dfs, v);

        std::cout << ans << '\n';
    }

    return 0;
}