/**
 * RCC 2014 Warmup (Div. 2)
 * 
 * => E. Square Table ( @c 2400 )
 * 
 * -> https://codeforces.com/contest/417/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/417/submission/339262316 By huanhuanonly
 * 
 * @b Constructive
 * 
 * ----September 18, 2025 [21h:15m:20s]----
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

    std::vector<int> a(n, 1), b(m, 1);

    auto fill = [](auto& v) -> void
    {
        if (v.size() & 1)
        {
            if (v.size() > 1)
            {
                v.front() = 2;
                v.back() = (v.size() + 1) / 2;
            }
        }
        else
        {
            if (v.size() == 2)
            {
                v[0] = 3;
                v[1] = 4;
            }
            else
            {
                v.back() = (v.size() - 2) / 2;
            }
        }
    };

    fill(a);
    fill(b);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cout << a[i] * b[j] << " \n"[j + 1 == m];
        }
    }

    return 0;
}