/**
 * Codeforces Global Round 31 (Div. 1 + Div. 2)
 * 
 * => C. XOR-factorization ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/2180/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/2180/submission/354502644 By huanhuanonly
 * 
 * @b Constructive and @b Bitwise-XOR
 * 
 * ----December 22, 2025 [10h:54m:04s]----
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
        uint64 n, k;
        std::cin >> n >> k;

        if (k & 1)
        {
            for (uint64 i = 0; i < k; ++i)
            {
                std::cout << n << ' ';
            }
        }
        else if (std::popcount(n) == 1)
        {
            std::cout << 0 << ' ';

            for (uint64 i = 0; i < k - 1; ++i)
            {
                std::cout << n << ' ';
            }
        }
        else
        {
            static auto lowbit = [](uint64 x) -> uint64
            {
                return x & -x;
            };

            uint64 a = 0, b = n;

            
            std::vector<uint64> v;
            uint64 front = 0;
            
            for (int i = std::countr_zero(std::bit_floor(n ^ std::bit_floor(n))); i >= 0; --i)
            {
                if (n & (1 << i))
                {
                    if (v.size() < k - 1)
                    {
                        v.push_back(n ^ (1 << i));
                        front |= 1 << i;
                    }
                }
                else
                {
                    std::ranges::transform(v, v.begin(), [i](uint64 x) -> uint64 { return x | (1 << i); });

                    if (v.size() & 1)
                    {
                        front |= 1 << i;
                    }
                }
            }

            v.resize(k - 1, n);

            std::cout << front << ' ';

            for (const uint64& i : v)
            {
                std::cout << i << ' ';
            }
        }

        std::cout.put('\n');
    }

    return 0;
}