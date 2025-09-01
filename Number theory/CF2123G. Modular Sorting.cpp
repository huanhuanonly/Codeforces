/**
 * Codeforces Round 1034 (Div. 3)
 * 
 * => G. Modular Sorting ( @c 2100 )
 * 
 * -> https://codeforces.com/contest/2123/problem/G
 * 
 * Submissions ~> https://codeforces.com/contest/2123/submission/327131621 By huanhuanonly
 * 
 * @b Number-theory ( @a divisor )
 * 
 * ----July 03, 2025 [02h:19m:13s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n, m, q;
        std::cin >> n >> m >> q;

        std::vector<int> v(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
        }

        std::map<int, int> mp;

        for (int gcd : std::views::iota(2, static_cast<int>(std::sqrt(m) + 1)) |
                       std::views::filter([&](int i) -> bool { return m % i == 0; }) |
                       std::views::transform([&](int i) { return std::array{i, m / i}; }) |
                       std::views::join)
        {
            if (int& cnt = mp[gcd]; cnt == 0)
            {
                for (int i = 2; i <= n; ++i)
                {
                    cnt += v[i - 1] % gcd > v[i] % gcd;
                }
            }
        }

        int opt;
        while (q--)
        {
            std::cin >> opt;

            if (opt == 1)
            {
                int i, x;
                std::cin >> i >> x;

                for (auto& [gcd, count] : mp)
                {
                    int cnt = 0;

                    if (i > 1 and v[i - 1] % gcd > v[i] % gcd)
                    {
                        --cnt;
                    }

                    if (i < n and v[i] % gcd > v[i + 1] % gcd)
                    {
                        --cnt;
                    }

                    if (i > 1 and v[i - 1] % gcd > x % gcd)
                    {
                        ++cnt;
                    }

                    if (i < n and x % gcd > v[i + 1] % gcd)
                    {
                        ++cnt;
                    }

                    count += cnt;
                }

                v[i] = x;
            }
            else
            {
                int k;
                std::cin >> k;

                if (int gcd = std::gcd(m, k); mp[gcd] <= m / gcd - 1)
                {
                    std::cout << "YES\n";
                }
                else
                {
                    std::cout << "NO\n";
                }
            }
        }
    }

    return 0;
}