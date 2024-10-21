/**
 * => P3812 【模板】线性基
 * 
 * -> https://www.luogu.com.cn/problem/P3812
 * 
 * @b Xor-space-linear-basis for Maximum XOR sum
 * 
 * See also @link https://oi-wiki.org/math/linear-algebra/basis/
 * See also @link https://www.luogu.com.cn/problem/solution/P3812
*/

#include <bits/stdc++.h>

using uint    = unsigned int;
using llong   = long long int;
using ullong  = unsigned long long int;
using ldouble = long double;

template<typename T>
requires std::integral<T>
class XORSpaceLinearBasis
{
public:

    using value_type = T;

    std::vector<value_type> basis;

    explicit XORSpaceLinearBasis()
        : basis(sizeof(value_type) * 8)
    { }

    void insert(value_type __value) noexcept
    {
        for (int i = static_cast<int>(basis.size()) - 1; i >= 0; --i)
        {
            if ((__value >> i) == 0)
            {
                continue;
            }

            if (basis[i])
            {
                __value ^= basis[i];
            }
            else
            {
                basis[i] = __value;
                break;
            }
        }
    }

    value_type get_max_xor() const noexcept
    {
        value_type max{};

        for (auto i : basis | std::views::reverse)
        {
            max = std::max(max, max ^ i);
        }

        return max;
    }
};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    ullong n;
    std::cin >> n;

    XORSpaceLinearBasis<ullong> lb;

    for (ullong i = 0, v; i < n; ++i)
    {
        std::cin >> v;
        lb.insert(v);
    }

    std::cout << lb.get_max_xor();

    return 0;
}