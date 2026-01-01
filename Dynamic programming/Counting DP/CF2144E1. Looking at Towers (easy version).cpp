/**
 * Educational Codeforces Round 182 (Rated for Div. 2)
 * 
 * => E1. Looking at Towers (easy version) ( @c 2200 )
 * 
 * -> https://codeforces.com/contest/2144/problem/E1
 * 
 * Submissions ~> https://codeforces.com/contest/2144/submission/345372317 By huanhuanonly
 * 
 * @b Combinatorics
 * @b Counting-DP
 * @b 2D-Prefix-sum
 * 
 * ----October 23, 2025 [23h:19m:39s]----
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

    constexpr uint64 maxn = 5000;
    constexpr uint64 mod  = 998244353;

    std::vector<uint64> pow2(maxn + 1, 1);

    for (int i = 1; i < pow2.size(); ++i)
    {
        pow2[i] = pow2[i - 1] * 2 % mod;
    }

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        std::vector<int> v(n + 1);
        std::vector<int> s(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
            s[i] = v[i];
        }

        std::ranges::sort(s);
        s.erase(std::ranges::unique(s).begin(), s.end());

        std::ranges::transform(v, v.begin(), [&s](int i) -> int 
        {
            return std::ranges::lower_bound(s, i) - s.begin();
        });


        std::vector pre(n + 1, std::vector<int>(s.size()));

        for (int i = 1; i <= n; ++i)
        {
            ++pre[i][v[i]];
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j < s.size(); ++j)
            {
                pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            }
        }


        std::vector<int> ls{v[1]}, rs{v[n]};

        for (int i = 2; i <= n; ++i)
        {
            if (v[i] > ls.back())
            {
                ls.push_back(v[i]);
            }
        }

        for (int i = n - 1; i >= 1; --i)
        {
            if (v[i] > rs.back())
            {
                rs.push_back(v[i]);
            }
        }

        static auto $ = [](const auto& v, int value) -> int
        {
            auto it = std::ranges::lower_bound(v, value);

            if (*it == value)
            {
                return it - v.begin();
            }
            else
            {
                return v.end() - v.begin();
            }
        };


        std::vector<std::vector<int>> pos(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            pos[$(ls, v[i])].push_back(i);
        }

        std::vector<uint64> f(n + 1);
        std::vector<uint64> g(n + 1);

        for (int i : pos[0])
        {
            f[i] = 1;
        }

        for (int layer = 1; layer < ls.size(); ++layer)
        {
            for (int i : pos[layer])
            {
                for (int j : pos[layer - 1] | std::views::take_while([i](int j) -> bool { return j < i; }))
                {
                    f[i] += f[j] * pow2[pre[i - 1][v[j]] - pre[j][v[j]]] % mod;
                    f[i] %= mod;
                }
            }
        }

        for (auto& i : pos)
        {
            i.clear();
        }

        for (int i = n; i >= 1; --i)
        {
            pos[$(rs, v[i])].push_back(i);
        }

        for (int i : pos[0])
        {
            g[i] = 1;
        }

        for (int layer = 1; layer < rs.size(); ++layer)
        {
            for (int i : pos[layer])
            {
                for (int j : pos[layer - 1] | std::views::take_while([i](int j) -> bool { return j > i; }))
                {
                    g[i] += g[j] * pow2[pre[j - 1][v[j]] - pre[i][v[j]]] % mod;
                    g[i] %= mod;
                }
            }
        }

        auto& posmax = pos[rs.size() - 1];

        uint64 ans = 0;

        for (int i : posmax)
        {
            ans += f[i] * g[i] % mod;
            ans %= mod;
        }

        for (int i = 0; i < posmax.size(); ++i)
        {
            for (int j = i + 1; j < posmax.size(); ++j)
            {
                ans += f[posmax[j]] * pow2[posmax[i] - posmax[j] - 1] % mod * g[posmax[i]] % mod;
                ans %= mod;
            }
        }

        std::cout << ans << '\n';
    }

    return 0;
}