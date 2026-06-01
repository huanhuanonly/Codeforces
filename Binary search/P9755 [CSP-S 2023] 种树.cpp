/**
 * CSP-S 2023 自测【官方数据】
 *
 * => P9755 [CSP-S 2023] 种树 ( @c 提高+/省选− )
 *
 * -> https://www.luogu.com.cn/problem/P9755
 *
 * Submissions ~> https://www.luogu.com.cn/record/279684991 By huanhuanonly
 *
 * @b Binary-search
 * @b Dfs on @a Trees
 * @b Greedy
 *
 * ----May 28, 2026 [19h:24m:10s]----
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

constexpr int128 div_floor(int128 lhs, int128 rhs)
{
    return lhs / rhs - (lhs % rhs and (lhs ^ rhs) < 0);
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int n;
    std::cin >> n;

    struct item
    {
        int64 a, b, c;
    };

    std::vector<item> info(n);

    for (auto& [a, b, c] : info)
    {
        std::cin >> a >> b >> c;
    }

    std::vector<int> fa(n);

    std::vector<std::vector<int>> e(n);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        --u, --v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    auto build = [&](const auto& self, int u) -> void
    {
        for (int v : e[u])
        {
            if (v != fa[u])
            {
                fa[v] = u;
                self(self, v);
            }
        }
    };

    build(build, 0);

    auto check = [&](int128 lastday) -> bool
    {
        std::vector<std::pair<int, int128>> need(n);

        for (int i = 0; i < n; ++i)
        {
            need[i].first = i;

            const int128 midday = info[i].c >= 0 ? lastday : std::clamp(div_floor(1 - info[i].b, info[i].c), int128{}, lastday);

            auto check = [&](int128 startday) -> bool
            {
                if (startday > midday)
                {
                    return lastday - startday + 1 >= int128(info[i].a);
                }
                else
                {
                    const int128 cnt = midday - startday + 1;

                    int128 sum = cnt * info[i].b + (startday + midday) * cnt / 2 * info[i].c;

                    return sum + (lastday - midday) >= int128(info[i].a);
                }
            };

            int128 l = 0, r = lastday, mid;

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

            if (l == 0)
            {
                return false;
            }

            need[i].second = l;
        }

        std::ranges::sort(need, {}, &std::pair<int, int128>::second);

        std::vector<int64> startdays(n);
        startdays[0] = 1;

        int64 curday = 1;

        std::vector<int> que;

        for (const auto& [u, startday] : need)
        {
            for (int i = u; not startdays[i]; que.push_back(i), i = fa[i]);

            for (int i : que | std::views::reverse)
            {
                startdays[i] = ++curday;
            }

            que.clear();
        }

        std::ranges::sort(need, {}, &std::pair<int, int128>::first);

        for (int i = 0; i < n; ++i)
        {
            if (startdays[i] > need[i].second)
            {
                return false;
            }
        }

        return true;
    };

    int64 l = 0, r = 1e9, mid;

    while (r - l > 1)
    {
        mid = l + r >> 1;

        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }

    std::cout << r << '\n';

    return 0;
}