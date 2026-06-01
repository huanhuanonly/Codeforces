/**
 * 2025 ICPC Nanchang Invitational and Jiangxi Provincial Collegiate Programming Contest
 *
 * => D. Virtuous Pope
 *
 * -> https://codeforces.com/gym/105911/problem/D
 *
 * Submissions ~> https://codeforces.com/gym/105911/submission/372785982 By huanhuanonly
 *
 * @b Difference-array and @b Geometry
 *
 * ----April 28, 2026 [16h:55m:22s]----
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

#if defined(__SIZEOF_INT128__)
using int128 = __int128;
using uint128 = unsigned __int128;
#endif

using real32 = float;
using real64 = double;

#if defined(__SIZEOF_FLOAT80__)
using real80 = __float80;
#endif

#if defined(__SIZEOF_FLOAT128__)
using real128 = __float128;
#endif

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int n, a, b, c;
    std::cin >> n >> a >> b >> c;

    std::map<int, int> vx, vy, vz;

    for (int i = 0; i < n; ++i)
    {
        int x1, y1, z1, x2, y2, z2;
        std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        std::tie(x1, x2) = std::minmax({x1, x2});
        std::tie(y1, y2) = std::minmax({y1, y2});
        std::tie(z1, z2) = std::minmax({z1, z2});

        ++vx[x1], --vx[x2 + 1];
        ++vy[y1], --vy[y2 + 1];
        ++vz[z1], --vz[z2 + 1];
    }

    int ans = 0;

    {
        auto v = vx | std::views::values;
        std::partial_sum(v.begin(), v.end(), v.begin());
        ans = std::max(ans, *std::ranges::max_element(v));
    }

    {
        auto v = vy | std::views::values;
        std::partial_sum(v.begin(), v.end(), v.begin());
        ans = std::max(ans, *std::ranges::max_element(v));
    }

    {
        auto v = vz | std::views::values;
        std::partial_sum(v.begin(), v.end(), v.begin());
        ans = std::max(ans, *std::ranges::max_element(v));
    }

    std::cout << ans << '\n';

    return 0;
}