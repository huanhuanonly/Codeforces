/**
 * Codeforces Round 703 (Div. 2)
 * 
 * => D. Max Median ( @c 2100 )
 * 
 * -> https://codeforces.com/contest/1486/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/1486/submission/332086357 By huanhuanonly
 * 
 * @b Binary-search and @b Prefix-sum
 * 
 * ----August 02, 2025 [19h:38m:44s]----
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

    int n, k;
    std::cin >> n >> k;

    std::vector<int> v(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> v[i];
    }

    auto check = [&](int mid) -> bool
    {
        auto $ = [&](int x) -> int
        {
            return x < mid ? -1 : 1;
        };

        std::vector<int> presum(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            presum[i] = presum[i - 1] + $(v[i]);
        }

        std::vector<std::pair<int, int>> premin(n + 1), sufmax(n + 2, {std::numeric_limits<int>::min(), 0});

        for (int i = 1; i <= n; ++i)
        {
            premin[i] = std::min(premin[i - 1], {presum[i], i});
        }

        for (int i = n; i >= 1; --i)
        {
            sufmax[i] = std::max(sufmax[i + 1], {presum[i], i});
        }

        for (int i = k; i <= n; ++i)
        {
            if (sufmax[i].first - premin[i - k].first > 0)
            {
                return true;
            }
        }

        return false;
    };

    int l = 0, r = n + 1, mid;

    while (r - l > 1)
    {
        mid = l + r >> 1;

        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    std::cout << l << '\n';

    return 0;
}