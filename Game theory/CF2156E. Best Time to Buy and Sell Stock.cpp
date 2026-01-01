/**
 * Codeforces Round 1061 (Div. 2)
 * 
 * => E. Best Time to Buy and Sell Stock ( @c 2500 )
 * 
 * -> https://codeforces.com/contest/2156/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2156/submission/346041487 By huanhuanonly
 * 
 * @b Game-theory
 * @b Binary-search
 * @b Graph-modeling
 * @b Depth-first-search
 * @b Classification-discussion
 * 
 * ----October 27, 2025 [23h:21m:48s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        std::vector<int64> v(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
        }

        auto check = [&](int64 g) -> bool
        {
            std::vector<std::vector<int>> e(n + 1);
            std::vector<int> degree(n + 1);

            {
                // (value, index)
                std::set<std::pair<int64, int>> st;
    
                for (int i = 1; i <= n; ++i)
                {
                    int cnt = 0;
    
                    for (auto it = st.begin(); cnt < 3 and it != st.end(); ++cnt, ++it)
                    {
                        if (v[i] - it->first >= g)
                        {
                            e[i].push_back(it->second);
                            e[it->second].push_back(i);
    
                            ++degree[i];
                            ++degree[it->second];
                        }
                    }
    
                    st.insert({v[i], i});
                }
            }

            std::set<int> set;
            std::vector<bool> contains(n + 1);

            auto get_set = [&](const auto& self, int u) -> void
            {
                if (contains[u])
                {
                    return;
                }

                contains[u] = true;

                set.insert(u);

                for (int i : e[u])
                {
                    self(self, i);
                }

                return;
            };

            auto attempt = [&](int u) -> bool
            {
                auto find = [&, vis = std::set<int>()](auto& self, int u, int root) mutable -> bool
                {
                    if (degree[u] >= 2)
                    {
                        return true;
                    }

                    vis.insert(u);

                    for (int i : e[u] | std::views::filter([&](int i) -> bool { return not vis.contains(i) and i != root; }))
                    {
                        if (self(self, i, root))
                        {
                            return true;
                        }
                    }

                    return false;
                };

                bool found = false;

                for (int i : e[u])
                {
                    --degree[i];
                }
                
                for (int i : e[u])
                {
                    found = found or find(find, i, u);
                }

                for (int i : e[u])
                {
                    ++degree[i];
                }

                return found;
            };

            int cnt = 0;

            for (int u = 1; u <= n; ++u)
            {
                if (contains[u])
                {
                    continue;
                }

                get_set(get_set, u);

                if (set.size() >= 3)
                {
                    if (++cnt == 2)
                    {
                        return true;
                    }

                    bool can = true;

                    for (int i : set)
                    {
                        if (not attempt(i))
                        {
                            can = false;
                        }
                    }

                    if (can)
                    {
                        return true;
                    }
                }

                set.clear();
            }

            return false;
        };

        int64 l = -1e10, r = 1e10, mid;

        while (r - l > 1)
        {
            mid = (l + r) / 2;

            if (check(mid))
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }

        std::cout << l << '\n';
    }

    return 0;
}