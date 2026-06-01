/**
 * 哈尔滨华德学院第十七届程序设计竞赛（同步赛）
 *
 * => I-不好，Alice和Bob又来做游戏了
 *
 * -> https://ac.nowcoder.com/acm/contest/132781/I
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83577650 By huanhuanonly
 *
 * @b Tree-DP
 *
 * ----May 12, 2026 [20h:38m:13s]----
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

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> e(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    std::vector<bool> dp(n + 1);

    auto dfs = [&](const auto& self, int u, int fa) -> void
    {
        for (const auto& v : e[u])
        {
            if (v != fa)
            {
                self(self, v, u);

                if (not dp[v])
                {
                    dp[u] = true;
                }
            }
        }
    };

    dfs(dfs, 1, 0);

    std::vector<bool> ans(n + 1);

    auto dfs2 = [&](const auto& self, int u, int fa, bool fadp) -> void
    {
        int cnt = fadp;

        for (const auto& v : e[u])
        {
            if (v != fa)
            {
                cnt += not dp[v];
            }
        }

        ans[u] = cnt;

        for (const auto& v : e[u])
        {
            if (v != fa)
            {
                self(self, v, u, not (cnt - not dp[v]));
            }
        }
    };

    dfs2(dfs2, 1, 0, false);

    for (int i = 1; i <= n; ++i)
    {
        if (ans[i])
        {
            std::cout << "Alice\n";
        }
        else
        {
            std::cout << "Bob\n";
        }
    }

    return 0;
}