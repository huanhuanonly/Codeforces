/**
 * Ｓｋｙ Inc, Programming Contest 2026 (AtCoder Beginner Contest 455)
 * 
 * => E - Unbalanced ABC Substrings ( @c 450 )
 * 
 * -> https://atcoder.jp/contests/abc455/tasks/abc455_e
 * 
 * Submissions ~> https://atcoder.jp/contests/abc455/submissions/75274555 By huanhuanonly
 * 
 * @b Combinatorics ( @a inclusion-exclusion-principle )
 * @b Prefix-sum
 * 
 * ----April 25, 2026 [22h:12m:38s]----
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

    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;

    std::vector<std::array<int, 3>> cnt(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        cnt[i] = cnt[i - 1];
        ++cnt[i][s[i - 1] - 'A'];
    }

    std::map<int, int> map_ab{{0, 1}}, map_ac{{0, 1}}, map_bc{{0, 1}};
    std::map<std::pair<int, int>, int> map_abc{{{0, 0}, 1}};

    uint64 cnt_ab = 0, cnt_ac = 0, cnt_bc = 0, cnt_abc = 0;

    for (int i = 1; i <= n; ++i)
    {
        cnt_ab += map_ab[cnt[i][0] - cnt[i][1]]++;
        cnt_ac += map_ac[cnt[i][0] - cnt[i][2]]++;
        cnt_bc += map_bc[cnt[i][1] - cnt[i][2]]++;
        cnt_abc += map_abc[{cnt[i][0] - cnt[i][1], cnt[i][0] - cnt[i][2]}]++;
    }

    std::cout << uint64(n) * (n + 1) / 2 - (cnt_ab + cnt_ac + cnt_bc - 2 * cnt_abc) << '\n';

    return 0;
}