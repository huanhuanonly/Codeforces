/**
 * Codeforces Round 149 (Div. 2)
 * 
 * => D. Dispute ( @c 2100 )
 * 
 * -> https://codeforces.com/contest/242/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/242/submission/351935097 By huanhuanonly
 * 
 * @b Topological-sorting on @a Graphs
 * 
 * ----December 05, 2025 [09h:30m:04s]----
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

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> e(n + 1);

    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    std::vector<int> limit(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> limit[i];
    }

    std::vector<int> cnt(n + 1);
    std::vector<bool> selected(n + 1);

    std::queue<int> que;

    auto bfs = [&]() -> void
    {
        while (not que.empty())
        {
            const int u = que.front();
            que.pop();

            for (const int& i : e[u])
            {
                if (limit[i] == ++cnt[i])
                {
                    if (not selected[i])
                    {
                        ++cnt[i];
                        que.push(i);
                        selected[i] = true;
                    }
                }
            }
        }
    };

    for (int i = 1; i <= n; ++i)
    {
        if (limit[i] == cnt[i])
        {
            selected[i] = true;
            ++cnt[i];

            que.push(i);
            bfs();
        }
    }

    bool yes = true;

    for (int i = 1; i <= n; ++i)
    {
        yes = yes and limit[i] != cnt[i];
    }

    if (yes)
    {
        std::cout << std::ranges::count(selected, true) << '\n';

        for (int i = 1; i <= n; ++i)
        {
            if (selected[i])
            {
                std::cout << i << ' ';
            }
        }
    }
    else
    {
        std::cout << -1;
    }

    return 0;
}