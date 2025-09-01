/**
 * Codeforces Round 484 (Div. 2)
 * 
 * => D. Shark ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/982/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/982/submission/327363895 By huanhuanonly
 * 
 * @b Implementation
 * 
 * ----July 04, 2025 [18h:11m:25s]----
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

    int n;
    std::cin >> n;

    std::vector<int> v(n + 1);

    std::map<int, std::vector<int>> pos;

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> v[i];
        pos[v[i]].push_back(i);
    }
    
    std::set<std::pair<int, int>> lr, rl;
    std::multiset<int> sizes;

    int seg = 0, k = 0;

    for (const auto& [key, values] : pos)
    {
        for (int i : values)
        {
            auto cur = std::make_pair(i, i);

            if (auto it = lr.lower_bound({i + 1, 0}); it != lr.end() and it->first == i + 1)
            {
                cur.second = it->second;

                sizes.extract(it->second - it->first);

                rl.erase(std::make_pair(it->second, it->first));
                lr.erase(it);
            }

            if (auto it = rl.lower_bound({i - 1, 0}); it != rl.end() and it->first == i - 1)
            {
                cur.first = it->second;

                sizes.extract(it->first - it->second);

                lr.erase(std::make_pair(it->second, it->first));
                rl.erase(it);
            }

            lr.insert(cur);
            rl.insert(std::make_pair(cur.second, cur.first));

            sizes.insert(cur.second - cur.first);
        }

        if (*sizes.begin() == *sizes.rbegin())
        {
            if (seg < sizes.size())
            {
                seg = sizes.size();
                k = key + 1;
            }
        }
    }

    std::cout << k;

    return 0;
}