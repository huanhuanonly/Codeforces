/**
 * Educational Codeforces Round 169 (Rated for Div. 2)
 * 
 * => D. Colored Portals ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/2004/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2004/submission/319230062 By huanhuanonly
 * 
 * @b Jumping-chain
 * 
 * ----May 11, 2025 [23h:02m:19s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n, q;
        std::cin >> n >> q;

        std::vector<std::array<int, 4>> prev(n + 2);
        std::vector<std::array<int, 4>> next(n + 2);

        std::vector<std::string> s(n + 1);

        for (std::string& i : s | std::views::drop(1))
        {
            std::cin >> i;
        }

        auto map = [](char c) -> int
        {
            switch (c)
            {
            case 'B': return 0;
            case 'R': return 1;
            case 'G': return 2;
            default:  return 3;
            }
        };

        constexpr int inf = std::numeric_limits<int>::max() / 2;

        std::array<std::array<int, 4>, 4> arr;
        arr.fill({-inf, -inf, -inf, -inf});
        
        for (int i = 1; i <= n; ++i)
        {
            arr[map(s[i][0])][map(s[i][1])] = i;
            arr[map(s[i][1])][map(s[i][0])] = i;

            for (int j = 0; j < 4; ++j)
            {
                prev[i][j] = std::max(arr[map(s[i][0])][j], arr[map(s[i][1])][j]);
            }
        }
        
        arr.fill({inf, inf, inf, inf});
        for (int i = n; i >= 1; --i)
        {
            arr[map(s[i][0])][map(s[i][1])] = i;
            arr[map(s[i][1])][map(s[i][0])] = i;

            for (int j = 0; j < 4; ++j)
            {
                next[i][j] = std::min(arr[map(s[i][0])][j], arr[map(s[i][1])][j]);
            }
        }

        while (q--)
        {
            int x, y;
            std::cin >> x >> y;

            if (s[x][0] == s[y][0] or s[x][0] == s[y][1] or s[x][1] == s[y][0] or s[x][1] == s[y][1])
            {
                std::cout << std::abs(y - x) << '\n';
                continue;
            }

            int ans = std::numeric_limits<int>::max();

            if (auto p = prev[x][map(s[y][0])]; std::abs(p) != inf)
            {
                ans = std::min(ans, std::abs(x - p) + std::abs(p - y));
            }

            if (auto p = next[x][map(s[y][0])]; std::abs(p) != inf)
            {
                ans = std::min(ans, std::abs(x - p) + std::abs(p - y));
            }

            if (auto p = prev[x][map(s[y][1])]; std::abs(p) != inf)
            {
                ans = std::min(ans, std::abs(x - p) + std::abs(p - y));
            }

            if (auto p = next[x][map(s[y][1])]; std::abs(p) != inf)
            {
                ans = std::min(ans, std::abs(x - p) + std::abs(p - y));
            }

            if (ans != std::numeric_limits<int>::max())
                std::cout << ans << '\n';
            else
                std::cout << -1 << '\n';
        }
    }

    return 0;
}