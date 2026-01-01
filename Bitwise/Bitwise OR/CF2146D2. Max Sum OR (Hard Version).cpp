/**
 * Codeforces Round 1052 (Div. 2)
 * 
 * => D2. Max Sum OR (Hard Version) ( @c 2000 )
 * 
 * -> https://codeforces.com/contest/2146/problem/D2
 * 
 * Submissions ~> https://codeforces.com/contest/2146/submission/340143823 By huanhuanonly
 * 
 * @b Bitwise-OR
 * 
 * ----September 24, 2025 [19h:02m:14s]----
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

constexpr int64 lowbit(int64 x)
{
    return x & -x;
}

constexpr void remove_same_highbit(int64& l, int64& r)
{
    uint64 x = l, y = r;

    while (std::countl_zero(x) == std::countl_zero(y))
    {
        const uint64 cnt = std::countl_zero(x) + 1;

        x = x << cnt >> cnt;
        y = y << cnt >> cnt;
    }

    l = x, r = y;
}

template<typename _RandomAccessIterator>
constexpr void optimize(int64 l, int64 r, _RandomAccessIterator first)
{
    if (l == r)
    {
        return;
    }

    remove_same_highbit(l, r);
    const int64 offset = l;

    int64 start = -1;

    for (int64 i = r; i >= l; )
    {
        if (i == 0)
        {
            break;
        }

        int64 mask = i << 1;
        
        for (; mask != lowbit(mask); mask -= lowbit(mask));
        --mask;

        const int64 j = i ^ mask;

        if (j < l)
        {
            if (start == -1)
            {
                start = i;
            }

            --i;
        }
        else
        {
            if (start != -1)
            {
                optimize(i + 1, start, first + (i + 1 - offset));
                start = -1;
            }

            std::reverse(first + (j - offset), first + (i + 1 - offset));
            i = j - 1;
        }
    }

    if (start != -1)
    {
        optimize(l, start, first + (l - offset));
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
        int64 l, r;
        std::cin >> l >> r;

        std::vector<int64> v(r - l + 1);
        std::iota(v.begin(), v.end(), l);

        optimize(l, r, v.begin());

        int64 sum = 0;

        for (int64 i = l; i <= r; ++i)
        {
            sum += (i | v[i - l]);
        }

        std::cout << sum << '\n';

        for (int64 i : v)
        {
            std::cout << i << ' ';
        }

        std::cout.put('\n');
    }

    return 0;
}