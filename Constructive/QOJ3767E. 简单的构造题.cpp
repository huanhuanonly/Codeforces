/**
 * 2026 年山东省大学生程序设计竞赛
 *
 * => E. 简单的构造题
 *
 * -> https://qoj.ac/contest/3767/problem/18311
 *
 * Submissions ~> https://qoj.ac/submission/2445886 By huanhuanonly
 *
 * @b Constructive
 *
 * ----May 26, 2026 [19h:08m:37s]----
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
        int n, m;
        std::cin >> n >> m;

        auto test = [](int n, int m) -> std::optional<std::vector<std::vector<int>>>
        {
            std::vector v(n, std::vector(m, 0));

            auto fill = [&, id = 0](int num) mutable -> void
            {
                int i = num < 0 ? -num : 0, j = num > 0 ? num : 0;

                for (; i < n and j < m; ++i, ++j)
                {
                    v[i][j] = id++;
                }
            };

            for (int i = -n + 1; i < m; i += 2)
            {
                fill(i);
            }

            for (int i = -n + 2; i < m; i += 2)
            {
                fill(i);
            }

            bool yes = true;

            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (i and v[i - 1][j] == (v[i][j] + 1) % (n * m))
                    {
                        yes = false;
                        break;
                    }

                    if (j and v[i][j - 1] == (v[i][j] + 1) % (n * m))
                    {
                        yes = false;
                        break;
                    }

                    if (i + 1 < n and v[i + 1][j] == (v[i][j] + 1) % (n * m))
                    {
                        yes = false;
                        break;
                    }

                    if (j + 1 < m and v[i][j + 1] == (v[i][j] + 1) % (n * m))
                    {
                        yes = false;
                        break;
                    }
                }
            }

            if (yes)
            {
                return v;
            }
            else
            {
                return std::nullopt;
            }
        };


        if (const auto v = test(n, m))
        {
            std::cout << "Yes\n";

            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    std::cout << v.value()[i][j] << ' ';
                }

                std::cout.put('\n');
            }
        }
        else if (const auto v = test(m, n))
        {
            std::cout << "Yes\n";

            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    std::cout << v.value()[j][i] << ' ';
                }

                std::cout.put('\n');
            }
        }
        else
        {
            std::cout << "No\n";
        }
    }

    return 0;
}