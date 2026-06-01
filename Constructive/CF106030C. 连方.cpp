/**
 * 2024 China Collegiate Programming Contest (CCPC) Chongqing Onsite
 *
 * => C. 连方
 *
 * -> https://codeforces.com/gym/106030/problem/C
 *
 * Submissions ~> https://codeforces.com/gym/106030/submission/374415477 By huanhuanonly
 *
 * @b Constructive
 *
 * ----May 14, 2026 [00h:21m:04s]----
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

        std::vector<std::string> v(7, std::string(n, '.'));
        std::cin >> v.front() >> v.back();

        const int cf = std::ranges::count(v.front(), '.');
        const int cb = std::ranges::count(v.back(), '.');

        if (cf == 0 and cb == 0)
        {
            std::cout << "Yes\n";

            for (int i = 0; i < 7; ++i)
            {
                std::cout << std::string(n, '#') << '\n';
            }
        }
        else if (cf == 0 or cb == 0)
        {
            std::cout << "No\n";
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                if (v.front()[i] == '.')
                {
                    v[1][i] = '#';
                }
            }

            for (int i = 0; i < n; ++i)
            {
                if (v.back()[i] == '.')
                {
                    v[5][i] = '#';
                }
            }

            int pos1, pos2;

            for (int i = 0; i < n; ++i)
            {
                if (v[1][i] == '.' and ((i and v[1][i - 1] == '#') or i + 1 < n and v[1][i + 1] == '#'))
                {
                    pos1 = i;
                    v[2][i] = '#';
                    break;
                }
            }

            for (int i = 0; i < n; ++i)
            {
                if (v[5][i] == '.' and ((i and v[5][i - 1] == '#') or i + 1 < n and v[5][i + 1] == '#'))
                {
                    pos2 = i;
                    v[4][i] = '#';
                    break;
                }
            }

            if (std::abs(pos1 - pos2) <= 1)
            {
                v[3] = v[2];
            }
            else for (int i = 0; i < n; ++i)
            {
                if (v[2][i] == '.' and v[4][i] == '.')
                {
                    v[3][i] = '#';
                }
            }

            std::cout << "Yes\n";

            for (int i = 0; i < 7; ++i)
            {
                std::cout << v[i] << '\n';
            }
        }
    }

    return 0;
}