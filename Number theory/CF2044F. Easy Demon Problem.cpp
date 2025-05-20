/**
 * Codeforces Round 993 (Div. 4)
 * 
 * => F. Easy Demon Problem ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/2044/problem/F
 * 
 * Submissions ~> https://codeforces.com/contest/2044/submission/315785643 By huanhuanonly
 * 
 * @b Number-theory
 * 
 * ----April 16, 2025 [12h:14m:29s]----
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
struct hash
{
    using result_type = unsigned long long int;

    static_assert(std::is_integral<_Tp>::value, "This type is not an integer.");

    static result_type splitmix64(result_type x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    result_type operator()(_Tp x) const
    {
        static result_type FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(FIXED_RANDOM + x);
    }
};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<int64> a(n), b(m);

    int64 sum_a = 0, sum_b = 0;
    
    for (auto& i : a)
    {
        std::cin >> i;
        sum_a += i;
    }
    
    for (auto& i : b)
    {
        std::cin >> i;
        sum_b += i;
    }

    /**
     * X = SUM - Br * SUMA - Ac * SUMB + Ac * Br
     *   = SUMA * SUMB - Br * SUMA - Ac * SUMB + Ac * Br
     *   = SUMA * (SUMB - Br) - Ac * (SUMB - Br)
     *   = (SUMA - Ac) * (SUMB - Br)
     */

    std::unordered_set<int64, hash<int64>> l, r;

    for (const auto& i : a)
    {
        l.insert(sum_a - i);
    }
    
    for (const auto& i : b)
    {
        r.insert(sum_b - i);
    }

    auto check = [&](int64 x) -> bool
    {
        if (x == 0)
        {
            return l.contains(0) or r.contains(0);
        }

        for (const auto& i : std::views::iota(1LL)
                           | std::views::take(std::sqrt(std::abs(x)))
                           | std::views::filter([&](int64 i) -> bool { return std::abs(x) % i == 0; }))
        {
            if ((l.contains(i) and r.contains(x / i)) or
                (l.contains(x / i) and r.contains(i)))
            {
                return true;
            }
            else if ((l.contains(-i) and r.contains(-x / i)) or
                     (l.contains(-x / i) and r.contains(-i)))
            {
                return true;
            }
        }

        return false;
    };

    while (q--)
    {
        int64 x;
        std::cin >> x;

        if (check(x))
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }

    return 0;
}