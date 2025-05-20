/**
 * The 2023 Guangdong Provincial Collegiate Programming Contest
 * 
 * => B. Base Station Construction
 * 
 * -> https://codeforces.com/gym/104369/problem/B
 * 
 * Submissions ~> https://codeforces.com/gym/104369/submission/319633372 By huanhuanonly
 * 
 * @b Linear-DP
 * 
 * ----May 14, 2025 [19h:34m:03s]----
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
        int n;
        std::cin >> n;

        std::vector<uint64> v(n + 2);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
        }

        std::vector<int> mx(n + 2);
        
        std::multiset<uint64> st{0};
        int pos = 0;

        int m;
        std::cin >> m;

        for (int i = 0; i < m; ++i)
        {
            int l, r;
            std::cin >> l >> r;

            mx[r] = std::max(mx[r], l);
        }

        std::vector<uint64> dp(n + 2);

        for (int i = 1; i <= n + 1; ++i)
        {
            dp[i] = *st.begin() + v[i];

            st.insert(dp[i]);

            if (mx[i])
            {
                while (pos < mx[i])
                {
                    st.extract(dp[pos++]);
                }
            }
        }

        std::cout << dp.back() << '\n';
    }

    return 0;
}