/**
 * Codeforces Round 1066 (Div. 1 + Div. 2)
 * 
 * => C. Meximum Array 2 ( @c 1400 )
 * 
 * -> https://codeforces.com/contest/2157/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/2157/submission/352875918 By huanhuanonly
 * 
 * @b Constructive
 * 
 * ----December 11, 2025 [00h:03m:15s]----
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
        int n, k, q;
        std::cin >> n >> k >> q;

        std::vector<int> v(n + 1, k);
        std::vector<int> limit(n + 2);

        auto iota = std::views::iota(0, k);

        auto fill = [&](int l, int r) -> void
        {
            std::set<int> st(iota.begin(), iota.end());

            for (int i = l; i <= r; ++i)
            {
                st.erase(v[i]);
            }

            for (int i = l; i <= r and not st.empty(); ++i)
            {
                if (v[i] == k and not limit[i])
                {
                    v[i] = st.extract(st.begin()).value();
                }
            }
        };

        std::vector<std::tuple<int, int, int>> qs(q);

        for (auto& [opt, l, r] : qs)
        {
            std::cin >> opt >> l >> r;

            if (opt == 1)
            {
                ++limit[l];
                --limit[r + 1];
            }
        }
        
        std::ranges::sort(qs);

        std::partial_sum(limit.begin(), limit.end(), limit.begin());

        for (const auto& [opt, l, r] : qs)
        {
            if (opt == 2)
            {
                fill(l, r);
            }
        }
        
        for (const auto& [opt, l, r] : qs)
        {
            if (opt == 2)
            {
                for (int i = l; i <= r; ++i)
                {
                    if (v[i] == k)
                    {
                        ++v[i];
                    }
                }
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            std::cout << v[i] << " \n"[i == n];
        }
    }

    return 0;
}