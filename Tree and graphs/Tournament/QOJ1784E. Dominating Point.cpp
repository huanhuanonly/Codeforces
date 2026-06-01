/**
 * The 2023 ICPC Asia Xi'an Regional Contest
 *
 * => E. Dominating Point
 *
 * -> https://qoj.ac/contest/1784/problem/9246/statement/en
 *
 * Submissions ~> https://qoj.ac/submission/2372258 By huanhuanonly
 *
 * @b Tournament
 * @b Constructive
 *
 * ----May 15, 2026 [08h:47m:47s]----
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

    int n;
    std::cin >> n;

    std::vector<std::string> e(n);

    std::vector<int> outdeg(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> e[i];
        outdeg[i] = std::ranges::count(e[i], '1');
    }

    int a = std::ranges::max_element(outdeg) - outdeg.begin(), b = -1, c = -1;

    for (int i = 0; i < n; ++i)
    {
        if (e[i][a] == '1')
        {
            if (~b)
            {
                if (outdeg[i] > outdeg[b])
                {
                    b = i;
                }
            }
            else
            {
                b = i;
            }
        }
    }

    if (~b)
    {
        for (int i = 0; i < n; ++i)
        {
            if (i != a and e[i][b] == '1')
            {
                if (~c)
                {
                    if (outdeg[i] > outdeg[c])
                    {
                        c = i;
                    }
                }
                else
                {
                    c = i;
                }
            }
        }
    }

    if (~c)
    {
        std::cout << 1 + a << ' ' << 1 + b << ' ' << 1 + c << '\n';
    }
    else
    {
        std::cout << "NOT FOUND\n";
    }

    return 0;
}