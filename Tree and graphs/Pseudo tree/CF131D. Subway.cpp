/**
 * Codeforces Beta Round 95 (Div. 2)
 * 
 * => D. Subway ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/131/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/131/submission/345435697 By huanhuanonly
 * 
 * @b Dfs on @b Pseudo-tree
 * 
 * ----October 24, 2025 [11h:21m:17s]----
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

    std::vector<std::vector<int>> e(n + 1);

    for (int i = 0; i < n; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    std::vector<bool> vis(n + 1);
    std::stack<int> st;

    auto find_cycle = [&](const auto& self, int u, int fa) -> bool
    {
        if (vis[u])
        {
            for (; not st.empty() and st.top() != u; st.pop());
            for (st.pop(); not st.empty(); vis[st.top()] = false, st.pop());

            return true;
        }

        st.push(u);
        vis[u] = true;

        for (int i : e[u] | std::views::filter([fa](int i) -> bool { return i != fa; }))
        {
            if (self(self, i, u))
            {
                return true;
            }
        }

        st.pop();
        vis[u] = false;

        return false;
    };

    find_cycle(find_cycle, 1, 0);

    std::vector<int> dis(n + 1);

    auto dfs = [&](const auto& self, int u, int fa) -> void
    {
        for (int i : e[u] | std::views::filter([&](int i) -> bool { return i != fa and not vis[i]; }))
        {
            dis[i] = dis[u] + 1;
            self(self, i, u);
        }
    };

    for (int i = 1; i <= n; ++i)
    {
        if (vis[i])
        {
            dfs(dfs, i, 0);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        std::cout << dis[i] << ' ';
    }

    return 0;
}