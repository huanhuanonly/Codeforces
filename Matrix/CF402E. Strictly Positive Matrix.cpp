/**
 * Codeforces Round 236 (Div. 2)
 * 
 * => E. Strictly Positive Matrix ( @c 2200 )
 * 
 * -> https://codeforces.com/contest/402/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/402/submission/325570388 By huanhuanonly
 * 
 * @b Matrix and @b Tarjan
 * 
 * ----June 22, 2025 [20h:47m:06s]----
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

    int n;
    std::cin >> n;

    std::vector M(n, std::bitset<2000>());

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int v;
            std::cin >> v;

            M[i][j] = static_cast<bool>(v);
        }
    }

    std::vector<int> scc(n);
    std::iota(scc.begin(), scc.end(), 0);

    std::vector<int> dfn(n), low(n);

    auto dfs = [&, cnt = 0, vis = std::vector<bool>(n), stack = std::stack<int>()](auto& self, int u) mutable -> void
    {
        dfn[u] = low[u] = ++cnt;
        stack.push(u);

        for (auto i = M[u]._Find_first(); i != M[u].size(); i = M[u]._Find_next(i))
        {
            if (not vis[i])
            {
                vis[i] = true;
                self(self, i);
            }

            low[u] = std::min(low[u], low[i]);
        }

        if (dfn[u] == low[u])
        {
            while (stack.top() != u)
            {
                scc[stack.top()] = u;
                stack.pop();
            }

            stack.pop();
        }
    };

    dfs(dfs, 0);

    if (std::ranges::count(scc, scc.front()) == scc.size())
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }

    return 0;
}