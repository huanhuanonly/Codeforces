/**
 * Codeforces Round 105 (Div. 2)
 * 
 * => C. Terse princess ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/148/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/148/submission/371161155 By huanhuanonly
 * 
 * @b Constructive
 * 
 * ----April 15, 2026 [00h:49m:17s]----
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

    int n, a, b;
    std::cin >> n >> a >> b;

    std::vector<int> v{1};

    for (int i = 0, s = v.front(); i < b; ++i)
    {
        v.push_back(s + 1);
        s += v.back();
    }

    if (b == 0 and a)
    {
        v.push_back(1);
    }

    for (int i = 0; i < a; ++i)
    {
        v.push_back(v.back() + 1);
    }

    for (; v.size() < n; v.push_back(1));

    if (v.size() == n and v.back() <= 50000)
    {
        for (int i = 0; i < n; ++i)
        {
            std::cout << v[i] << ' ';
        }
    }
    else
    {
        std::cout << "-1";
    }

    return 0;
}