/**
 * VK Cup 2016 - Round 3
 * 
 * => B. Bear and Two Paths ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/643/problem/B
 * 
 * Submissions ~> https://codeforces.com/contest/643/submission/341128515 By huanhuanonly
 * 
 * @b Constructive and @b Graphs
 * 
 * ----September 30, 2025 [09h:46m:00s]----
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

    int n, k;
    std::cin >> n >> k;

    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    if (n == 4 or k < n + 1)
    {
        std::cout << -1;
    }
    else
    {
        std::vector<int> path;
        path.reserve(n - 4);
        
        for (int i = 1; i <= n; ++i)
        {
            if (i != a and i != b and i != c and i != d)
            {
                path.push_back(i);
            }
        }

        std::cout << a << ' ' << c << ' ';
        std::ranges::for_each(path, [](int i) -> void { std::cout << i << ' '; });
        std::cout << d << ' ' << b << '\n';

        std::cout << c << ' ' << a << ' ';
        std::ranges::for_each(path, [](int i) -> void { std::cout << i << ' '; });
        std::cout << b << ' ' << d << '\n';
    }

    return 0;
}