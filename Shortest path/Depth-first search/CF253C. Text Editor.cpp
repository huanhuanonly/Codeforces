/**
 * Codeforces Round 154 (Div. 2)
 * 
 * => C. Text Editor ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/253/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/253/submission/347506258 By huanhuanonly
 * 
 * @b Depth-first-search
 * 
 * ----November 05, 2025 [14h:45m:21s]----
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
#else
    ::freopen("input.txt", "r", stdin);
    ::freopen("output.txt", "w", stdout);
#endif

    int n;
    std::cin >> n;

    std::vector<int> v(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> v[i];
        ++v[i];
    }

    int sx, sy, tx, ty;
    std::cin >>sx >> sy >> tx >> ty;

    std::map<std::pair<int, int>, int> mp;

    auto dfs = [&](const auto& self, int x, int y, int d) -> void
    {
        if (auto it = mp.find({x, y}); it != mp.end() and d >= it->second)
        {
            return;
        }

        mp[{x, y}] = d;

        if (x - 1 >= 1)
        {
            self(self, x - 1, std::min(y, v[x - 1]), d + 1);
        }

        if (x + 1 <= n)
        {
            self(self, x + 1, std::min(y, v[x + 1]), d + 1);
        }
    };

    dfs(dfs, sx, sy, 0);

    int ans = std::numeric_limits<int>::max();

    for (const auto& [key, value] : mp)
    {
        if (key.first == tx)
        {
            ans = std::min(ans, std::abs(key.second - ty) + value);
        }
    }

    std::cout << ans;

    return 0;
}