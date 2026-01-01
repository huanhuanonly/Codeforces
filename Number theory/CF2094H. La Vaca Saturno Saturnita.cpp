/**
 * Codeforces Round 1017 (Div. 4)
 * 
 * => H. La Vaca Saturno Saturnita ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/2094/problem/H
 * 
 * Submissions ~> https://codeforces.com/contest/2094/submission/347580704 By huanhuanonly
 * 
 * @b Number-theory ( @a divisor )
 * 
 * ----November 06, 2025 [00h:36m:56s]----
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

    std::vector<std::vector<int>> divisors(1e5 + 1);

    for (int i = 2; i < divisors.size(); ++i)
    {
        for (int j = 1; i * j < divisors.size(); ++j)
        {
            divisors[i * j].push_back(i);
        }
    }

    int _;
    std::cin >> _;

    while (_--)
    {
        int n, q;
        std::cin >> n >> q;

        std::vector<int> v(n + 1);
        std::map<int, std::vector<int>> pos;

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
            pos[v[i]].push_back(i);
        }

        while (q--)
        {
            int k, l, r;
            std::cin >> k >> l >> r;
            
            int cpos = l;
            
            uint64 ans = 0;
            
            while (cpos <= r)
            {
                for (; k % v[cpos] == 0; k /= v[cpos]);

                int next = r + 1;

                for (const int d : divisors[k])
                {
                    if (auto it = std::ranges::upper_bound(pos[d], cpos); it != pos[d].end())
                    {
                        next = std::min(next, *it);
                    }
                }

                ans += static_cast<uint64>(next - cpos) * k;
                cpos = next;
            }

            std::cout << ans << '\n';
        }
    }

    return 0;
}