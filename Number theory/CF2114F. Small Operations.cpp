/**
 * Codeforces Round 1027 (Div. 3)
 * 
 * => F. Small Operations ( @c 2000 )
 * 
 * -> https://codeforces.com/contest/2114/problem/F
 * 
 * Submissions ~> https://codeforces.com/contest/2114/submission/321536882 By huanhuanonly
 * 
 * @b Number-theory ( @a prime-number )
 * 
 * ----May 27, 2025 [01h:13m:44s]----
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

template<typename _Tp>
auto prime_factorization(_Tp __n)
{
    std::vector<_Tp> res;

    for (_Tp i = 2; i <= __n / i; ++i)
    {
        while (__n % i == 0)
        {
            res.push_back(i);
            __n /= i;
        }
    }

    if (__n != 1)
    {
        res.push_back(__n);
    }

    return res;
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
        uint64 x, y, k;
        std::cin >> x >> y >> k;

        auto eval = [&](uint64 n) -> std::optional<uint64>
        {
            auto v = prime_factorization(n);

            if (v.empty())
            {
                return 0;
            }

            std::ranges::sort(v);

            uint64 min = std::numeric_limits<uint64>::max();

            if (not v.empty() and v.back() > k)
            {
                return std::nullopt;
            }

            do
            {
                uint64 cnt = 1, sum = 1;

                for (int i = 0; i < v.size(); ++i)
                {
                    if (sum * v[i] <= k)
                    {
                        sum *= v[i];
                    }
                    else
                    {
                        ++cnt;
                        sum = v[i];
                    }
                }

                min = std::min(min, cnt);
            } while (std::next_permutation(v.begin(), v.end()));
            
            return min;
        };

        uint64 gcd = std::gcd(x, y);

        if (auto a = eval(x / gcd), b = eval(y / gcd); a.has_value() and b.has_value())
        {
            std::cout << a.value() + b.value() << '\n';
        }
        else
        {
            std::cout << -1 << '\n';
        }
    }

    return 0;
}