/**
 * Codeforces Round 359 (Div. 1)
 * 
 * => B. Kay and Snowflake ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/685/problem/B
 * 
 * Submissions ~> https://codeforces.com/contest/685/submission/344113330 By huanhuanonly
 * 
 * @b Dfs to find @a Tree-centroid of every subtree
 * 
 * ----October 17, 2025 [11h:18m:52s]----
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

    int n, q;
    std::cin >> n >> q;

    std::vector<std::vector<int>> e(n + 1);

    struct node
    {
        int parent;
        int size;
        int weight;
        int centroid;
    };

    std::vector<node> tree(n + 1);

    for (int i = 2, u; i <= n; ++i)
    {
        std::cin >> tree[i].parent;
        e[tree[i].parent].push_back(i);
    }

    auto dfs = [&](const auto& self, int u) -> void
    {
        tree[u].size = 1;

        for (int i : e[u])
        {
            self(self, i);

            tree[u].size += tree[i].size;
            tree[u].weight = std::max(tree[u].weight, tree[i].size);
        }

        if (tree[u].weight <= tree[u].size / 2)
        {
            tree[u].centroid = u;
            return;
        }

        for (int i : e[u])
        {
            for (int c = tree[i].centroid; c != u; c = tree[c].parent)
            {
                if (std::max(tree[c].weight, tree[u].size - tree[c].size) <= tree[u].size / 2)
                {
                    tree[u].centroid = c;
                    return;
                }
            }
        }

        assert(false);
    };

    dfs(dfs, 1);

    while (q--)
    {
        int u;
        std::cin >> u;

        std::cout << tree[u].centroid << '\n';
    }

    return 0;
}