/**
 * Educational Codeforces Round 177 (Rated for Div. 2)
 * 
 * => E. Zebra-like Numbers ( @c 2400 )
 * 
 * -> https://codeforces.com/contest/2086/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2086/submission/318089676 By huanhuanonly
 * 
 * @b Digit-DP
 * 
 * ----May 02, 2025 [18h:08m:46s]----
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

uint64 dfs(uint64 n, uint64 k)
{
	static std::map<std::pair<uint64, uint64>, uint64> mp;

	static const auto&& st = [] {
		std::set<uint64, std::greater<uint64>> st;
		
		for (uint64 i = 1; i <= 1e18; i = i << 2 | 1)
		{
			st.insert(i);
		}

		return st;
	}();

	if (auto it = mp.find({n, k}); it != mp.end())
	{
		return it->second;
	}

	if (k > 4 * st.size() or n < k or n == 0 or k == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return k == 1;
	}
	else if (k == 1)
	{
		return std::distance(st.lower_bound(n), st.end());
	}

	uint64 mid = *st.lower_bound(n);

	auto& value = mp[{n, k}];

	if (n > mid)
	{
		value += dfs(n - mid, k - 1);
	}

	value += dfs(mid - 1, k);

	return value;
}

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
		uint64 l, r, k;
		std::cin >> l >> r >> k;

		std::cout << dfs(r, k) - dfs(l - 1, k) << '\n';
	}

	return 0;
}