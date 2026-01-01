/**
 * Educational Codeforces Round 185 (Rated for Div. 2)
 * 
 * => D. Almost Roman ( @c 2200 )
 * 
 * -> https://codeforces.com/contest/2170/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2170/submission/351437403 By huanhuanonly
 * 
 * @b Constructive ( @a Normalization ) and @b Classification-discussion
 * 
 * ----December 01, 2025 [16h:48m:49s]----
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
        int n, q;
        std::cin >> n >> q;

        std::string s;
        std::cin >> s;

        int cost = 0;
        const int cnt = std::ranges::count(s, '?');

        for (char& c : s)
        {
            if (c == 'X')
            {
                c = 'V';
                cost += 10;
            }
            else if (c == 'V')
            {
                cost += 5;
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'I' or s[i] == '?')
            {
                if (i + 1 < n and s[i + 1] == 'V')
                {
                    --cost;
                }
                else
                {
                    ++cost;
                }
            }
        }

        int III = 0, VII = 0, IIV = 0;

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '?')
            {
                if (i and s[i - 1] == 'I')
                {
                    if (i + 1 < n and s[i + 1] == 'V')
                    {
                        ++IIV;
                        s[i] = 'I';
                    }
                    else
                    {
                        ++III;
                        s[i] = 'V';
                    }
                }
                else
                {
                    s[i] = 'I';

                    if (i + 1 == n or s[i + 1] == 'I')
                    {
                        ++VII;
                    }
                }
            }
        }

        while (q--) [=]() mutable
        {
            int cx, cv, ci;
            std::cin >> cx >> cv >> ci;
            
            cost += std::max(cnt - (ci + cv), 0) * 5;
            cv = std::max(cnt - ci, 0);

            int min;

            min = std::min(cv, III);
            cost += min * 2;
            cv -= min;

            min = std::min(cv, VII);
            cost += min * 4;
            cv -= min;

            min = std::min(cv, IIV);
            cost += min * 4;
            cv -= min;

            cost += cv * 6;

            std::cout << cost << '\n';
        }();
    }

    return 0;
}