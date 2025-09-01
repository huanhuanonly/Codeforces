/**
 * => P3379 【模板】最近公共祖先（LCA） ( @c 普及/提高− )
 * 
 * -> https://www.luogu.com.cn/problem/P3379
 * 
 * Submissions ~> https://www.luogu.com.cn/record/151738766 By huanhuanonly
 * 
 * @b LCA ( @a heavy-light-decomposition )
 * 
 * ----September 01, 2025 [18h:29m:45s]----
*/

#include <bits/stdc++.h>

using uint = unsigned int;
using llong = long long int;
using ullong = unsigned long long int;
using ldouble = long double;

class Lca
{
public:

    const std::vector<std::vector<int>>& e;

    std::vector<int> depth, head, wson, size, fa;

    explicit Lca(const std::vector<std::vector<int>>& __e, int root = 1)
        : e(__e), depth(e.size()), head(e.size()), wson(e.size()), size(e.size()), fa(e.size(), root)
    {
        build(root);
        build_head(root, root);
    }

    int operator()(int x, int y)
    {
        while (head[x] != head[y])
        {
            if (depth[head[x]] > depth[head[y]])
                x = fa[head[x]];
            else
                y = fa[head[y]];
        }

        if (depth[x] < depth[y])
            return x;
        else
            return y;
    }

private:

    void build(int p)
    {
        depth[p] = depth[fa[p]] + 1;
        size[p] = 1;

        for (const auto& i : e[p])
        {
            if (i == fa[p])
                continue;

            fa[i] = p;

            build(i);

            size[p] += size[i];

            if (size[i] > size[wson[p]])
                wson[p] = i;
        }
    }

    void build_head(int p, int top)
    {
        head[p] = top;

        if (wson[p])
            build_head(wson[p], top);
        
        for (const auto& i : e[p])
        {
            if (i == fa[p] or i == wson[p])
                continue;

            build_head(i, i);
        }
    }

};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __localhost
    ::freopen("Input.txt", "r", stdin);
    ::freopen("Output.txt", "w", stdout);
#endif

    int n, m, s;
    std::cin >> n >> m >> s;

    std::vector<std::vector<int>> e(n + 1);

    for (int i = 1; i < n; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    Lca lca(e, s);

    while (m--)
    {
        int x, y;
        std::cin >> x >> y;

        std::cout << lca(x, y) << '\n';
    }

    return 0;
}