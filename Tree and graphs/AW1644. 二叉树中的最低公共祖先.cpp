/**
 * => 1644. 二叉树中的最低公共祖先
 * 
 * -> https://www.acwing.com/problem/content/1646
 * 
 * @b LCA @a (Lowest-Common-Ancestor)
*/

#include <bits/stdc++.h>

using uint = unsigned int;
using llong = long long int;
using ullong = unsigned long long int;
using ldouble = long double;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __localhost
    ::freopen("Input.txt", "r", stdin);
    ::freopen("Output.txt", "w", stdout);
#endif

    int q, n;
    std::cin >> q >> n;

    std::vector<int> in(n), pre(n);

    std::map<int, int> mp;

    for (int i = 0; i < n; ++i)
        std::cin >> in[i],
        mp[in[i]] = i;

    for (int i = 0; i < n; ++i)
        std::cin >> pre[i];

    struct node
    {
        int ls, rs;
        int number;
        int depth;
    };
    std::vector<node> tree(n, {-1, -1, 0});

    std::map<int, int> log;

    std::vector<std::vector<int>> dp(n, std::vector<int>(20));

    std::function<void(int&, int, int, int)> build = [&, num = 0](int& p, int l, int r, int fa) mutable -> void
    {
        if (not (mp[pre[num]] >= l and mp[pre[num]] <= r))
            return;

        int i = num++;

        p = i;
        tree[p].number = pre[i];
        tree[p].depth = tree[fa].depth + 1;

        log[tree[p].number] = i;
        
        dp[p][0] = fa;
        for (int i = 1; i < 20; ++i)
        {
            dp[p][i] = dp[dp[p][i - 1]][i - 1];
        }

        build(tree[p].ls, l, std::max(l, mp[pre[i]] - 1), p);
        build(tree[p].rs, std::min(r, mp[pre[i]] + 1), r, p);
    };

    auto lca = [&](int u, int v) -> int
    {
        if (tree[u].depth > tree[v].depth)
            std::swap(u, v);

        for (int i = 20; i >= 0; --i)
        {
            if (tree[dp[v][i]].depth >= tree[u].depth)
            {
                v = dp[v][i];
            }
        }

        if (u == v)
            return u;

        for (int i = 20; i >= 0; --i)
        {
            if (dp[u][i] != dp[v][i])
            {
                u = dp[u][i];
                v = dp[v][i];
            }
        }

        return dp[u][0];
    };

    int root = 0;
    build(root, 0, n - 1, root);

    while (q--)
    {
        int u, v;
        std::cin >> u >> v;

        auto fu = log.find(u), fv = log.find(v);

        if (fu == log.end() and fv == log.end())
            std::cout << "ERROR: " << u << " and " << v << " are not found.\n";
        else if (fu == log.end())
            std::cout << "ERROR: " << u << " is not found.\n";
        else if (fv == log.end())
            std::cout << "ERROR: " << v << " is not found.\n";
        else
        {
            int ans = lca(log[u], log[v]);

            if (tree[ans].number == u)
                std::cout << u << " is an ancestor of " << v << ".\n";
            else if (tree[ans].number == v)
                std::cout << v << " is an ancestor of " << u << ".\n";
            else
                std::cout << "LCA of " << u << " and " << v << " is " << tree[ans].number << ".\n";
        }
    }

    return 0;
}