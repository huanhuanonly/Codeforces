/**
 * Codeforces Round 1031 (Div. 2)
 * 
 * => D. Cheater ( @c 2200 )
 * 
 * -> https://codeforces.com/contest/2113/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2113/submission/324778944 By huanhuanonly
 * 
 * @b Binary-search
 * 
 * ----June 17, 2025 [21h:14m:42s]----
*/

/// @brief This is an @c interesting problem!

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

        std::vector<int> a(n), b(n);

        std::vector<std::pair<int, int>> minmax(n);

        std::map<int, int> pos;

        for (int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
            pos[a[i]] = i;

            if (i)
            {
                minmax[i].first = std::min(minmax[i - 1].first, a[i]);
            }
            else
            {
                minmax[i].first = a[i];
            }
        }

        for (int i = 0; i < n; ++i)
        {
            std::cin >> b[i];
        }

        for (int i = n - 1; i >= 0; --i)
        {
            if (i + 1 < n)
            {
                minmax[i].second = std::max(minmax[i + 1].second, a[i]);
            }
            else
            {
                minmax[i].second = a[i];
            }
        }

        std::vector<int> pa(n), pb(n), v(n + n);
        std::iota(pa.begin(), pa.end(), 0);  // [0, n - 1]
        std::iota(pb.begin(), pb.end(), n);  // [n, 2n - 1]

        auto check = [&](int mid) -> bool
        {
            static auto swap_if = [](int& i, int& j, auto cmp) -> void {
                cmp(i, j) ? std::swap(i, j) : void();
            };

            if (mid == std::clamp(mid, 0, n - 1))
            {
                swap_if(a[pos[minmax[mid - 1].first]], a[pos[minmax[mid].second]], std::less());
            }
            
            std::ranges::merge(pa, pb, v.begin(), [&](int i, int j) -> bool {
                return a[j] < b[i - n];
            });

            bool result =
                std::ranges::count_if(v | std::views::take(n), [&](int i) -> bool {
                    return i < n;
                }) >= mid;
            
            if (mid == std::clamp(mid, 0, n - 1))
            {
                swap_if(a[pos[minmax[mid - 1].first]], a[pos[minmax[mid].second]], std::greater());
            }

            return result;
        };

        int l = 0, r = n + 1, mid;

        while (r - l > 1)
        {
            mid = l + r >> 1;

            if (check(mid))
                l = mid;
            else
                r = mid;
        }

        std::cout << l << '\n';
    }
    
    return 0;
}