/**
 * Educational Codeforces Round 185 (Rated for Div. 2)
 * 
 * => C. Quotient and Remainder ( @c 1300 )
 * 
 * -> https://codeforces.com/contest/2170/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/2170/submission/351027444 By huanhuanonly
 * 
 * @b Binary-search
 * 
 * ----November 28, 2025 [23h:19m:23s]----
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
        int64 n, k;
        std::cin >> n >> k;

        std::vector<int64> q(n);
        std::multiset<int64, std::ranges::greater> st;

        for (int64 i = 0; i < n; ++i)
        {
            std::cin >> q[i];
        }

        std::ranges::sort(q);

        for (int64 i = 0, v; i < n; ++i)
        {
            std::cin >> v;
            st.insert(v);
        }

        int64 cnt = 0;

        for (int64 i = 0; i < n; ++i)
        {
            auto check = [&](int64 mid) -> bool
            {
                const int64 y = mid + 1;
                const int64 x = q[i] * y + mid;

                return x <= k and y <= k;
            };

            int64 l = *st.rbegin(), r = *st.begin() + 1, mid;

            while (r - l > 1)
            {
                mid = (l + r) / 2;

                if (check(mid))
                {
                    l = mid;
                }
                else
                {
                    r = mid;
                }
            }

            if (check(l))
            {
                st.extract(st.lower_bound(l));
                ++cnt;
            }
            else
            {
                break;
            }
        }

        std::cout << cnt << '\n';
    }

    return 0;
}