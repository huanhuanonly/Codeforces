/**
 * Codeforces Round 1059 (Div. 3)
 * 
 * => F. Beautiful Intervals ( @c 2100 )
 * 
 * -> https://codeforces.com/contest/2162/problem/F
 * 
 * Submissions ~> https://codeforces.com/contest/2162/submission/344820860 By huanhuanonly
 * 
 * @b Constructive and @b Classification-discussion
 * 
 * ----October 20, 2025 [15h:17m:08s]----
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
        int n, m;
        std::cin >> n >> m;

        std::vector<std::pair<int, int>> v(m);

        std::vector<int> cnt(n + 2);

        std::set<int> ls, rs;

        for (int i = 0; i < m; ++i)
        {
            std::cin >> v[i].first >> v[i].second;
            
            ++cnt[v[i].first];
            --cnt[v[i].second + 1];

            ls.insert(v[i].first);
            rs.insert(v[i].second);
        }

        std::ranges::sort(v);
        v.erase(std::ranges::unique(v).begin(), v.end());

        std::partial_sum(cnt.begin(), cnt.end(), cnt.begin());

        std::vector<int> ans(n, -1);

        int cur = 1;

        // 0
        if (auto fit = std::ranges::find(cnt, m); fit != cnt.end())
        {
            ans[fit - cnt.begin() - 1] = 0;
            cur = 0;
        }
        else
        {
            // 1
            bool found = false;

            for (int i = 1; i < n; ++i)
            {
                if (not rs.contains(i))
                {
                    ans[i] = 1;
                    ans[i - 1] = 0;
                    
                    found = true;
                    break;
                }
                else if (not ls.contains(i + 1))
                {
                    ans[i] = 0;
                    ans[i - 1] = 1;

                    found = true;
                    break;
                }
            }

            // 2
            if (not found)
            {
                ans[0] = 0;
                ans[n - 1] = 1;
            }
        }

        for (int i : ans)
        {
            if (~i)
            {
                std::cout << i << ' ';
            }
            else
            {
                std::cout << ++cur << ' ';
            }
        }

        std::cout.put('\n');
    }

    return 0;
}