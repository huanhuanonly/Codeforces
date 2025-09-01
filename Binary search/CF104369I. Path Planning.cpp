/**
 * The 2023 Guangdong Provincial Collegiate Programming Contest
 * 
 * => I. Path Planning
 * 
 * -> https://codeforces.com/gym/104369/problem/I
 * 
 * Submissions ~> https://codeforces.com/gym/104369/submission/319515688 By huanhuanonly
 * 
 * @b Binary-search
 * 
 * ----May 14, 2025 [19h:41m:04s]----
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

#ifdef __localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int _;
    std::cin >> _;

    while (_--)
    {
        int n, m;
        std::cin >> n >> m;

        std::vector<std::pair<int, int>> pos(n * m);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int v;
                std::cin >> v;

                pos[v] = {i, j};
            }
        }

        std::set<std::pair<int, int>> st;

        int i = 0;

        for (; i < pos.size(); ++i)
        {
            auto it = st.upper_bound(pos[i]);

            if ((it == st.end() or pos[i].second <= it->second) and (it == st.begin() or pos[i].second >= std::prev(it)->second))
            {
                st.insert(pos[i]);
            }
            else
            {
                break;
            }
        }

        std::cout << i << '\n';
    }

    return 0;
}