/**
 * The 2022 ICPC Asia Xian Regional Contest
 * 
 * => L. Tree
 * 
 * -> https://codeforces.com/gym/104077/problem/L
 * 
 * @b Long-path-decomposition
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        std::vector<std::vector<int>> e(n + 1);

        for (int i = 2; i <= n; ++i)
        {
            int u;
            std::cin >> u;

            e[u].push_back(i);
            e[i].push_back(u);
        }

        struct node
        {
            int size, depth, wson, fa, color;
        };

        std::vector<node> tree(n + 1);

        std::vector<int> colors(n + 1);

        std::queue<int> que;

        std::function<int(int, int)> split = [&](int u, int fa) -> int
        {
            tree[u].fa = fa;
            tree[u].depth = tree[fa].depth + 1;
            tree[u].size = 1;

            int mx = 0;

            for (const auto& i : e[u])
            {
                if (i == fa)
                    continue;

                int ct = split(i, u);

                if (ct > mx)
                    tree[u].wson = i,
                    mx = ct;

                tree[u].size += tree[i].size;
            }

            return std::max(mx, tree[u].depth);
        };

        split(1, 1);

        std::function<void(int, int, int)> dfs = [&, num = 1](int u, int fa, int ct) mutable -> void
        {
            ++colors[ct];
            tree[u].color = ct;

            if (tree[u].wson)
                dfs(tree[u].wson, u, ct);
            
            for (const auto& i : e[u])
            {
                if (i == fa or i == tree[u].wson)
                    continue;

                dfs(i, u, ++num);
            }

            if (tree[u].size == 1)
                que.push(u);
        };

        dfs(1, 1, 1);

        std::sort(colors.begin(), colors.end(), std::greater<int>());

        int ans = INT_MAX;

        for (int i = 0; i < colors.size(); ++i)
        {
            ans = std::min(ans, i + colors[i]);
        }

        std::cout << ans << '\n';
    }

    return 0;
}