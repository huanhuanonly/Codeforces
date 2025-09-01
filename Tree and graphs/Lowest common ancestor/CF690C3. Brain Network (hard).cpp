/**
 * Helvetic Coding Contest 2016 online mirror (teams, unrated)
 * 
 * => C3. Brain Network (hard) ( @c 2200 )
 * 
 * -> https://codeforces.com/contest/690/problem/C3
 * 
 * Submissions ~> https://codeforces.com/contest/690/submission/327406131 By huanhuanonly
 * 
 * @b LCA ( @a heavy-light-decomposition ) to maintain @a tree-diameter with dynamic edge insertion
 * 
 * ----July 04, 2025 [23h:29m:59s]----
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

    int operator()(int x, int y) const
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

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> e(n + 1);
    
    for (int i = 2; i <= n; ++i)
    {
        int v;
        std::cin >> v;

        e[v].push_back(i);
        e[i].push_back(v);
    }

    auto dist = [&, lca = Lca(e)](int u, int v) -> int
    {
        return lca.depth[u] + lca.depth[v] - lca.depth[lca(u, v)] * 2;
    };

    int u = 1, v = 1, d = 0;

    for (int i = 2; i <= n; ++i)
    {
        if (int du = dist(u, i), dv = dist(v, i); du >= dv and du > d)
        {
            v = i;
            d = du;
        }
        else if (dv >= du and dv > d)
        {
            u = i;
            d = dv;
        }

        std::cout << d << ' ';
    }

    return 0;
}