/**
 * Manthan, Codefest 18 (rated, Div. 1 + Div. 2)
 * 
 * => E. Trips ( @c 2200 )
 * 
 * -> https://codeforces.com/contest/1037/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/1037/submission/346445394 By huanhuanonly
 * 
 * @b Topological-sorting on @a Graphs
 * 
 * ----October 29, 2025 [18h:24m:48s]----
*/

/// @brief This is an @c interesting problem!

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

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::pair<int, int>> log(m);

    std::vector<std::set<int>> e(n + 1);

    for (int i = 0; i < m; ++i)
    {
        std::cin >> log[i].first >> log[i].second;

        e[log[i].first].insert(log[i].second);
        e[log[i].second].insert(log[i].first);
    }

    std::queue<int> que;

    auto bfs = [&, remain = n]() mutable -> int
    {
        while (not que.empty())
        {
            const int u = que.front();
            que.pop();

            --remain;

            for (const int i : e[u])
            {
                e[i].erase(u);

                if (e[i].size() == k - 1)
                {
                    que.push(i);
                }
            }

            e[u].clear();
        }

        return remain;
    };

    for (int i = 1; i <= n; ++i)
    {
        if (e[i].size() < k)
        {
            que.push(i);
        }
    }

    std::vector<int> ans;
    ans.reserve(m);
    
    for (const auto& [u, v] : log | std::views::reverse)
    {
        ans.push_back(bfs());

        if (e[u].contains(v))
        {
            e[u].erase(v);
            e[v].erase(u);

            if (e[u].size() < k)
            {
                que.push(u);
            }

            if (e[v].size() < k)
            {
                que.push(v);
            }
        }
    }

    for (const int i : ans | std::views::reverse)
    {
        std::cout << i << '\n';
    }

    return 0;
}