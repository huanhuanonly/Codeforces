/**
 * NOIP2018提高组自测
 *
 * => P5021 [NOIP 2018 提高组] 赛道修建 ( @c 提高+/省选− )
 *
 * -> https://www.luogu.com.cn/problem/P5021
 *
 * Submissions ~> https://www.luogu.com.cn/record/278741051 By huanhuanonly
 *
 * @b Binary-search
 * @b Dfs on @a Trees
 * @b Greedy
 *
 * ----May 21, 2026 [17h:15m:23s]----
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

    const int root = std::ranges::find(e, 1, [](const auto& e) { return e.size(); }) - e.begin();

    auto check = [&](int mid) -> bool
    {
        int cnt = 0;

        auto dfs = [&](const auto& self, int u, int fa) -> int
        {
            std::multiset<int> set;

            for (const auto& [v, w] : e[u])
            {
                if (v != fa)
                {
                    set.insert(self(self, v, u) + w);
                }
            }

            for (; not set.empty() and *set.rbegin() >= mid; ++cnt, set.erase(std::prev(set.end())));

            int max = 0;

            for (auto it = set.begin(); it != set.end(); )
            {
                const int value = *it;
                it = set.erase(it);

                if (auto fit = set.lower_bound(mid - value); fit != set.end())
                {
                    ++cnt;

                    if (fit == it)
                    {
                        it = set.erase(fit);
                    }
                    else
                    {
                        set.erase(fit);
                    }
                }
                else
                {
                    max = std::max(max, value);
                }
            }

            return max;
        };

        dfs(dfs, root, 0);

        return cnt >= m;
    };

    int l = 1, r = 1e9 + 1, mid;

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

    std::cout << l << '\n';

    return 0;
}