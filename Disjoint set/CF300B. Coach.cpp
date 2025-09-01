/**
 * Codeforces Round 181 (Div. 2)
 * 
 * => B. Coach ( @c 1500 )
 * 
 * -> https://codeforces.com/contest/300/problem/B
 * 
 * Submissions ~> https://codeforces.com/contest/300/submission/329291525 By huanhuanonly
 * 
 * @b Disjoint-set
 * 
 * ----July 17, 2025 [15h:15m:14s]----
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

class DisjointSet
{
public:
    std::vector<int> tree;

    explicit DisjointSet(std::size_t n)
        : tree(n)
    {
        std::iota(tree.begin(), tree.end(), 0);
    }

    int find(int u)
    {
        return tree[u] == u ? u : tree[u] = find(tree[u]);
    }

    void merge(int u, int v)
    {
        tree[find(v)] = find(u);
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

    int n, m;
    std::cin >> n >> m;

    DisjointSet dsu(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        dsu.merge(u, v);
    }

    std::map<int, std::vector<int>> teams;
    std::set<int> st;

    bool yes = true;

    for (int i = 1; i <= n; ++i)
    {
        teams[dsu.find(i)].push_back(i);
    }

    for (auto it = teams.begin(); it != teams.end(); )
    {
        if (it->second.size() == 1)
        {
            st.insert(it->second.front());
            it = teams.erase(it);
        }
        else
        {
            ++it;
        }
    }

    for (auto& [key, values] : teams)
    {
        if (values.size() > 3)
        {
            yes = false;
            break;
        }
        else if (values.size() < 3)
        {
            while (not st.empty() and values.size() < 3)
            {
                values.push_back(st.extract(st.begin()).value());
            }
            
            if (values.size() < 3)
            {
                yes = false;
                break;
            }
        }
    }

    if (yes)
    {
        for (const auto& [key, values] : teams)
        {
            std::cout << values[0] << ' ';
            std::cout << values[1] << ' ';
            std::cout << values[2] << '\n';
        }

        while (not st.empty())
        {
            std::cout << st.extract(st.begin()).value() << ' ';
            std::cout << st.extract(st.begin()).value() << ' ';
            std::cout << st.extract(st.begin()).value() << '\n';
        }
    }
    else
    {
        std::cout << -1;
    }

    return 0;
}