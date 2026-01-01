/**
 * Codeforces Round 629 (Div. 3)
 * 
 * => E. Tree Queries ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/1328/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/1328/submission/354700871 By huanhuanonly
 * 
 * @b Dfs on @a Trees and @b Offline
 * 
 * ----December 23, 2025 [22h:23m:03s]----
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

    int n, m;
    std::cin >> n >> m;

    struct node
    {
        std::vector<int> children;
        std::vector<int> qids;
    };

    std::vector<node> tree(n + 1);

    auto connect = [&](int u, int v) -> void
    {
        tree[u].children.push_back(v);
        tree[v].children.push_back(u);
    };

    struct result
    {
        int  count;
        bool answer;
    };

    std::vector<result> answers(m);

    auto add_query = [&](int id, int u) -> void
    {
        ++answers[id].count;
        tree[u].qids.push_back(id);
    };

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        connect(u, v);
    }

    for (int i = 0; i < m; ++i)
    {
        int k;
        std::cin >> k;

        while (k--)
        {
            int u;
            std::cin >> u;

            add_query(i, u);
        }
    }

    auto calc = [&](const auto& self, int u, int parent) -> void
    {
        for (const int& v : tree[u].children)
        {
            if (v == parent)
            {
                continue;
            }

            for (const int& i : tree[v].qids)
            {
                if (--answers[i].count == 0)
                {
                    answers[i].answer = true;
                }
            }
        }

        for (const int& v : tree[u].children)
        {
            if (v == parent)
            {
                continue;
            }

            self(self, v, u);
        }

        for (const int& v : tree[u].children)
        {
            if (v == parent)
            {
                continue;
            }

            for (const int& i : tree[v].qids)
            {
                ++answers[i].count;
            }
        }
    };

    for (const int& i : tree[1].qids)
    {
        if (--answers[i].count == 0)
        {
            answers[i].answer = true;
        }
    }

    calc(calc, 1, 0);

    for (const auto& [cnt, yes] : answers)
    {
        if (yes)
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }

    return 0;
}