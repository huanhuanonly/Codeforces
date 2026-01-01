/**
 * Codeforces Round 1051 (Div. 2)
 * 
 * => F. Increasing Xor ( @c 2700 )
 * 
 * -> https://codeforces.com/contest/2143/problem/F
 * 
 * Submissions ~> https://codeforces.com/contest/2143/submission/353663011 By huanhuanonly
 * 
 * @b XOR-basis
 * 
 * ----December 16, 2025 [14h:51m:19s]----
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

inline namespace huanhuanonly
{
template<typename _Tp, typename _St = std::size_t>
requires requires(_Tp __x, _St __n) {
    {__x ^ __x} -> std::same_as<_Tp>;
    {__x & __x} -> std::same_as<_Tp>;
    {__x >> __n} -> std::same_as<_Tp>;
    {__x == __x} -> std::same_as<bool>;
    {__x ^= __x} -> std::same_as<_Tp&>; }
class XorBasis
{
public:

    using value_type = _Tp;
    using size_type  = _St;

    constexpr
    XorBasis() noexcept
        : _M_basis{}, _M_size(0), _M_zero(false)
    { }

    template<std::input_iterator _Iter, std::sentinel_for<_Iter> _Sent, typename _Proj = std::identity>
    constexpr
    XorBasis(_Iter __first, _Sent __last, _Proj __proj = {}) noexcept
        : XorBasis()
    { insert(__first, __last, __proj); }

    template<std::ranges::input_range _Range, typename _Proj = std::identity>
    constexpr
    XorBasis(_Range&& __r, _Proj __proj = {}) noexcept
        : XorBasis()
    { insert(std::forward<_Range>(__r), __proj); }

    constexpr
    XorBasis(std::initializer_list<value_type> __list) noexcept
        : XorBasis()
    { insert(__list); }


    [[nodiscard]] constexpr bool
    operator==(const XorBasis& __other) const noexcept
    { return _M_zero == __other._M_zero and std::ranges::equal(_M_basis, __other._M_basis, {}, _S_check); }

    [[nodiscard]] constexpr bool
    operator!=(const XorBasis& __other) const noexcept
    { return not (*this == __other); }


    [[nodiscard]] static constexpr size_type
    bit_count() noexcept
    { return sizeof(value_type) * 8; }

    [[nodiscard]] constexpr size_type
    size() const noexcept
    { return _M_size; }

    [[nodiscard]] constexpr bool
    empty() const noexcept
    { return not _M_size; }

    [[nodiscard]] constexpr bool
    operator not() const noexcept
    { return static_cast<bool>(_M_size); }

    [[nodiscard]] constexpr size_type
    count() const noexcept
    { return (1 << _M_size) - not _M_zero; }

    [[nodiscard]] constexpr auto
    view() const noexcept
    { return _M_basis | std::views::filter([](value_type i) -> bool { return static_cast<bool>(i); }); }

    constexpr void
    clear() noexcept
    {
        _M_basis.fill(value_type{});
        _M_size = size_type{};
        _M_zero = false;
    }

    constexpr bool
    insert(value_type __value) noexcept
    {
        for (size_type i = static_cast<size_type>(_M_basis.size()); i--; )
        {
            if (_S_take(__value, i))
            {
                if (_S_check(_M_basis[i]))
                {
                    __value ^= _M_basis[i];
                }
                else
                {
                    _M_basis[i] = __value;
                    ++_M_size;
                    return true;
                }
            }
        }

        _M_zero = true;
        return false;
    }

    template<std::input_iterator _Iter, std::sentinel_for<_Iter> _Sent, typename _Proj = std::identity>
    constexpr size_type
    insert(_Iter __first, _Sent __last, _Proj __proj = {}) noexcept
    {
        size_type n{};

        for (; __first != __last; ++__first)
        {
            n += insert(std::invoke(__proj, *__first));
        }

        return n;
    }

    template<std::ranges::input_range _Range, typename _Proj = std::identity>
    constexpr size_type
    insert(_Range&& __r, _Proj __proj = {})
    { return insert(std::ranges::begin(__r), std::ranges::end(__r), __proj); }

    constexpr void
    normalize() noexcept
    {
        for (size_type i = static_cast<size_type>(_M_basis.size()); i--; )
        {
            if (_S_check(_M_basis[i]))
            {
                for (size_type j = i; j--; )
                {
                    if (_S_check(_M_basis[j]))
                    {
                        _M_basis[i] ^= _M_basis[j];
                    }
                }
            }
        }
    }

    [[nodiscard]] constexpr bool
    contains(value_type __value) const noexcept
    {
        if (not _S_check(__value))
        {
            return _M_zero;
        }

        for (size_type i = static_cast<size_type>(_M_basis.size()); i--; )
        {
            if (_S_take(__value, i))
            {
                if (_S_check(_M_basis[i]))
                {
                    __value ^= _M_basis[i];
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }

    [[nodiscard]] constexpr value_type
    find_min_xor_sum() const noexcept
    { return _M_zero ? value_type{} : *std::ranges::find(_M_basis, true, _S_check); }

    [[nodiscard]] constexpr value_type
    find_max_xor_sum() const noexcept
    {
        value_type max{};

        for (size_type i = static_cast<size_type>(_M_basis.size()); i--; )
        {
            if (_S_check(_M_basis[i]) and not _S_take(max, i))
            {
                max ^= _M_basis[i];
            }
        }

        return max;
    }

    [[nodiscard]] constexpr value_type
    find_kth_smallest(size_type __k) const noexcept
    {
        assert(__k >= 0 and __k < count());

        if (_M_zero)
        {
            if (__k == 0)
            {
                return value_type{};
            }
        }
        else
        {
            ++__k;
        }

        value_type result{};
        size_type  cnt = 1 << _M_size - 1;

        for (size_type i = static_cast<size_type>(_M_basis.size()); i--; )
        {
            if (_S_check(_M_basis[i]))
            {
                if (__k >= cnt)
                {
                    if (not _S_take(result, i))
                    {
                        result ^= _M_basis[i];
                    }
                    
                    __k -= cnt;
                }
                else if (_S_take(result, i))
                {
                    result ^= _M_basis[i];
                }

                cnt >>= 1;
            }
        }

        return result;
    }

    [[nodiscard]] constexpr value_type
    find_kth_largest(size_type __k) const noexcept
    {
        assert(count() >= 1 + __k);
        return find_kth_smallest(count() - 1 - __k);
    }

    [[nodiscard]] constexpr value_type
    find_kth_smallest_after_normalization(size_type __k) const noexcept
    {
        assert(__k >= 0 and __k < count());

        if (_M_zero)
        {
            if (__k == 0)
            {
                return value_type{};
            }
        }
        else
        {
            ++__k;
        }

        value_type result{};

        for (size_type i = 0; i < static_cast<size_type>(_M_basis.size()); ++i)
        {
            if (_S_check(_M_basis[i]))
            {
                if (__k & 1)
                {
                    result ^= _M_basis[i];
                }

                __k >>= 1;
            }
        }

        return result;
    }

    [[nodiscard]] constexpr value_type
    find_kth_largest_after_normalization(size_type __k) const noexcept
    {
        assert(count() >= 1 + __k);
        return find_kth_smallest_after_normalization(count() - 1 - __k);
    }

    [[nodiscard]] constexpr size_type
    count_le(const value_type& __value) const noexcept
    {
        if (__value <= 0)
        {
            return size_type{};
        }
        else if (_M_size == 0)
        {
            return _M_zero;
        }

        value_type result{};
        size_type cnt = 1 << _M_size - 1;

        value_type mask{};

        for (size_type i = static_cast<size_type>(_M_basis.size()); i--; )
        {
            if (_S_check(_M_basis[i]))
            {
                if (_S_take(__value, i))
                {
                    result += cnt;

                    if (not _S_take(mask, i))
                    {
                        mask ^= _M_basis[i];
                    }
                }
                else if (_S_take(mask, i))
                {
                    mask ^= _M_basis[i];
                }

                cnt >>= 1;
            }
            else if (const auto lb = _S_take(__value, i), rb = _S_take(mask, i); lb != rb)
            {
                if (lb)
                {
                    result += cnt << 1;
                }

                break;
            }
        }

        return result - not _M_zero;
    }

    [[nodiscard]] constexpr size_type
    count_leq(const value_type& __value) const noexcept
    { return count_le(__value) + contains(__value); }

    [[nodiscard]] constexpr size_type
    count_ge(const value_type& __value) const noexcept
    { return count() - count_leq(__value); }

    [[nodiscard]] constexpr size_type
    count_geq(const value_type& __value) const noexcept
    { return count() - count_le(__value); }


    [[nodiscard]] constexpr std::optional<value_type>
    prev_less(const value_type& __value, size_type __n = 1) const noexcept
    {
        if (__n == 0) [[unlikely]]
        {
            if (contains(__value))
            {
                return __value;
            }
            else
            {
                return std::nullopt;
            }
        }

        if (const size_type cid = count_le(__value); cid >= __n) [[likely]]
        {
            return find_kth_smallest(cid - __n);
        }
        else [[unlikely]]
        {
            return std::nullopt;
        }
    }

    [[nodiscard]] constexpr std::optional<value_type>
    next_greater(const value_type& __value, size_type __n = 1) const noexcept
    {
        if (__n == 0) [[unlikely]]
        {
            if (contains(__value))
            {
                return __value;
            }
            else
            {
                return std::nullopt;
            }
        }

        if (const size_type cid = count_ge(__value); cid >= __n) [[likely]]
        {
            return find_kth_largest(cid - __n);
        }
        else [[unlikely]]
        {
            return std::nullopt;
        }
    }

    [[nodiscard]] constexpr value_type
    operator[](std::make_signed_t<size_type> __n) const noexcept
    { return __n >= 0 ? find_kth_smallest(size_type(__n)) : find_kth_largest(size_type(-__n - 1)); }


    constexpr void
    merge(const XorBasis& __other) noexcept
    {
        for (size_type i = 0; i < static_cast<size_type>(_M_basis.size()); ++i)
        {
            if (_S_check(__other._M_basis[i]))
            {
                insert(__other._M_basis[i]);
            }
        }

        if (__other._M_zero)
        {
            _M_zero = true;
        }
    }

    constexpr XorBasis&
    operator|=(const XorBasis& __other) noexcept
    { return merge(__other), *this; }

    [[nodiscard]] constexpr XorBasis
    operator|(const XorBasis& __other) const noexcept
    { return XorBasis(*this) |= __other; }

protected:

    [[nodiscard]] static constexpr bool
    _S_check(const value_type& __value) noexcept
    {
        if constexpr (std::convertible_to<value_type, bool>)
        {
            return static_cast<bool>(__value);
        }
        else
        {
            return not (__value == value_type{});
        }
    }

    [[nodiscard]] static constexpr bool
    _S_take(const value_type& __value, size_type __i) noexcept
    {
        if constexpr (requires{ {__value[__i] } -> std::convertible_to<bool>; })
        {
            return __value[__i];
        }
        else
        {
            return __value >> __i & 1;
        }
    }

private:

    std::array<value_type, bit_count()> _M_basis;
    size_type _M_size;
    bool _M_zero;
};

template<std::input_iterator _Iter, std::sentinel_for<_Iter> _Sent, typename _Proj = std::identity>
XorBasis(_Iter, _Sent, _Proj = {}) -> XorBasis<std::remove_reference_t<std::invoke_result_t<_Proj, std::iter_reference_t<_Iter>>>>;

template<std::ranges::input_range _Range, typename _Proj = std::identity>
XorBasis(_Range&&, _Proj = {}) -> XorBasis<std::remove_reference_t<std::invoke_result_t<_Proj, std::iter_reference_t<decltype(std::ranges::begin(std::declval<_Range>()))>>>>;

template<std::size_t _Size>
[[nodiscard]] constexpr std::strong_ordering
operator<=>(const std::bitset<_Size>& __lhs, const std::bitset<_Size>& __rhs) noexcept
{
    constexpr auto n = sizeof(std::bitset<_Size>);

    if constexpr (n % sizeof(std::uint64_t) == 0)
    {
        constexpr auto c = n / sizeof(std::uint64_t);

        auto lptr = reinterpret_cast<const std::uint64_t*>(&__lhs) + c - 1;
        auto rptr = reinterpret_cast<const std::uint64_t*>(&__rhs) + c - 1;

        for (auto i = 0; i < c; ++i, --lptr, --rptr)
        {
            if (*lptr != *rptr)
            {
                return *lptr < *rptr ? std::strong_ordering::less : std::strong_ordering::greater;
            }
        }
    }
    else
    {
        constexpr auto c = n / sizeof(std::uint32_t);

        auto lptr = reinterpret_cast<const std::uint32_t*>(&__lhs) + c - 1;
        auto rptr = reinterpret_cast<const std::uint32_t*>(&__rhs) + c - 1;

        for (auto i = 0; i < c; ++i, --lptr, --rptr)
        {
            if (*lptr != *rptr)
            {
                return *lptr < *rptr ? std::strong_ordering::less : std::strong_ordering::greater;
            }
        }
    }

    return std::strong_ordering::equivalent;
}
}

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
        uint32 n, q;
        std::cin >> n >> q;

        std::vector<uint32> v(n + 1);

        for (uint32 i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
        }

        std::vector<uint32> maxr(n + 1);
        std::iota(maxr.begin(), maxr.end(), uint32{});

        XorBasis<uint32> basis;
        std::set<uint32> ids;

        for (uint32 l = n; l >= 1; --l)
        {
            ids.insert(l);

            if (not basis.insert(v[l]))
            {
                basis.clear();
                
                auto tids = std::move(ids);

                for (const uint32& i : tids)
                {
                    if (basis.insert(v[i]))
                    {
                        ids.insert(i);
                    }
                }
            }

            std::pair<uint32, uint32> last{l, 0};
            XorBasis<uint32> cbasis{v[l]};

            auto check = [&](uint32 mid) -> bool
            {
                if (mid == l)
                {
                    return true;
                }
                else
                {
                    return cbasis.next_greater(last.second, mid - last.first).has_value();
                }
            };

            ids.insert(n + 1);

            for (const uint32& i : ids | std::views::drop(1))
            {
                auto pos = *std::ranges::lower_bound(std::views::iota(last.first, i) | std::views::reverse, true, {}, check);

                maxr[l] = pos;
                
                if (pos != i - 1)
                {
                    break;
                }
                
                last.second = cbasis.next_greater(last.second, pos - last.first).value_or(last.second);
                last.first = i - 1;

                cbasis.insert(v[i]);
            }

            ids.erase(n + 1);
        }

        while (q--)
        {
            uint32 l, r;
            std::cin >> l >> r;

            if (r <= maxr[l])
            {
                std::cout << "YES\n";
            }
            else
            {
                std::cout << "NO\n";
            }
        }
    }

    return 0;
}