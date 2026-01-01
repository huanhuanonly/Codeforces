/**
 * Manthan, Codefest 18 (rated, Div. 1 + Div. 2)
 * 
 * => D. Valid BFS? ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/1037/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/1037/submission/346048382 By huanhuanonly
 * 
 * @b Bfs-order
 * 
 * ----October 28, 2025 [00h:11m:21s]----
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

    int n;
    std::cin >> n;

    std::vector<std::set<int>> e(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        e[u].insert(v);
        e[v].insert(u);
    }

    auto dfs = [&](const auto& self, int u) -> void
    {
        for (int i : e[u])
        {
            e[i].erase(u);
            self(self, i);
        }
    };

    dfs(dfs, 1);

    std::vector<int> q(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> q[i];
    }

    bool yes = q[0] == 1;
    int pos = 0;

    std::queue<std::set<int>> que;
    que.push({1});

    while (not que.empty())
    {
        auto set = std::move(que.front());
        que.pop();

        while (not set.empty())
        {
            if (auto it = set.find(q[pos++]); it == set.end())
            {
                yes = false;
                break;
            }
            else
            {
                que.push(e[*it]);
                set.erase(it);
            }
        }
    }

    if (yes)
    {
        std::cout << "Yes";
    }
    else
    {
        std::cout << "No";
    }

    return 0;
}