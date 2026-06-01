/**
 * Codeforces Round 1095 (Div. 2)
 *
 * => C. Mental Monumental (Easy Version) ( @c 1500 )
 *
 * -> https://codeforces.com/contest/2226/problem/C
 *
 * Submissions ~> https://codeforces.com/contest/2226/submission/372849285 By huanhuanonly
 *
 * @b Binary-search
 *
 * ----April 29, 2026 [01h:10m:53s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        std::multiset<int> set;

        for (int i = 0, v; i < n; ++i)
        {
            std::cin >> v;
            set.insert(v);
        }

        auto check = [&](int mid) -> bool
        {
            std::multiset<int> mset;

            int mex = 0;

            for (int i = 0; i < mid; ++i)
            {
                if (auto it = set.find(i); it != set.end())
                {
                    mset.insert(set.extract(it));
                }
            }

            for (; mset.contains(mex); ++mex);

            for (auto it = set.begin(); it != set.end() and mex < mid; ++it)
            {
                if ((*it / 2 + *it % 2) - 1 >= mex)
                {
                    ++mex;
                    for (; mset.contains(mex); ++mex);
                }
            }

            set.insert(mset.begin(), mset.end());

            return mex >= mid;
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
    }

    return 0;
}