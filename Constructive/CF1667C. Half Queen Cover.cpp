/**
 * Codeforces Round 783 (Div. 1)
 * 
 * => C. Half Queen Cover ( @c 2400 )
 * 
 * -> https://codeforces.com/contest/1667/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/1667/submission/340035434 By huanhuanonly
 * 
 * @b Constructive
 * 
 * ----September 23, 2025 [21h:51m:21s]----
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

    std::vector<std::pair<int, int>> ans;

    const int k = (n * 2 + 1) / 3;
    const int s = std::max(1, (n - k) * 2 - 1);

    ans.reserve(k);

    for (int i = 1, j = 1; i <= s; ++i, ++(++j %= s))
    {
        ans.push_back({i, j});
    }

    for (int i = s + 1; i <= k; ++i)
    {
        ans.push_back({i, i});
    }

    std::cout << ans.size() << '\n';

    for (const auto& [i, j] : ans)
    {
        std::cout << i << ' ' << j << '\n';
    }

    return 0;
}