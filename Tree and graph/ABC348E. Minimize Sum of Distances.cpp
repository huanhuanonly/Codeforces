/**
 * Toyota Programming Contest 2024#4（AtCoder Beginner Contest 348）
 * 
 * => E - Minimize Sum of Distances
 * 
 * -> https://atcoder.jp/contests/abc348/tasks/abc348_e
 * 
 * @b Trees
*/

#include <bits/stdc++.h>

using uint    = unsigned int;
using llong   = long long int;
using ullong  = unsigned long long int;
using ldouble = long double;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __localhost
    ::freopen("Input.txt", "r", stdin);
    ::freopen("Output.txt", "w", stdout);
#endif

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> e(n + 1);

    for (int i = 1; i < n; ++i)
    {
        int x, y;
        std::cin >> x >> y;

        e[x].push_back(y);
        e[y].push_back(x);
    }

    std::vector<ullong> c(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> c[i];
    }

    std::vector<ullong> size(n + 1);

    ullong ans = ULLONG_MAX;

    std::function<ullong(int, int, int)> dfs = [&](int p, int fa, int layer) -> ullong
    {
        size[p] = c[p];

        ullong res = c[p] * layer;

        for (const auto& i : e[p])
        {
            if (i == fa)
                continue;

            res += dfs(i, p, layer + 1);

            size[p] += size[i];
        }

        return res;
    };

    std::function<void(int, int, ullong)> dfs2 = [&](int p, int fa, ullong cnt) -> void
    {
        ans = std::min(ans, cnt);

        for (const auto& i : e[p])
        {
            if (i == fa)
                continue;

            dfs2(i, p, cnt - size[i] + (size[1] - size[i]));
        }
    };

    dfs2(1, 1, dfs(1, 1, 0));

    std::cout << ans;

    return 0;
}