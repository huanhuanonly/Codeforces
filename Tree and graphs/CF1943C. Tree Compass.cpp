/**
 * Codeforces Round 934 (Div. 1)
 * 
 * => C. Tree Compass
 * 
 * -> https://codeforces.com/problemset/problem/1943/C (2300)
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        std::vector<std::vector<int>> e(n + 1);

        for (int i = 1; i < n; ++i)
        {
            int u, v;
            std::cin >> u >> v;

            e[u].push_back(v);
            e[v].push_back(u);
        }

        if (n == 1)
        {
            std::cout << "1\n1 0\n";
            continue;
        }
        else if (n == 2)
        {
            std::cout << "2\n1 1\n2 1\n";
            continue;
        }

        std::vector<std::vector<int>> dc(n + 1, std::vector<int>(n));

        std::function<int(int, int, int, int)> build = [&](int dci, int u, int fa, int depth) -> int
        {
            ++dc[dci][depth];

            int mx = depth;

            for (const auto& i : e[u])
            {
                if (i == fa)
                    continue;

                mx = std::max(mx, build(dci, i, u, depth + 1));
            }

            return mx;
        };

        int radius = INT_MAX / 2;

        std::vector<int> vertex;
        vertex.reserve(2);

        for (int i = 1; i <= n; ++i)
        {
            dc[i].resize(build(i, i, i, 0) + 1);

            if (dc[i].size() - 1 < radius)
            {
                radius = dc[i].size() - 1;

                vertex.clear();
                vertex.push_back(i);
            }
            else if (dc[i].size() - 1 == radius)
            {
                vertex.push_back(i);
            }
        }

        if (vertex.size() == 1)
        {
            std::cout << radius + 1 << '\n';

            for (int i = 0; i <= radius; ++i)
                std::cout << vertex.front() << ' ' << i << '\n';
        }
        else
        {
            std::cout << ((radius + 1) & ~1) << '\n';

            for (int i = 1; i <= radius; i += 2)
                std::cout << vertex.front() << ' ' << i << '\n',
                std::cout << vertex.back()  << ' ' << i << '\n';
        }
    }

    return 0;
}