/**
 * Codeforces Round 805 (Div. 3)
 * 
 * => G1. Passable Paths (easy version) ( @c 1900 )
 * => G2. Passable Paths (hard version) ( @c 2000 )
 * 
 * -> https://codeforces.com/contest/1702/problem/G1
 * -> https://codeforces.com/contest/1702/problem/G2
 * 
 * Submissions ~> https://codeforces.com/contest/1702/submission/264355660 By huanhuanonly
 * Submissions ~> https://codeforces.com/contest/1702/submission/264355559 By huanhuanonly
 * 
 * @b LCA ( @a heavy-light-decomposition )
 * 
 * ----June 06, 2024 [15h:17m:04s]----
*/

#include <bits/stdc++.h>

using uint    = unsigned int;
using llong   = long long int;
using ullong  = unsigned long long int;
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
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif


    int n;
    std::cin >> n;

    std::vector<std::vector<int>> e(n + 1);

    for (int i = 2; i <= n; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    Lca lca(e);

    int q;
    std::cin >> q;

    while (q--)
    {
        int k;
        std::cin >> k;

        std::vector<int> v(k);

        for (int i = 0; i < k; ++i)
            std::cin >> v[i];

        if (k <= 2)
        {
            std::cout << "YES\n";
            continue;
        }

        std::sort(v.begin(), v.end(), [&](int lv, int rv) -> bool
        {
            return lca.depth[lv] < lca.depth[rv];
        });

        std::vector<int> que;

        int fa_lca = lca(v[0], v[1]);

        if (fa_lca == v[0])
            que.push_back(v[0]);
        else if (fa_lca == v[1])
            que.push_back(v[1]);
        else
            que.push_back(v[0]),
            que.push_back(v[1]);

        bool yes = true;

        for (int i = 0; i < k; ++i)
        {
            bool has = false;

            for (auto& cur : que)
            {
                if (lca(cur, v[i]) == cur)
                {
                    cur = v[i];
                    has = true;
                    break;
                }
            }

            if (not has)
            {
                if (int nfa = lca(que.front(), v[i]); lca.depth[nfa] <= lca.depth[fa_lca])
                {
                    fa_lca = nfa;
                    que.push_back(v[i]);

                    if (que.size() > 2)
                    {
                        yes = false;
                        break;
                    }
                }
                else
                {
                    yes = false;
                    break;
                }
            }
        }

        std::cout << (yes ? "YES\n" : "NO\n");
    }

    return 0;
}