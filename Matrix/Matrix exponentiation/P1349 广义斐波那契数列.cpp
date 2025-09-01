/**
 * => P1349 广义斐波那契数列 ( @c 普及+/提高 )
 * 
 * -> https://www.luogu.com.cn/problem/P1349
 * 
 * Submissions ~> https://www.luogu.com.cn/record/188134839 By huanhuanonly
 * 
 * @b Matrix-exponentiation
 * 
 * ----November 11, 2024 [16h:08m:41s]----
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

template<typename _Tp, _Tp _Mod = std::numeric_limits<_Tp>::max(),
         typename _Enable = std::void_t<decltype(std::declval<_Tp>() % std::declval<_Tp>())>>
class Mod
{
public:
    
    using value_type = _Tp;

    static_assert(std::is_same_v<_Enable, std::void_t<>>,
                    "The last template parameter is only used to restrict the _Tp.");

    Mod(value_type __value = value_type{}) : _M_value(__value % _S_mod) { }

    Mod& set_mod(value_type __mod) noexcept
    { _S_mod = __mod; _M_value %= __mod; }

    static void init_mod(value_type __mod) noexcept
    { _S_mod = __mod; }

    static constexpr value_type mod() noexcept
    { return _S_mod; }

    template<typename _ItTp, _ItTp _ItMod>
    std::strong_ordering operator<=>(Mod<_ItTp, _ItMod> __it) const noexcept
    { return _M_value <=> __it._M_value; }

    operator value_type() const noexcept
    { return _M_value; }
    
    operator bool() const noexcept
    { return static_cast<bool>(_M_value); }

    Mod operator~() const noexcept
    { return Mod(~_M_value); }

    Mod operator!() const noexcept
    { return Mod(!_M_value); }

    Mod operator-() const noexcept
    { return Mod(-_M_value); }

    constexpr value_type operator*() const noexcept
    { return _M_value; }

    constexpr value_type value() const noexcept
    { return _M_value; }

    Mod abs() const noexcept
    { return Mod(std::abs(_M_value)); }

    template<typename _ItTp, _ItTp _ItMod>
    Mod operator+(Mod<_ItTp, _ItMod> __it) const noexcept
    { return Mod(_M_value + __it._M_value); }

    template<typename _ItTp, _ItTp _ItMod>
    Mod operator-(Mod<_ItTp, _ItMod> __it) const noexcept
    { return Mod(_M_value - __it._M_value % _S_mod + _S_mod); }

    template<typename _ItTp, _ItTp _ItMod>
    Mod operator*(Mod<_ItTp, _ItMod> __it) const noexcept
    { return _S_quick_mul(*this, __it); }

    template<typename _ItTp, _ItTp _ItMod>
    Mod operator/(Mod<_ItTp, _ItMod> __it) const noexcept
    { return Mod(_M_value * __it.pow(_S_mod - 2)); }

    template<typename _ItTp, _ItTp _ItMod>
    Mod operator%(Mod<_ItTp, _ItMod> __it) const noexcept
    { return Mod(_M_value % __it._M_value); }

    template<typename _ValueType>
    std::enable_if_t<std::is_integral_v<_ValueType>, Mod> pow(_ValueType __it) noexcept
    {
        Mod ans(1);
        for (; __it; *this *= *this, __it >>= 1)
            if (__it & 1)
                ans *= *this;
        return ans;
    }

    template<typename _ValueType, typename = std::void_t<decltype(std::declval<value_type>() & std::declval<_ValueType>())>>
    Mod operator&(_ValueType __it) const noexcept
    { return Mod(_M_value & __it); }

    template<typename _ValueType, typename = std::void_t<decltype(std::declval<value_type>() | std::declval<_ValueType>())>>
    Mod operator|(_ValueType __it) const noexcept
    { return Mod(_M_value | __it); }

    template<typename _ValueType, typename = std::void_t<decltype(std::declval<value_type>() ^ std::declval<_ValueType>())>>
    Mod operator^(_ValueType __it) const noexcept
    { return Mod(_M_value ^ __it); }

    template<typename _ValueType, typename = std::void_t<decltype(std::declval<value_type>() << std::declval<_ValueType>())>>
    Mod operator<<(_ValueType __it) const noexcept
    { return Mod(_M_value << __it); }

    template<typename _ValueType, typename = std::void_t<decltype(std::declval<value_type>() >> std::declval<_ValueType>())>>
    Mod operator>>(_ValueType __it) const noexcept
    { return Mod(_M_value >> __it); }


    template<typename _ItTp, _ItTp _ItMod>
    Mod& operator+=(Mod<_ItTp, _ItMod> __it) noexcept
    { return (_M_value += __it._M_value) %= _S_mod, *this; }

    template<typename _ItTp, _ItTp _ItMod>
    Mod& operator-=(Mod<_ItTp, _ItMod> __it) noexcept
    { return ((_M_value -= __it._M_value % _S_mod) += _S_mod) %= _S_mod, *this; }

    template<typename _ItTp, _ItTp _ItMod>
    Mod& operator*=(Mod<_ItTp, _ItMod> __it) const noexcept
    { return *this = _S_quick_mul(*this, __it); }

    template<typename _ItTp, _ItTp _ItMod>
    Mod& operator/=(Mod<_ItTp, _ItMod> __it) const noexcept
    { return (_M_value *= __it.pow(_S_mod - 2)._M_value) %= _S_mod, *this; }

    template<typename _ItTp, _ItTp _ItMod>
    Mod& operator%=(Mod<_ItTp, _ItMod> __it) const noexcept
    { return _M_value %= __it._M_value, *this; }

    template<typename _ValueType>
    std::enable_if_t<std::is_integral_v<_ValueType>, Mod&> pow_equal(_ValueType __it) noexcept
    { return *this = pow(__it); }


    template<typename _ValueType, typename = std::void_t<decltype(std::declval<value_type>() & std::declval<_ValueType>())>>
    Mod& operator&=(_ValueType __it) noexcept
    { return _M_value = (_M_value & __it) % _S_mod, *this; }

    template<typename _ValueType, typename = std::void_t<decltype(std::declval<value_type>() | std::declval<_ValueType>())>>
    Mod& operator|=(_ValueType __it) noexcept
    { return _M_value = (_M_value | __it) % _S_mod, *this; }

    template<typename _ValueType, typename = std::void_t<decltype(std::declval<value_type>() ^ std::declval<_ValueType>())>>
    Mod& operator^=(_ValueType __it) noexcept
    { return _M_value = (_M_value ^ __it) % _S_mod, *this; }

    template<typename _ValueType, typename = std::void_t<decltype(std::declval<value_type>() << std::declval<_ValueType>())>>
    Mod& operator<<=(_ValueType __it) noexcept
    { return _M_value = (_M_value << __it) % _S_mod, *this; }
    
    template<typename _ValueType, typename = std::void_t<decltype(std::declval<value_type>() >> std::declval<_ValueType>())>>
    Mod& operator>>=(_ValueType __it) noexcept
    { return _M_value = (_M_value >> __it) % _S_mod, *this; }


    Mod& operator++() noexcept
    { return _M_value += 1, *this; }

    Mod operator++(int) noexcept
    { return _M_value += 1, Mod(_M_value - 1); }

    Mod& operator--() noexcept
    { return _M_value -= 1, *this; }

    Mod operator--(int) noexcept
    { return _M_value -= 1, Mod(_M_value + 1); }


    template<typename _ItTp, _ItTp _ItMod>
    friend std::istream& operator>>(std::istream& __is, Mod<_ItTp, _ItMod>& __this) noexcept;

    template<typename _ItTp, _ItTp _ItMod>
    friend std::ostream& operator<<(std::ostream& __os, Mod<_ItTp, _ItMod> __this) noexcept;

    template<typename _ItTp, _ItTp _ItMod, typename>
    friend class Mod;

private:

    static Mod _S_quick_mul(Mod __fv, Mod __sv)
    {
        Mod ans(0);
        for (; __sv; __fv += __fv, __sv >>= 1)
            if (__sv._M_value & 1)
                ans += __fv;
        return ans;
    }

protected:

    value_type _M_value;
    static value_type _S_mod;
};

template<typename _ItTp, _ItTp _ItMod>
std::istream& operator>>(std::istream& __is, Mod<_ItTp, _ItMod>& __this) noexcept
{ return __is >> __this._M_value; }

template<typename _ItTp, _ItTp _ItMod>
std::ostream& operator<<(std::ostream& __os, Mod<_ItTp, _ItMod> __this) noexcept
{ return __os << __this._M_value; }


template<typename _Tp, _Tp _Mod, typename _Enable>
Mod<_Tp, _Mod, _Enable>::value_type Mod<_Tp, _Mod, _Enable>::_S_mod = _Mod;

template<typename _Tp, uint32 _RowCount, uint32 _ColumnCount>
class Matrix
{
public:
    
    using value_type = _Tp;
    using pointer = _Tp*;
    using const_pointer = const _Tp*;
    using reference = _Tp&;
    using const_reference = const _Tp&;

    Matrix() = delete;

    // Do nothing
    Matrix(std::nullptr_t) noexcept
    { }

    Matrix(_Tp __value = _Tp{}) noexcept : Matrix(nullptr)
    { fill(__value); }

    template<typename _Generator = _Tp (*)(uint32, uint32)>
    Matrix(_Generator __er) : Matrix(nullptr)
    { fill(__er); }

    Matrix(std::initializer_list<std::initializer_list<value_type>> __init) : Matrix(nullptr)
    {
        for_each([this, &__init](uint32 i, uint32 j) -> void
        {
            _M_matrix[i][j] = (
                i < __init.size() and j < (__init.begin() + i)->size()
                ? *((__init.begin() + i)->begin() + j)
                : value_type(0));
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

    Matrix operator+(const Matrix& __it) const noexcept
    {
        Matrix res(nullptr);

        for_each([this, &__it, &res](uint32 i, uint32 j) -> void
        {
            res[i][j] = _M_matrix[i][j] + __it._M_matrix[i][j];
        });

        return res;
    }

    Matrix& operator+=(const Matrix& __it) noexcept
    {
        for_each([this, &__it](uint32 i, uint32 j) -> void
        {
            _M_matrix[i][j] += __it._M_matrix[i][j];
        });
    }

    Matrix operator-(const Matrix& __it) const noexcept
    {
        Matrix res(nullptr);

        for_each([this, &__it, &res](uint32 i, uint32 j) -> void
        {
            res[i][j] = _M_matrix[i][j] - __it._M_matrix[i][j];
        });

        return res;
    }

    Matrix& operator-=(const Matrix& __it) noexcept
    {
        for_each([this, &__it](uint32 i, uint32 j) -> void
        {
            _M_matrix[i][j] -= __it._M_matrix[i][j];
        });
    }

    template<uint32 _ItsColumnCount>
    Matrix operator*(const Matrix<_Tp, _ColumnCount, _ItsColumnCount>& __it) const
    {
        Matrix res(nullptr);

        for (uint32 i = 0; i < _RowCount; ++i)
        {
            for (uint32 j = 0; j < _ItsColumnCount; ++j)
            {
                for (uint32 k = 0; k < _ColumnCount; ++k)
                {
                    res._M_matrix[i][j] += _M_matrix[i][k] * __it._M_matrix[k][j];
                }
            }
        }

        return res;
    }


    template<uint32 _ItsColumnCount>
    Matrix& operator*=(const Matrix<_Tp, _ColumnCount, _ItsColumnCount>& __it)
    {
        swap(*this * __it);
        return *this;
    }

    template<typename _ValueType>
    std::enable_if_t<std::is_integral_v<_ValueType>, Matrix&> operator^=(_ValueType __pow)
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

    template<typename _ItsTp, uint32 _ItsRowCount, uint32 _ItsColumnCount>
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

    uint64 p, q, a1, a2, n, m;
    std::cin >> p >> q >> a1 >> a2 >> n >> m;

    if (n == 1)
    {
        std::cout << a1;
        return 0;
    }
    else if (n == 2)
    {
        std::cout << a2;
        return 0;
    }

    Mod<uint64>::init_mod(m);

    Matrix<Mod<uint64>, 1, 2> fib{{a2, a1}};
    Matrix<Mod<uint64>, 2, 2> x{{p, 1}, {q, 0}};

    x ^= n - 2;
    std::cout << (fib * x).at(0, 0);

    return 0;
}