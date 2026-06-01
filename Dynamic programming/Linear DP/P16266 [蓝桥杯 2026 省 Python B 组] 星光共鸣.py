# 蓝桥杯省赛自测（Python B 组）
# 
# => P16266 [蓝桥杯 2026 省 Python B 组] 星光共鸣 ( @c 普及/提高− )
# 
# -> https://www.luogu.com.cn/problem/P16266
# 
# Submissions ~> https://www.luogu.com.cn/record/273914110 By huanhuanonly
# 
# @b Linear-DP
# 
# ----April 13, 2026 [22h:30m:56s]----

n, k = map(int, input().split())

mod = 10 ** 9 + 7

dp = [[0] * (k + 1) for i in range(n + 2)]

dp[0][0] = 1

for i in range(n + 1):
    for ck in range(k + 1):
        dp[i][ck] %= mod
        for j in range(i + 1, n + 2):
            dp[j][min(k, ck + (j - i - 1) * (j - i) // 2)] += dp[i][ck]

print(dp[n + 1][k] % mod)
