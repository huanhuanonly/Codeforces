/**
 * Harbour.Space Scholarship Contest 2023-2024 (Div. 1 + Div. 2)
 * 
 * => D. Matrix Cascade ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/1864/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/1864/submission/324009416 By huanhuanonly
 * 
 * @b Binary-indexed-tree
 * 
 * ----June 12, 2025 [17h:18m:19s]----
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

// Fenwick Tree
template<typename _Tp>
class BinaryIndexedTree
{
public:
    using value_type = _Tp;

    explicit BinaryIndexedTree(std::size_t n) : arr(n) { }

    static constexpr std::size_t lowbit(std::size_t p) { return p & -p; }

    void add(std::size_t p, value_type value)
    {
        while (p < arr.size())
        {
            arr[p] += value;
            p += lowbit(p);
        }
    }

    value_type sum(std::size_t p)
    {
        value_type ans{};
        while (p)
        {
            ans += arr[p];
            p -= lowbit(p);
        }
        return ans;
    }

private:
    std::vector<value_type> arr;
};

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

        std::vector<std::string> v(n);

        for (auto& i : v)
        {
            std::cin >> i;
        }

        BinaryIndexedTree<int> bit(n * 4);
        int cnt = 0;

        for (int c = 0; c < n; ++c)
        {
            int id = c;

            for (int i = 0, j = c; j >= 0; ++i, --j, id -= 2)
            {
                int val = (v[i][j] - '0' + (bit.sum(n * 4 - 1) - bit.sum(id - 1 + n * 2))) & 1;

                if (val)
                {
                    bit.add(id + n * 2, 1);
                    ++cnt;
                }
            }
        }

        for (int r = 1; r < n; ++r)
        {
            int id = n - 1 - r;

            for (int i = r, j = n - 1; i < n; ++i, --j, id -= 2)
            {
                int val = (v[i][j] - '0' + (bit.sum(n * 4 - 1) - bit.sum(id - 1 + n * 2))) & 1;

                if (val)
                {
                    bit.add(id + n * 2, 1);
                    ++cnt;
                }
            }
        }

        std::cout << cnt << '\n';
    }

    return 0;
}