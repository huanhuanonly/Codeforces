/**
 * The 2025 ICPC Asia East Continent Online Contest (I)
 * 
 * => A. Who Can Win
 * 
 * -> https://qoj.ac/contest/2513/problem/14301
 * 
 * Submissions ~> https://qoj.ac/submission/2210851 By huanhuanonly
 * 
 * @b Implementation
 * 
 * ----April 09, 2026 [15h:54m:23s]----
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

#if defined(__SIZEOF_INT128__)
using int128 = __int128;
using uint128 = unsigned __int128;
#endif

using real32 = float;
using real64 = double;

#if defined(__SIZEOF_FLOAT80__)
using real80 = __float80;
#endif

#if defined(__SIZEOF_FLOAT128__)
using real128 = __float128;
#endif

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

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

        enum Status
        {
            Rejected = 0,
            Accepted,
            Unknown
        };

        struct Data
        {
            std::string name;
            char pid;
            int time;
            std::string result;
        };

        std::vector<Data> data(n);

        for (auto& [name, pid, time, result] : data)
        {
            std::cin >> name >> pid >> time >> result;
            pid -= 'A';
        }
        
        std::ranges::sort(data, {}, &Data::time);

        std::map<std::string, std::array<std::pair<Status, int>, 26>> map;
        
        for (const auto& [name, pid, time, result] : data)
        {
            auto& team = map[name];

            if (team[pid].first == Rejected)
            {
                if (result[0] == 'A')
                {
                    team[pid].first = Accepted;
                    team[pid].second += time;
                }
                else if (result[0] == 'R')
                {
                    team[pid].second += 20;
                }
                else if (result[0] == 'U')
                {
                    team[pid].first = Unknown;
                    team[pid].second += time;
                }
            }
        }

        struct Team
        {
            std::string name;
            std::array<std::pair<Status, int>, 26> prob;

            bool comp_flag;

            auto proj() const
            {
                int cnt = 0;
                int tot = 0;

                for (const auto& i : prob)
                {
                    if (i.first == Accepted or (comp_flag and i.first == Unknown))
                    {
                        ++cnt;
                        tot += i.second;
                    }
                }

                return std::pair(cnt, -tot);
            }
        };

        std::vector<Team> teams(map.size());

        for (auto [ait, bit] = std::tuple(teams.begin(), map.begin()); ait != teams.end(); ++ait, ++bit)
        {
            ait->name = bit->first;
            ait->prob = bit->second;
        }

        std::ranges::sort(teams, {}, &Team::proj);

        std::vector<std::string> ans;
        ans.reserve(map.size());

        for (const auto& i : teams)
        {
            auto j = i;
            j.comp_flag = true;

            if (j.proj() >= teams.back().proj())
            {
                ans.push_back(j.name);
            }
        }

        std::ranges::sort(ans);

        bool first = true;

        for (const auto& i : ans)
        {
            if (not first)
            {
                std::cout.put(' ');
            }

            first = false;
            
            std::cout << i;
        }

        std::cout.put('\n');
    }

    return 0;
}