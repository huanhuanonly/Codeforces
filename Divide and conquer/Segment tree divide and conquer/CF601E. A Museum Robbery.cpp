/**
 * Codeforces Round 333 (Div. 1)
 * 
 * => E. A Museum Robbery ( @c 2800 )
 * 
 * -> https://codeforces.com/contest/601/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/601/submission/347104999 By huanhuanonly
 * 
 * @b Segment-tree-divide-and-conquer
 * @b Knapsack-DP ( @a 0/1-knapsack-problem )
 * 
 * ----November 02, 2025 [21h:04m:09s]----
*/

/// @brief This is an @c interesting problem!

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

class SegmentTree
{
public:

    struct item
    {
        int id, v, w;

        bool operator<(const item& other) const
        {
            return id < other.id;
        }
    };

    explicit SegmentTree(int n) : tree(n << 2) { }

    static int ls(int u)
    {
        return u << 1;
    }

    static int rs(int u)
    {
        return u << 1 | 1;
    }

    void insert(int u, int l, int r, int x, int y, const item& value)
    {
        if (x <= l and r <= y)
        {
            tree[u].push_back(value);
            return;
        }

        const int mid = l + r >> 1;

        if (x <= mid)
        {
            insert(ls(u), l, mid, x, y, value);
        }
        if (y > mid)
        {
            insert(rs(u), mid + 1, r, x, y, value);
        }
    }

    void dfs(int u, int l, int r, auto& dp, std::vector<uint64>& ans, const auto& f)
    {
        for (const auto& value : tree[u])
        {
            dp.emplace_back(dp.back().size());

            for (int i = 1; i < dp.back().size(); ++i)
            {
                dp.back()[i] = std::max(dp[dp.size() - 2][i], dp.back()[i - 1]);

                if (i >= value.w)
                {
                    dp.back()[i] = std::max(dp.back()[i], dp[dp.size() - 2][i - value.w] + value.v);
                }
            }
        }

        if (l == r)
        {
            ans[l] = f(dp.back());
        }
        else
        {
            const int mid = l + r >> 1;

            dfs(ls(u), l, mid, dp, ans, f);
            dfs(rs(u), mid + 1, r, dp, ans, f);
        }

        dp.resize(dp.size() - tree[u].size());
    }

private:

    std::vector<std::vector<item>> tree;
};

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

    constexpr int maxn = 5000 + 30000;

    SegmentTree seg(maxn + 1);

    std::vector<SegmentTree::item> list(n + 1);
    list.reserve(maxn + 1);

    std::map<int, int> mp;

    for (int i = 1; i <= n; ++i)
    {
        list[i].id = i;
        std::cin >> list[i].v >> list[i].w;

        mp[i] = i;
    }

    int q;
    std::cin >> q;

    std::vector<int> queries;
    queries.reserve(q);

    for (int i = 1; i <= q; ++i)
    {
        int opt;
        std::cin >> opt;

        if (opt == 1)
        {
            int v, w;
            std::cin >> v >> w;

            list.emplace_back(list.size(), v, w);
            mp[list.back().id] = n + i;
        }
        else if (opt == 2)
        {
            int x;
            std::cin >> x;

            seg.insert(1, 1, maxn, mp[x], n + i - 1, list[x]);
            mp.erase(x);
        }
        else
        {
            queries.push_back(n + i);
        }
    }

    for (const auto& [id, start] : mp)
    {
        seg.insert(1, 1, maxn, start, n + q, list[id]);
    }

    std::vector<uint64> ans(maxn + 1);

    constexpr uint64 p = 1e7 + 19, mod = 1e9 + 7;

    std::vector<uint64> pow(k, 1);

    for (uint64 i = 1; i < k; ++i)
    {
        pow[i] = pow[i - 1] * p % mod;
    }

    std::vector dp(1, std::vector<int>(k + 1));

    seg.dfs(1, 1, maxn, dp, ans, [k, &pow](const std::vector<int>& dp) -> uint64
    {
        uint64 sum = 0;

        for (int i = 1; i <= k; ++i)
        {
            sum += dp[i] * pow[i - 1] % mod;
            sum %= mod;
        }

        return sum;
    });

    for (const int i : queries)
    {
        std::cout << ans[i] << '\n';
    }

    return 0;
}