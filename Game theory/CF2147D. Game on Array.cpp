/**
 * Codeforces Global Round 29 (Div. 1 + Div. 2)
 * 
 * => D. Game on Array ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/2147/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2147/submission/349740541 By huanhuanonly
 * 
 * @b Game-theory and @b Classification-discussion
 * 
 * ----November 20, 2025 [00h:02m:38s]----
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
        uint64 n;
        std::cin >> n;

        std::map<uint64, uint64> cnt;

        for (uint64 i = 0, v; i < n; ++i)
        {
            std::cin >> v;
            ++cnt[v];
        }

        std::array<uint64, 2> sum{};

        for (auto it = cnt.begin(); it != cnt.end(); )
        {
            if ((it->first & 1) == 0)
            {
                sum[0] += (it->first * it->second) / 2;
                sum[1] += (it->first * it->second) / 2;

                it = cnt.erase(it);
            }
            else
            {
                ++it;
            }
        }

        std::priority_queue<std::pair<uint64, uint64>> que;

        for (auto it = cnt.begin(); it != cnt.end(); ++it)
        {
            que.emplace(it->second, it->first);
        }

        int layer = 0;

        while (not que.empty())
        {
            const auto [count, value] = que.top();
            que.pop();

            sum[layer] += (value + 1) / 2 * count;

            layer ^= 1;

            sum[layer] += value / 2 * count;
        }

        std::cout << sum[0] << ' ' << sum[1] << '\n';
    }

    return 0;
}