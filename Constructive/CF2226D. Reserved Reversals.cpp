/**
 * Codeforces Round 1095 (Div. 2)
 *
 * => D. Reserved Reversals ( @c 1900 )
 *
 * -> https://codeforces.com/contest/2226/problem/D
 *
 * Submissions ~> https://codeforces.com/contest/2226/submission/372916225 By huanhuanonly
 *
 * @b Constructive
 *
 * ----April 29, 2026 [14h:47m:26s]----
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

        std::vector<int> odd, even;

        for (int i = 0, v; i < n; ++i)
        {
            std::cin >> v;

            if (v & 1)
            {
                odd.push_back(v);
            }
            else
            {
                even.push_back(v);
            }
        }

        if (odd.empty() or even.empty())
        {
            if (std::ranges::is_sorted(odd) and std::ranges::is_sorted(even))
            {
                std::cout << "YES\n";
            }
            else
            {
                std::cout << "NO\n";
            }

            continue;
        }

        bool yes = true;

        auto [omin, omax] = std::ranges::minmax(odd);
        auto [emin, emax] = std::ranges::minmax(even);

        for (int mx = 0; const auto& i : odd)
        {
            if (mx > i)
            {
                if (not (emin < i or mx < emax))
                {
                    yes = false;
                    break;
                }
            }
            else
            {
                mx = i;
            }
        }

        for (int mx = 0; const auto& i : even)
        {
            if (mx > i)
            {
                if (not (omin < i or mx < omax))
                {
                    yes = false;
                    break;
                }
            }
            else
            {
                mx = i;
            }
        }

        if (yes)
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }

    return 0;
}