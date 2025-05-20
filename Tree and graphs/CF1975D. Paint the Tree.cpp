/**
 * Codeforces Round 947 (Div. 1 + Div. 2)
 * 
 * => D. Paint the Tree ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/1975/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/1975/submission/318811638 By huanhuanonly
 * 
 * @b Dfs to find @a the-meeting-point between two points
 * 
 * ----May 08, 2025 [16h:36m:30s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        int a, b;
        std::cin >> a >> b;

        std::vector<std::vector<int>> e(n + 1);

        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            std::cin >> u >> v;

            e[u].push_back(v);
            e[v].push_back(u);
        }

        std::vector<int> path;
        path.reserve(n);

        auto find_meeting_point = [&](const auto& self, int u, int fa) -> bool
        {
            if (u == b)
            {
                return true;
            }

            for (int i : e[u] | std::views::filter([&](int i) -> bool { return i != fa; }))
            {
                path.push_back(i);
                
                if (self(self, i, u))
                {
                    return true;
                }

                path.pop_back();
            }

            return false;
        };

        auto find_deepest_depth = [&](const auto& self, int u, int fa, int depth = 0) -> int
        {
            int max = depth;

            for (int i : e[u] | std::views::filter([&](int i) -> bool { return i != fa; }))
            {
                max = std::max(max, self(self, i, u, depth + 1));
            }

            return max;
        };

        path.push_back(a);
        find_meeting_point(find_meeting_point, a, 0);
        int max = find_deepest_depth(find_deepest_depth, path[(path.size() - 1) / 2], 0);

        std::cout << (n - 1) * 2 + path.size() / 2 - max << '\n';
    }

    return 0;
}