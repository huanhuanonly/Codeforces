/**
 * => P3174 [HAOI2009] 毛毛虫
 * 
 * -> https://www.luogu.com.cn/problem/P3174
 * 
 * @b Tree
*/

#include <bits/stdc++.h>

using uint    = unsigned int;
using llong   = long long int;
using ullong  = unsigned long long int;
using ldouble = long double;

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __localhost
	::freopen("in", "r", stdin);
	::freopen("out", "w", stdout);
#endif

	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> e(n + 1);

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		std::cin >> u >> v;

		e[u].push_back(v);
		e[v].push_back(u);
	}

	int ans = 0;

	std::function<int(int, int)> dfs = [&](int u, int fa) -> int
	{
		std::vector<int> v;
		v.reserve(e[u].size());

		int cnt = 0;

		for (const auto& i : e[u])
		{
			if (i == fa)
				continue;

			v.push_back(dfs(i, u));
			++cnt;
		}

		std::sort(v.begin(), v.end(), std::greater<int>());

		if (cnt >= 2)
		{
			ans = std::max<int>(ans, v[0] + v[1] + cnt - 2 + 1 + !!fa);
		}

		if (cnt >= 1)
		{
			ans = std::max<int>(ans, v.front() + cnt - 1 + 1 + !!fa);
		}

		return v.empty() ? 1 : v.front() + cnt - 1 + 1;
	};

	std::cout << std::max(dfs(1, 0), ans);

	return 0;
}