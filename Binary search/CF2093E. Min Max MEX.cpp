/**
 * Codeforces Round 1016 (Div. 3)
 * 
 * => E. Min Max MEX ( @c 1500 )
 * 
 * -> https://codeforces.com/contest/2093/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2093/submission/314956185 By huanhuanonly
 * 
 * @b Binary-search
 * 
 * ----April 11, 2025 [12h:46m:40s]----
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
        int n, k;
        std::cin >> n >> k;

        std::vector<int> v(n);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> v[i];
        }

        auto check = [&](int mid) -> bool
        {
            int ck = 0;
            int mex = 0;

            std::set<int> que;

            for (int i = 0; i < n; ++i)
            {
                if (v[i] >= mex)
                {
                    que.insert(v[i]);
                }

                while (not que.empty() and *que.begin() == mex)
                {
                    que.erase(que.begin());

                    if (++mex >= mid)
                    {
                        if (++ck == k)
                        {
                            return true;
                        }
                        
                        mex = 0;
                        que.clear();
                        break;
                    }
                }
            }

            return false;
        };

        // If `r` is set to about 1e9, you will receive a TLE!
        int l = 0, r = 2e5 + 1, mid;

        while (r - l > 1)
        {
            mid = l + r >> 1;

            if (check(mid))
                l = mid;
            else
                r = mid;
        }

        std::cout << l << '\n';
    }

    return 0;
}