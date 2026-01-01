/**
 * Cloudflare纪念赛
 * 
 * => L-小红的字符串构造
 * 
 * -> https://ac.nowcoder.com/acm/contest/123509/L
 * 
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=80641497&returnHomeType=1&uid=934399949 By huanhuanonly
 * 
 * @b Graph-modeling and @b Dfs
 * 
 * ----November 20, 2025 [01h:28m:57s]----
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

    std::string a, b;
    std::cin >> a >> b;

    constexpr auto space = '_';

    std::string ans(n, space);

    std::vector<int> cur(1 << 7);

    std::vector<std::set<std::pair<char, int>>> e(1 << 7);

    for (int i = 0; i < n; ++i)
    {
        if (a[i] == b[i])
        {
            ans[i] = a[i];
            cur[a[i]] ^= 1;
        }
        else
        {
            e[a[i]].emplace(b[i], i);
            e[b[i]].emplace(a[i], i);
        }
    }

    std::vector<bool> vis(1 << 7);

    auto dfs = [&](const auto& self, char u, std::pair<char, int> fa) -> bool
    {
        if (vis[u])
        {
            return false;
        }
        
        vis[u] = true;

        for (auto it = e[u].begin(); it != e[u].end(); )
        {
            if (*it == fa)
            {
                ++it;
                continue;
            }

            if (self(self, it->first, {u, it->second}))
            {
                ans[it->second] = it->first;
            }
            else
            {
                cur[u] ^= 1;
                ans[it->second] = u;
            }

            e[it->first].erase({u, it->second});
            it = e[u].erase(it);
        }

        return cur[u] & 1;
    };

    bool can = true;

    for (char i = 'a'; i <= 'z'; ++i)
    {
        if (not vis[i])
        {
            if (dfs(dfs, i, {space, -1}))
            {
                can = false;
                break;
            }
        }
    }

    if (can)
    {
        std::cout << ans;
    }
    else
    {
        std::cout << -1;
    }

    return 0;
}