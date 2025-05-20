/**
 * The 2023 Guangdong Provincial Collegiate Programming Contest
 * 
 * => K. Peg Solitaire ( @c Rating )
 * 
 * -> https://codeforces.com/gym/104369/problem/K
 * 
 * Submissions ~> https://codeforces.com/gym/104369/submission/319524177 By huanhuanonly
 * 
 * @b Dfs
 * 
 * ----May 14, 2025 [19h:38m:55s]----
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
        int n, m, k;
        std::cin >> n >> m >> k;

        std::vector<std::string> v(n, std::string(m, 0));

        for (int i = 0; i < k; ++i)
        {
            int x, y;
            std::cin >> x >> y;

            v[x - 1][y - 1] = 1;
        }

        int ans = k;

        auto dfs = [&](const auto& self, std::vector<std::string> mp) -> void
        {
            bool has = false;

            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m - 1; ++j)
                {
                    if (mp[i][j] and mp[i][j + 1])
                    {
                        if (j + 2 < m and not mp[i][j + 2])
                        {
                            has = true;
                            
                            mp[i][j] = mp[i][j + 1] = 0;
                            mp[i][j + 2] = 1;
                            
                            self(self, mp);
                            
                            mp[i][j] = mp[i][j + 1] = 1;
                            mp[i][j + 2] = 0;
                        }
                        
                        if (j - 1 >= 0 and not mp[i][j - 1])
                        {
                            has = true;
                            
                            mp[i][j] = mp[i][j + 1] = 0;
                            mp[i][j - 1] = 1;
                            
                            self(self, mp);
                            
                            mp[i][j] = mp[i][j + 1] = 1;
                            mp[i][j - 1] = 0;
                        }
                    }
                }
            }
            
            for (int j = 0; j < m; ++j)
            {
                for (int i = 0; i < n - 1; ++i)
                {
                    if (mp[i][j] and mp[i + 1][j])
                    {
                        if (i + 2 < n and not mp[i + 2][j])
                        {
                            has = true;
                            
                            mp[i][j] = mp[i + 1][j] = 0;
                            mp[i + 2][j] = 1;
                            
                            self(self, mp);
                            
                            mp[i][j] = mp[i + 1][j] = 1;
                            mp[i + 2][j] = 0;
                        }
                        
                        if (i - 1 >= 0 and not mp[i - 1][j])
                        {
                            has = true;

                            mp[i][j] = mp[i + 1][j] = 0;
                            mp[i - 1][j] = 1;
                            
                            self(self, mp);
                            
                            mp[i][j] = mp[i + 1][j] = 1;
                            mp[i - 1][j] = 0;
                        }
                    }
                }
            }
            
            if (not has)
            {
                int cnt = 0;

                for (int i = 0; i < n; ++i)
                {
                    cnt += std::ranges::count(mp[i], 1);
                }

                ans = std::min(ans, cnt);
            }
        };

        dfs(dfs, v);

        std::cout << ans << '\n';
    }

    return 0;
}