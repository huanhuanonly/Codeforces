/**
 * Codeforces Round 1099 (Div. 2)
 *
 * => D. Maximum Prefix Sums ( @c 1900 )
 *
 * -> https://codeforces.com/contest/2231/problem/D
 *
 * Submissions ~> https://codeforces.com/contest/2231/submission/376169923 By huanhuanonly
 *
 * @b Constructive
 *
 * ----May 26, 2026 [17h:55m:44s]----
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

        std::string s;
        std::cin >> s;

        std::vector<int64> a(n), c(n);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
        }

        for (int i = 0; i < n; ++i)
        {
            std::cin >> c[i];
        }

        if (not std::ranges::is_sorted(c))
        {
            std::cout << "No\n";
            continue;
        }

        constexpr int64 inf = std::numeric_limits<int64>::max() / 2;

        int64 sum = 0, last = -1;
        std::pair<int64, int64> limit;

        bool yes = true;

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '1')
            {
                sum += a[i];
            }
            else
            {
                last = i;
                limit = {-inf, c[i] - sum};
            }

            if (i == 0 or c[i] != c[i - 1])
            {
                if (c[i] != sum)
                {
                    if (~last and limit.first <= c[i] - sum and c[i] - sum <= limit.second)
                    {
                        a[last] += c[i] - sum;
                        sum += c[i] - sum;
                        last = -1;
                    }
                    else
                    {
                        yes = false;
                        break;
                    }
                }

                limit.first = 0;
            }
            else if (sum > c[i])
            {
                if (~last and limit.first <= c[i] - sum)
                {
                    a[last] += c[i] - sum;
                    sum += c[i] - sum;
                }
                else
                {
                    yes = false;
                    break;
                }
            }

            if (~last)
            {
                limit.second = std::min(limit.second, c[i] - sum);
            }
        }

        if (yes)
        {
            std::cout << "Yes\n";

            for (int i = 0; i < n; ++i)
            {
                std::cout << a[i] << " \n"[i + 1 == n];
            }
        }
        else
        {
            std::cout << "No\n";
        }
    }

    return 0;
}