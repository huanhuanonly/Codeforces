/**
 * Codeforces Round 1060 (Div. 2)
 * 
 * => C1. No Cost Too Great (Easy Version) ( @c 1400 )
 * 
 * -> https://codeforces.com/contest/2154/problem/C1
 * 
 * Submissions ~> https://codeforces.com/contest/2154/submission/344701240 By huanhuanonly
 * 
 * @b Classification-discussion and @b Number-theory ( @a greatest-common-divisor )
 * 
 * ----October 20, 2025 [23h:31m:32s]----
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
        int n;
        std::cin >> n;

        std::vector<int> v(n), w(n);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> v[i];
        }

        for (int i = 0; i < n; ++i)
        {
            std::cin >> w[i];
        }

        std::map<int, int> cnt;

        bool found = false;

        for (int i = 0; i < n and not found; ++i)
        {
            if (v[i] == 1)
            {
                continue;
            }

            for (int t = 2; t <= std::sqrt(v[i]); ++t)
            {
                if (v[i] % t == 0)
                {
                    if (++cnt[t] == 2)
                    {
                        found = true;
                        break;
                    }
                    else if (t != v[i] / t and ++cnt[v[i] / t] == 2)
                    {
                        found = true;
                        break;
                    }
                }
            }

            if (++cnt[v[i]] == 2)
            {
                found = true;
            }
        }

        if (found)
        {
            std::cout << 0 << '\n';
            continue;
        }

        for (int i = 0; i < n and not found; ++i)
        {
            ++v[i];

            for (int t = 2; t <= std::sqrt(v[i]); ++t)
            {
                if (v[i] % t == 0)
                {
                    if (cnt[t])
                    {
                        found = true;
                        break;
                    }
                    else if (t != v[i] / t and cnt[v[i] / t])
                    {
                        found = true;
                        break;
                    }
                }
            }

            if (cnt[v[i]])
            {
                found = true;
            }
        }

        if (found)
        {
            std::cout << 1 << '\n';
        }
        else
        {
            std::cout << 2 << '\n';
        }
    }

    return 0;
}