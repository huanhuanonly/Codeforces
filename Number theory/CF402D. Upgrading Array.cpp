/**
 * Codeforces Round 236 (Div. 2)
 * 
 * => D. Upgrading Array ( @c 1800 )
 * 
 * -> https://codeforces.com/contest/402/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/402/submission/325136303 By huanhuanonly
 * 
 * @b Number-theory ( @a prime-number )
 * 
 * ----June 19, 2025 [19h:07m:50s]----
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

template<std::integral _Tp>
void prime_factorization(_Tp __n, std::map<_Tp, int>& __result)
{
    for (int i = 2; i <= __n / i; ++i)
    {
        while (__n % i == 0)
        {
            ++__result[i];
            __n /= i;
        }
    }

    if (__n != 1)
    {
        ++__result[__n];
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m);
    std::vector<std::map<int, int>> v(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        prime_factorization(a[i], v[i]);
    }

    for (int i = 0; i < m; ++i)
    {
        std::cin >> b[i];
    }

    auto eval = [&](std::map<int, int>& mp) -> int
    {
        int sum = 0;

        for (const auto& [key, value] : mp)
        {
            if (std::ranges::binary_search(b, key))
            {
                sum -= value;
            }
            else
            {
                sum += value;
            }
        }

        return sum;
    };

    while (true)
    {
        auto min = std::make_pair(eval(v[0]), v[0]);
        int pos = 0;

        auto cur = min;

        for (int i = 1; i < n; ++i)
        {
            for (auto it = cur.second.begin(); it != cur.second.end(); )
            {
                if (auto fit = v[i].find(it->first); fit != v[i].end())
                {
                    it->second = std::min(it->second, fit->second);
                    ++it;
                }
                else
                {
                    it = cur.second.erase(it);
                }
            }

            if (cur.second.empty())
            {
                break;
            }
            else if (cur.first = eval(cur.second) * (i + 1); cur.first < 0)
            {
                min = cur;
                pos = i;
            }
        }

        if (min.first >= 0)
        {
            break;
        }
        else for (int i = 0; i <= pos; ++i)
        {
            for (auto it = v[i].begin(); it != v[i].end(); )
            {
                if (auto fit = min.second.find(it->first); fit != min.second.end())
                {
                    if (it->second -= fit->second)
                    {
                        ++it;
                    }
                    else
                    {
                        it = v[i].erase(it);
                    }
                }
                else
                {
                    ++it;
                }
            }
        }
    }

    int sum = 0;

    for (int i = 0; i < n; ++i)
    {
        sum += eval(v[i]);
    }

    std::cout << sum;

    return 0;
}