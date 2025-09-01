/**
 * => P1962 斐波那契数列 ( @c 普及+/提高 )
 * 
 * -> https://www.luogu.com.cn/problem/P1962
 * 
 * Submissions ~> https://www.luogu.com.cn/record/185929353 By huanhuanonly
 * 
 * @b Matrix-exponentiation
 * 
 * ----October 31, 2024 [16h:34m:50s]----
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

template<typename _Tp, uint32 _RowCount, uint32 _ColumnCount, _Tp _Mod = static_cast<_Tp>(1e9) + 7,
         typename = std::enable_if<not std::is_class_v<_Tp>>::type>
class Matrix
{
public:
    
    using value_type = _Tp;
    using pointer = _Tp*;
    using const_pointer = const _Tp*;
    using reference = _Tp&;
    using const_reference = const _Tp&;
    
    Matrix(_Tp __value = _Tp{}) noexcept
    { fill(__value); }

    template<typename _Generator = _Tp (*)(uint32, uint32)>
    Matrix(_Generator __er)
    { fill(__er); }

    // Do nothing
    Matrix(std::nullptr_t)
    { }

    Matrix(std::initializer_list<std::initializer_list<_Tp>> __init)
    {
        for_each([this, &__init](uint32 i, uint32 j) -> void
        {
            _M_matrix[i][j] = (
                i < __init.size() and j < (__init.begin() + i)->size()
                ? *((__init.begin() + i)->begin() + j)
                : 0);
        });
    }

    void fill(value_type __value) noexcept
    {
        for_each([this, &__value](uint32 i, uint32 j) -> void
        {
            _M_matrix[i][j] = __value;
        });
    }

    template<typename _Generator = value_type (*)(uint32, uint32)>
    void fill(_Generator __er)
    {
        for_each([this, &__er](uint32 i, uint32 j) -> void
        {
            _M_matrix[i][j] = __er(i, j);
        });
    }

    Matrix operator+(const Matrix& __it) noexcept
    {
        Matrix res;

        for_each([this, &__it, &res](uint32 i, uint32 j) -> void
        {
            res[i][j] = (_M_matrix[i][j] + __it._M_matrix[i][j]) % _Mod;
        });

        return res;
    }

    Matrix& operator+=(const Matrix& __it) noexcept
    {
        for_each([this, &__it](uint32 i, uint32 j) -> void
        {
            (_M_matrix[i][j] += __it._M_matrix[i][j]) %= _Mod;
        });
    }

    Matrix operator-(const Matrix& __it) noexcept
    {
        Matrix res;

        for_each([this, &__it, &res](uint32 i, uint32 j) -> void
        {
            res[i][j] = (_M_matrix[i][j] + _Mod - __it._M_matrix[i][j]) % _Mod;
        });

        return res;
    }

    Matrix& operator-=(const Matrix& __it) noexcept
    {
        for_each([this, &__it](uint32 i, uint32 j) -> void
        {
            ((_M_matrix[i][j] += _Mod) -= __it._M_matrix[i][j]) %= _Mod;
        });
    }

    template<uint32 _ItsColumnCount>
    Matrix operator*(const Matrix<_Tp, _ColumnCount, _ItsColumnCount, _Mod>& __it)
    {
        Matrix res;

        for (uint32 i = 0; i < _RowCount; ++i)
        {
            for (uint32 j = 0; j < _ItsColumnCount; ++j)
            {
                for (uint32 k = 0; k < _ColumnCount; ++k)
                {
                    res._M_matrix[i][j] += _M_matrix[i][k] * __it._M_matrix[k][j] % _Mod;
                    res._M_matrix[i][j] %= _Mod;
                }
            }
        }

        return res;
    }


    template<uint32 _ItsColumnCount>
    Matrix& operator*=(const Matrix<_Tp, _ColumnCount, _ItsColumnCount, _Mod>& __it)
    {
        swap(*this * __it);
        return *this;
    }

    Matrix& operator^=(_Tp __pow)
    {
        Matrix res([](uint32 i, uint32 j) -> _Tp { return static_cast<_Tp>(i == j); });

        for (; __pow; __pow >>= 1, *this *= *this)
        {
            if (__pow & 1)
            {
                res *= *this;
            }
        }

        swap(std::move(res));
        return *this;
    }

    constexpr reference at(uint32 __rowNumber, uint32 __colNumber) noexcept
    { return _M_matrix[__rowNumber][__colNumber]; }

    constexpr value_type at(uint32 __rowNumber, uint32 __colNumber) const noexcept
    { return _M_matrix[__rowNumber][__colNumber]; }

    void swap(Matrix& __it) noexcept
    {
        for_each([this, &__it](uint32 i, uint32 j) -> void
        {
            _M_matrix[i][j] ^= __it._M_matrix[i][j];
            __it._M_matrix[i][j] ^= _M_matrix[i][j];
            _M_matrix[i][j] ^= __it._M_matrix[i][j];
        });
    }

    void swap(Matrix&& __it) noexcept
    {
        for_each([this, &__it](uint32 i, uint32 j) -> void
        {
            _M_matrix[i][j] = __it._M_matrix[i][j];
        });
    }

    constexpr uint32 row_count() const noexcept
    { return _RowCount; }

    constexpr uint32 column_count() const noexcept
    { return _ColumnCount; }

    constexpr value_type mod() const noexcept
    { return _Mod; }

    template<typename _Function = void (*)(uint32, uint32)>
    constexpr void for_each(_Function __func)
    {
        for (uint32 i = 0; i < _RowCount; ++i)
        {
            for (uint32 j = 0; j < _ColumnCount; ++j)
            {
                __func(i, j);
            }
        }
    }

    template<typename _ItsTp, uint32 _ItsRowCount, uint32 _ItsColumnCount, _ItsTp _ItsMod, typename>
    friend class Matrix;

protected:

    value_type _M_matrix[_RowCount][_ColumnCount];
};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    uint64 n;
    std::cin >> n;

    if (n <= 2)
    {
        std::cout << 1;
    }
    else
    {
        Matrix<uint64, 1, 2> fib{{1, 1}};
        Matrix<uint64, 2, 2> x{{1, 1}, {1, 0}};

        x ^= n - 2;
        fib *= x;

        std::cout << fib.at(0, 0);
    }

    return 0;
}