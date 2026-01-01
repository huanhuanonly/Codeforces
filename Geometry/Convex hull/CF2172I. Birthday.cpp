/**
 * 2025 ICPC Asia Taichung Regional Contest (Unrated, Online Mirror, ICPC Rules, Preferably Teams)
 * 
 * => I. Birthday ( @c 2000 )
 * 
 * -> https://codeforces.com/contest/2172/problem/I
 * 
 * Submissions ~> https://codeforces.com/contest/2172/submission/355197045 By huanhuanonly
 * 
 * @b Geometry ( @a convex-hull )
 * 
 * ----December 26, 2025 [23h:58m:52s]----
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

    int64 n, r;
    std::cin >> n >> r;

    struct point : std::pair<int64, int64>
    {
        using std::pair<int64, int64>::pair;

        point operator-(const point& other) const noexcept
        {
            return {first - other.first, second - other.second};
        }
    };

    auto cross_product = [](const point& lhs, const point& rhs) -> int64
    {
        return (lhs.first * rhs.second) - (lhs.second * rhs.first);
    };

    auto slope = [](const point& lhs, const point& rhs) -> real64
    {
        return real64(rhs.second - lhs.second) / (rhs.first - lhs.first);
    };

    std::vector<point> v(n);

    for (auto& [x, y] : v)
    {
        std::cin >> x >> y;
    }

    v.emplace_back(0, 0);

    std::ranges::sort(v);

    std::vector<point> hull;
    hull.reserve(v.size());

    real64 ans = 0;

    auto update = [&, total_area = std::numbers::pi_v<real64> * r * r]() -> void
    {
        if (hull.size() == 1)
        {
            ans = std::max(ans, total_area / 2);
            return;
        }

        for (int i = 1; i < hull.size(); ++i)
        {
            const auto d = [&]() -> real64
            {
                if (hull[i].first == hull[i - 1].first)
                {
                    return std::fabs(hull[i].first);
                }
                else
                {
                    const auto k = slope(hull[i - 1], hull[i]);
                    return std::fabs(hull[i].first * k - hull[i].second) / std::sqrt(k * k + 1);
                }
            }();

            const auto h = r - d;

            const auto area = std::acos(d / r) * r * r - d * std::sqrt(2 * r * h - h * h);
            ans = std::max(ans, std::min(area, total_area));
        }
    };

    for (const auto& i : v)
    {
        for (; hull.size() >= 2 and cross_product(hull[hull.size() - 2] - hull.back(), i - hull.back()) >= 0; hull.pop_back());
        hull.push_back(i);
    }

    update();
    hull.clear();

    for (const auto& i : v)
    {
        for (; hull.size() >= 2 and cross_product(hull[hull.size() - 2] - hull.back(), i - hull.back()) <= 0; hull.pop_back());
        hull.push_back(i);
    }

    update();

    std::cout << std::fixed << std::setprecision(12) << ans;

    return 0;
}