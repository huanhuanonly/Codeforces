/**
 * 第十三届重庆市大学生程序设计竞赛
 * 
 * =>  J. RGB 树
 * 
 * -> https://codeforces.com/gym/105887/problem/J
 * 
 * Submissions ~> https://codeforces.com/gym/105887/submission/319871915 By huanhuanonly
 * 
 * @b Dfs
 * 
 * ----May 16, 2025 [17h:32m:26s]----
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

    std::string s;
    std::cin >> s;

    std::string_view c(s.data() - 1, s.size() + 1);
    std::map<char, int> mp{{'R', 0}, {'G', 1}, {'B', 2}, {'W', 3}};

    std::vector<std::vector<int>> e(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    std::array<std::vector<int>, 4> set;

    int ans = 0;
    int start;

    auto dfs = [&](const auto& self, int u, int fa) -> void
    {
        for (int i = 0; i < 3; ++i)
        {
            if (i == mp[c[start]] or i == mp[c[u]])
            {
                continue;
            }

            for (int j = 0; j < set[i].size(); ++j)
            {
                const_cast<char&>(c[set[i][j]]) = 'W';
            }

            ans += set[i].size();
            set[i].clear();
        }

        set[mp[c[u]]].push_back(u);

        for (int i : e[u] | std::views::filter([&](int i) -> bool { return i != fa; }))
        {
            self(self, i, u);
        }

        if (not set[mp[c[u]]].empty() and set[mp[c[u]]].back() == u)
        {
            set[mp[c[u]]].pop_back();
        }
    };

    std::vector<bool> vis(3);
    for (int i = 1; i <= n; ++i)
    {
        if (c[i] != 'W' and not vis[mp[c[i]]])
        {
            start = i;
            vis[mp[c[i]]] = true;
            
            for (int j = 0; j < set.size(); ++j)
            {
                set[j].clear();
            }

            dfs(dfs, i, 0);
        }
    }

    std::cout << ans;

    return 0;
}