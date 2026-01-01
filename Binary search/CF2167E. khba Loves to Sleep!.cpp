/**
 * Codeforces Round 1062 (Div. 4)
 * 
 * => E. khba Loves to Sleep! ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/2167/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2167/submission/346295605 By huanhuanonly
 * 
 * @b Binary-search
 * 
 * ----October 29, 2025 [00h:50m:43s]----
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
        int64 n, k, x;
        std::cin >> n >> k >> x;

        std::vector<int64> v(n + 2);
        v[n + 1] = x;

        for (int64 i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
        }

        std::ranges::sort(v);

        std::vector<int64> set;
        set.reserve(k);

        auto check = [&](int64 mid) -> bool
        {
            set.clear();

            if (mid == 0)
            {
                set.resize(k);
                std::iota(set.begin(), set.end(), 0);
                return true;
            }

            for (int64 i = 0; i <= n; ++i)
            {
                for (int64 j = v[i] + (i ? mid : 0); j + (i != n ? mid : 0) <= v[i + 1] and set.size() < k; ++j)
                {
                    set.push_back(j);
                }
            }

            return set.size() == k;
        };

        int64 l = 0, r = 1e10, mid;

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

        check(l);

        for (int64 i : set)
        {
            std::cout << i << ' ';
        }

        std::cout.put('\n');
    }

    return 0;
}