# 网络流
---

## [上下界网络流](https://www.luogu.com/article/gprgncve)

### 无源上下界可行流

> 通过原网络构建差网络  
>> $flow=flow_{upperBound}-flow_{lowerBound}$  

> 新建一个源点 $s$ 和汇点 $t$  
> 连接 $s$ 可以进行增流，被连接的结点的出流将会增加，连接汇点的入流将会增加  
> 从源点 $s$ 到汇点 $t$ 跑最大流后，`残留网络` 将会满足 `流量守恒`，得到 `可行流`

### 有源上下界可行流

> _link_ $T\rightarrow^{inf}_0{S}$ 构成 `循环流`
> 源汇不需要满足 `流量守恒`，直接转换成 *无源上下界可行流*

### 有源上下界最大流

> $=$ `可行流` $+$ `增流`
> `可行流` 是一个 `循环流`，在 `残留网络` 上再次跑 `最大流` 一定不会降低原来的流量，
> 需要先清空 `附加边` 的流量，只需要将 $T\rightarrow^{inf}_0{S}$ 的流量设置为 $0$ 即可

### 有源上下界最小流

> 从 $T$ 向 $S$ 跑 `最大流`

### 最小费用最大流（有负费用）

[参考文献](https://blog.panda2134.site/%E6%80%BB%E7%BB%93/2018/02/26/NetworkFlow/#%E6%9C%80%E5%B0%8F%E8%B4%B9%E7%94%A8%E5%8F%AF%E8%A1%8C%E6%B5%81)

> 使用 **上下界网络流** 中的 `强制满流` 技术， 先将负费用的边反向连接使其 `预先满流`  
>> $u\rightarrow^{+flow}_{-cost}v$ _change to_ $u \leftarrow^{+flow}_{+cost}v$
```c++
for (int i = 1; i <= m; ++i)
{
    int u, v, w, c;
    std::cin >> u >> v >> w >> c;

    if (c >= 0)
    {
        add_edge(u, v, w, c);
    }
    else
    {
        add_edge(v, u, w, -c);

        inout[u] -= w;
        inout[v] += w;

        cost += w * c;
    }
}
```
> 这同等于从 $u$ 输送了 $\vert{cost}\vert$ 的流量到 $v$，但是为了 `流量守恒`，需要从 $v$ 送回 $\vert{cost}\vert$ 的流量到 $u$  
> 新建一个源点 $s$ 和汇点 $t$， 然后
>> _link_ $s\rightarrow{v}$ and $u\rightarrow{t}$ 
```c++
for (int i = 1; i <= n; ++i)
{
    if (inout[i] > 0)
        add_edge(s, i, inout[i], 0);
    else if (inout[i] < 0)
        add_edge(i, t, -inout[i], 0);
}
```
> 此时已经没有负费用，以源点 $s$ 到汇点 $t$ 跑最小费用最大流并计算费用，使得满足 `流量平衡`，得到 `残留网络`，  
> 保留费用，以源点 $S$ 到汇点 $T$ 跑最小费用最大流，得到最终的最大流和最小费用

Warning:  

可能会得到一个或多个 `循环流` 不经过源点或汇点，这个 `循环流` 的费用是负的，将会计入最终费用中，不会影响 `最大流`，`最大流` 的流量一定是从源点到汇点的

这个问题暂时无法在 `多项式` 的时间复杂度内解决