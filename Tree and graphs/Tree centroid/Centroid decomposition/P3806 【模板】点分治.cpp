/**
 * => P3806 【模板】点分治 ( @c 提高+/省选− )
 * 
 * -> https://www.luogu.com.cn/problem/P3806
 * 
 * Submissions ~> https://www.luogu.com.cn/record/272811456 By huanhuanonly
 * 
 * @b Centroid-decomposition
 * 
 * ----April 09, 2026 [00h:32m:37s]----
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

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> e(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v, w;
        std::cin >> u >> v >> w;

        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }

    std::vector<int> queries(m);
    std::vector<bool> ans(m);

    for (int i = 0; i < m; ++i)
    {
        std::cin >> queries[i];
    }

    std::vector<bool> removed(n + 1);
    std::vector<int> sizes(n + 1);

    std::vector<bool> occur(1e8 + 1);
    occur[0] = true;

    auto calc = [&](int u) -> void
    {
        std::vector<int> que;

        auto add = [&](const auto& self, int u, int fa, int dis) -> void
        {
            if (removed[u])
            {
                return;
            }

            occur[dis] = true;
            que.push_back(dis);

            for (const auto& [v, w] : e[u])
            {
                if (v != fa)
                {
                    self(self, v, u, dis + w);
                }
            }
        };

        auto check = [&](const auto& self, int u, int fa, int dis) -> void
        {
            if (removed[u])
            {
                return;
            }

            for (int i = 0; i < m; ++i)
            {
                if (queries[i] >= dis and occur[queries[i] - dis])
                {
                    ans[i] = true;
                }
            }

            for (const auto& [v, w] :  e[u])
            {
                if (v != fa)
                {
                    self(self, v, u, dis + w);
                }
            }
        };

        for (const auto& [v, w] : e[u])
        {
            check(check, v, u, w);
            add(add, v, u, w);
        }

        for (const auto& i : que)
        {
            occur[i] = false;
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

            for (const auto& [v, w] : e[u])
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

            for (const auto& [i, w] : e[v])
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

        for (const auto& [v, w] : e[u])
        {
            if (not removed[v])
            {
                self(self, find_centroid(v));
            }
        }
    };

    dfs(dfs, find_centroid(1));

    for (const bool yes : ans)
    {
        if (yes)
        {
            std::cout << "AYE\n";
        }
        else
        {
            std::cout << "NAY\n";
        }
    }

    return 0;
}