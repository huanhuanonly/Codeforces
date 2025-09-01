/**
 * Codeforces Round 1045 (Div. 2)
 * 
 * => B. Add 0 or K ( @c 1200 )
 * 
 * -> https://codeforces.com/contest/2134/problem/B
 * 
 * Submissions ~> https://codeforces.com/contest/2134/submission/335793014 By huanhuanonly
 * 
 * @b Number-theory ( @a Extended-Euclidean-algorithm )
 * 
 * ----August 27, 2025 [18h:49m:55s]----
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

std::pair<int64, int64> extended_euclid(int64 a, int64 b)
{
    if (b == 0)
    {
        return {1, 0};
    }
    else
    {
        const auto [x, y] = extended_euclid(b, a % b);
        return {y, x - a / b * y};
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int64 n, k;
        std::cin >> n >> k;

        std::vector<int64> v(n);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> v[i];
        }

        const int64 m = k + 1;
        const int64 inv = (extended_euclid(k, m).first % m + m) % m;

        for (int i = 0; i < n; ++i)
        {
            v[i] += (m - v[i] % m) * inv % m * k;
        }

        assert([&]() -> bool
        {
            int64 gcd = v[0];
            
            for (int i = 1; i < n; ++i)
            {
                gcd = std::gcd(gcd, v[i]);
            }
    
            return gcd > 1;
        }());

        for (int i = 0; i < n; ++i)
        {
            std::cout << v[i] << " \n"[i + 1 == n];
        }
    }

    return 0;
}