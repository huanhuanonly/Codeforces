/**
 * Codeforces Round 1012 (Div. 2)
 * 
 * => C. Dining Hall ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/2090/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/2090/submission/317531112 By huanhuanonly
 * 
 * @b Implementation
 * 
 * ----April 28, 2025 [12h:50m:39s]----
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

        std::vector<int> t(n);
        
        for (auto& i : t)
        {
            std::cin >> i;
        }

        struct table
        {
            std::array<std::pair<int, int>, 4> coord;
            std::array<int, 4> dist;
            int idx;

            table(const std::pair<int, int>& __coord)
                : idx{}
            {
                coord[0] = __coord;
                coord[1] = {__coord.first, __coord.second + 1};
                coord[2] = {__coord.first + 1, __coord.second};
                coord[3] = {__coord.first + 1, __coord.second + 1};

                dist[0] = __coord.first + __coord.second;
                dist[1] = dist[2] = dist[0] + 1;
                dist[3] = dist[2] + 3;
            }

            bool operator<(const table& other) const
            {
                if (dist[idx] != other.dist[other.idx])
                {
                    return dist[idx] < other.dist[other.idx];
                }
                else
                {
                    return coord[idx] < other.coord[other.idx];
                }
            }
            
            void println() const
            {
                switch (idx)
                {
                case 0:
                    std::cout << coord[0].first << ' ' << coord[0].second << '\n';
                    break;

                case 1:
                    std::cout << coord[1].first << ' ' << coord[1].second << '\n';
                    break;

                case 2:
                    std::cout << coord[2].first << ' ' << coord[2].second << '\n';
                    break;

                case 3:
                    std::cout << coord[3].first << ' ' << coord[3].second << '\n';
                    break;
                }
            }
        };

        std::set<table> vacant_tables, completely_unoccupied_tables;

        for (int y = 1; vacant_tables.size() < n; y += 3)
        {
            for (int x = 1, ty = y; ty >= 1; x += 3, ty -= 3)
            {
                vacant_tables.insert(table({x, ty}));
                completely_unoccupied_tables.insert(table({x, ty}));
            }
        }

        for (const auto& i : t)
        {
            if (i)
            {
                auto nd = vacant_tables.extract(vacant_tables.begin());
                completely_unoccupied_tables.erase(nd.value());

                nd.value().println();
                
                if (++nd.value().idx < nd.value().dist.size())
                {
                    vacant_tables.insert(std::move(nd));
                }
            }
            else
            {
                auto nd = completely_unoccupied_tables.extract(completely_unoccupied_tables.begin());
                auto ndt = vacant_tables.extract(nd.value());
                
                nd.value().println();
                
                ++nd.value().idx;
                ++ndt.value().idx;

                vacant_tables.insert(std::move(ndt));
            }
        }
    }

    return 0;
}