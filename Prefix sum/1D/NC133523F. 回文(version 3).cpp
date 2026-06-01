/**
 * 牛客周赛 Round 141
 *
 * => F-回文(version 3) ( @c 1900 )
 *
 * -> https://ac.nowcoder.com/acm/contest/133523/F
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83431898 By huanhuanonly
 *
 * @b Prefix-sum
 *
 * ----April 27, 2026 [19h:18m:21s]----
*/

// \sum_{i=1}^{|P|}\sum_{j=i+1}^{|P|}\left( P_j - P_i - 1 \right)
//
// \begin{aligned}
//     &\sum_{i=L}^{R}\sum_{j=i+1}^{R}\left( P_j - P_i - 1 \right) \\
//     =&\sum_{i=L}^{R}
//     \left(
//         \sum_{j=i+1}^{R}{P_j} - \sum_{j=i+1}^{R}(P_i + 1)
//     \right) \\
//     =&\sum_{i=L}^{R}
//     \left(
//         \sum_{j=i+1}^{R}{P_j} - (R - i) \cdot (P_i + 1)
//     \right) \\
//     &\text{Let } S_i = \sum_{j=1}^{i}{P_j} \\
//     =&\sum_{i=L}^{R}
//     \left(
//         S_{R} - S_i - (R - i) \cdot (P_i + 1)
//     \right) \\
//     =&\sum_{i=L}^{R}{S_R} - \sum_{i=L}^{R}{S_i} - \sum_{i=L}^{R}(R \cdot (P_i + 1)) + \sum_{i=L}^{R}(i \cdot (P_i + 1)) \\
//     &\text{Let } Len = R - L + 1 \\
//     =&Len \cdot S_R - \sum_{i=L}^{R}{S_i} - R\sum_{i=L}^{R}(P_i + 1) + \sum_{i=L}^{R}(i \cdot (P_i + 1)) \\
//     =&Len \cdot S_R - \sum_{i=L}^{R}{S_i} - R\sum_{i=L}^{R}{P_i} - R\sum_{i=L}^{R}{1} + \sum_{i=L}^{R}(i \cdot (P_i + 1)) \\
//     =&Len \cdot S_R - \sum_{i=L}^{R}{S_i} - R \cdot (S_R - S_{L-1}) - R \cdot Len + \sum_{i=L}^{R}(i \cdot (P_i + 1))
// \end{aligned}

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

    int64 n, q;
    std::cin >> n >> q;

    std::string s;
    std::cin >> s;

    std::vector<std::array<int64, 26>> precnt(n + 1);

    std::array<std::vector<int64>, 26> pos;
    std::array<std::vector<int64>, 26> presum;
    std::array<std::vector<int64>, 26> presumsum;
    std::array<std::vector<int64>, 26> preipi;

    for (int c = 0; c < 26; ++c)
    {
        pos[c].push_back(0);
    }

    for (int64 i = 1; i <= n; ++i)
    {
        const int c = s[i - 1] - 'a';

        precnt[i] = precnt[i - 1];
        ++precnt[i][c];

        pos[c].push_back(i);
    }

    for (int c = 0; c < 26; ++c)
    {
        const int64 len = pos[c].size();

        presum[c].resize(len);
        presumsum[c].resize(len);
        preipi[c].resize(len);

        std::partial_sum(pos[c].begin(), pos[c].end(), presum[c].begin());
        std::partial_sum(presum[c].begin(), presum[c].end(), presumsum[c].begin());

        for (int64 i = 1; i < len; ++i)
        {
            preipi[c][i] = i * (pos[c][i] + 1);
        }

        std::partial_sum(preipi[c].begin(), preipi[c].end(), preipi[c].begin());
    }

    while (q--)
    {
        int l, r, x;
        std::cin >> l >> r >> x;

        if (x == 1)
        {
            std::cout << r - l + 1 << '\n';
        }
        else if (x == 2)
        {
            int64 sum = 0;

            for (int i = 0; i < 26; ++i)
            {
                const auto cnt = precnt[r][i] - precnt[l - 1][i];
                sum += cnt * (cnt - 1) / 2;
            }

            std::cout << sum << '\n';
        }
        else
        {
            int64 sum = 0;

            for (int c = 0; c < 26; ++c)
            {
                const auto& p = pos[c];

                const auto L = std::ranges::lower_bound(p, l) - p.begin();
                const auto R = std::ranges::upper_bound(p, r) - p.begin() - 1;

                const int64 len = R - L + 1;

                sum += len * presum[c][R] - (presumsum[c][R] - presumsum[c][L - 1]) - R * (presum[c][R] - presum[c][L - 1]) - R * len + (preipi[c][R] - preipi[c][L - 1]);
            }

            std::cout << sum << '\n';
        }
    }

    return 0;
}