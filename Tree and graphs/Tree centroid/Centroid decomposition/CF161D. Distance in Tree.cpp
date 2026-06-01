/**
 * VK Cup 2012 Round 1
 * 
 * => D. Distance in Tree ( @c 1800 )
 * 
 * -> https://codeforces.com/contest/161/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/161/submission/370312668 By huanhuanonly
 * 
 * @b Centroid-decomposition
 * 
 * ----April 09, 2026 [01h:29m:14s]----
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

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> e(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    uint64 ans = 0;

    std::vector<bool> removed(n + 1);
    std::vector<int> sizes(n + 1);

    std::vector<int> occur(std::max(n, k + 1));

    auto calc = [&](int u) -> void
    {
        std::vector<int> que;

        auto add = [&](const auto& self, int u, int fa, int dis) -> void
        {
            if (removed[u])
            {
                return;
            }

            ++occur[dis];
            que.push_back(dis);

            for (const auto& v : e[u])
            {
                if (v != fa)
                {
                    self(self, v, u, dis + 1);
                }
            }
        };

        auto check = [&](const auto& self, int u, int fa, int dis) -> void
        {
            if (removed[u])
            {
                return;
            }

            if (k >= dis)
            {
                ans += occur[k - dis];
            }

            for (const auto& v :  e[u])
            {
                if (v != fa)
                {
                    self(self, v, u, dis + 1);
                }
            }
        };

        for (const auto& v : e[u])
        {
            check(check, v, u, 1);
            add(add, v, u, 1);
        }

        ans += occur[k];

        for (const auto& i : que)
        {
            occur[i] = 0;
        }
    };

    auto find_centroid = [&](int u) -> int
    {
        std::vector<int> que;

        auto build = [&](const auto& self, int u, int fa) -> void
        {
            if (removed[u])
            {
                return;
            }

            que.push_back(u);
            sizes[u] = 1;

            for (const auto& v : e[u])
            {
                if (v != fa)
                {
                    self(self, v, u);
                    sizes[u] += sizes[v];
                }
            }
        };

        build(build, u, u);

        for (const auto& v : que)
        {
            std::priority_queue<int> pque;

            for (const auto& i : e[v])
            {
                pque.push(sizes[i]);
            }

            if (v != u)
            {
                pque.pop();
            }

            pque.push(sizes[u] - sizes[v]);

            if (pque.top() <= sizes[u] / 2)
            {
                return v;
            }
        }

        assert(false);
        return 0;
    };

    auto dfs = [&](const auto& self, int u) -> void
    {
        calc(u);
        removed[u] = true;
        sizes[u] = 0;

        for (const auto& v : e[u])
        {
            if (not removed[v])
            {
                self(self, find_centroid(v));
            }
        }
    };

    dfs(dfs, find_centroid(1));

    std::cout << ans << '\n';

    return 0;
}