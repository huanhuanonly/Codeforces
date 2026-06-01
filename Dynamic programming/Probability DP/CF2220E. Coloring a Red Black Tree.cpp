/**
 * Codeforces Round 1093 (Div. 2)
 *
 * => E. Coloring a Red Black Tree ( @c 2300 )
 *
 * -> https://codeforces.com/contest/2220/problem/E
 *
 * Submissions ~> https://codeforces.com/contest/2220/submission/372190182 By huanhuanonly
 *
 * @b Expectation-DP and @b Tree-DP
 *
 * ----April 23, 2026 [09h:08m:57s]----
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

#if defined(__SIZEOF_INT128__)
using int128 = __int128;
using uint128 = unsigned __int128;
#endif

using real32 = float;
using real64 = double;

#if defined(__SIZEOF_FLOAT80__)
using real80 = __float80;
#endif

#if defined(__SIZEOF_FLOAT128__)
using real128 = __float128;
#endif

void chmin(auto& lhs, auto&& rhs)
{
    if (rhs < lhs)
    {
        lhs = std::forward<decltype(rhs)>(rhs);
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        std::string s;
        std::cin >> s;

        s.insert(s.begin(), '~');

        std::vector<std::vector<int>> e(n + 1);

        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            std::cin >> u >> v;

            e[u].push_back(v);
            e[v].push_back(u);
        }

        std::vector<int> rcnt(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            if (s[i] == '0')
            {
                for (const auto& j : e[i])
                {
                    if (s[j] == '1')
                    {
                        ++rcnt[i];
                    }
                }
            }
        }

        constexpr auto inf = std::numeric_limits<real80>::max();

        std::vector<bool> vis(n + 1);
        std::vector dp(n + 1, std::array{inf, inf});

        auto dfs = [&](const auto& self, int u, int fa) -> void
        {
            vis[u] = true;

            std::vector<int> son;
            son.reserve(e[u].size());

            for (const auto& v : e[u])
            {
                if (v != fa and s[v] == '0')
                {
                    son.push_back(v);
                    self(self, v, u);
                }
            }

            std::vector<real80> list;
            list.reserve(e[u].size() + 1);

            real80 sum = 0;

            for (const auto& v : son)
            {
                list.push_back(dp[v][0] - dp[v][1]);
                sum += dp[v][1];
            }

            std::ranges::sort(list);
            list.push_back(0);

            for (int c = 0; c <= 1; ++c)
            {
                real80 add = 0;

                for (int i = 0; i < list.size(); ++i)
                {
                    if (const auto cnt = rcnt[u] + i + c; cnt)
                    {
                        chmin(dp[u][c], real80(e[u].size()) / cnt + sum + add);
                    }

                    add += list[i];
                }
            }
        };

        real80 ans = 0;

        for (int i = 1; i <= n; ++i)
        {
            if (not vis[i] and s[i] == '0')
            {
                dfs(dfs, i, 0);
                ans += dp[i][0];
            }
        }

        std::cout << std::fixed << std::setprecision(12) << ans << '\n';
    }

    return 0;
}