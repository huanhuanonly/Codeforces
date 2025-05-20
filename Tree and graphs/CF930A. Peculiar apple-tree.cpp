/**
 * Codeforces Round 468 (Div. 1, based on Technocup 2018 Final Round)
 * 
 * => A. Peculiar apple-tree ( @c 1500 )
 * 
 * -> https://codeforces.com/problemset/problem/930/A
 * 
 * Submissions ~> https://codeforces.com/contest/930/submission/319360900 By huanhuanonly
 * 
 * @b Dfs
 * 
 * ----May 12, 2025 [18h:28m:41s]----
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

#ifdef __localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> e(n + 1);

    for (int i = 2; i <= n; ++i)
    {
        int u;
        std::cin >> u;

        e[u].push_back(i);
    }

    std::map<int, int> mp;

    auto dfs = [&](const auto& self, int u, int d) -> void
    {
        ++mp[d];

        for (int i : e[u])
        {
            self(self, i, d + 1);
        }
    };

    dfs(dfs, 1, 0);

    int ans = 0;

    for (int count : mp | std::views::values)
    {
        ans += count & 1;
    }

    std::cout << ans;

    return 0;
}