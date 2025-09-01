/**
 * Testing Round 12
 * 
 * => B. Restaurant ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/597/problem/B
 * 
 * Submissions ~> https://codeforces.com/contest/597/submission/328936114 By huanhuanonly
 * 
 * @b Linear-DP
 * 
 * ----July 15, 2025 [01h:06m:35s]----
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

    std::map<int, int> mp;

    std::vector<std::pair<int, int>> v(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i].first >> v[i].second;
        mp[v[i].first], mp[v[i].second];
    }

    for (auto [i, it] = std::tuple(1, mp.begin()); it != mp.end(); ++i, ++it)
    {
        it->second = i;
    }

    std::ranges::sort(v, [](const auto& lv, const auto& rv) -> bool {
        return lv.second < rv.second;
    });

    std::vector<int> dp(mp.size() + 1);

    int pos = 1;

    for (int i = 0; i < n; ++i)
    {
        for (; pos <= mp[v[i].second]; ++pos)
        {
            dp[pos] = std::max(dp[pos], dp[pos - 1]);
        }

        dp[mp[v[i].second]] = std::max(dp[mp[v[i].second]], dp[mp[v[i].first] - 1] + 1);
    }

    std::cout << dp.back();

    return 0;
}