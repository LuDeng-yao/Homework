/*********************************
 * 韩梅梅喜欢满宇宙到处逛街。现在她逛到了一家火星店里
 * 发现这家店有个特别的规矩：你可以用任何星球的硬币付钱，但是绝不找零，当然也不能欠债。
 * 韩梅梅手边有 10^4枚来自各个星球的硬币，需要请你帮她盘算一下，是否可能精确凑出要付的款额。

 * 输入格式：
 * 输入第一行给出两个正整数：N（≤10^4）是硬币的总个数，M（≤10^2）是韩梅梅要付的款额。
 * 第二行给出 N 枚硬币的正整数面值。数字间以空格分隔。

 * 输出格式：
 * 在一行中输出硬币的面值 V1 ≤V2 ≤⋯≤Vk ，满足条件 V1 +V2 +...+Vk =M。
 * 数字间以 1 个空格分隔，行首尾不得有多余空格。若解不唯一，则输出最小序列。若无解，则输出 No Solution。

 * 注：我们说序列{ A[1],A[2],⋯ }比{ B[1],B[2],⋯ }“小”，
 * 是指存在 k≥1 使得 A[i]=B[i] 对所有 i<k 成立，并且 A[k]<B[k]。
*********************************/
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int f[10005];
int num = 0, n, m;
int flag = 0;
int road[10005];
int cnt = 0;

void bfs(int r, int sum)
{
    if (sum > m || flag)
        return;
    if (sum == m)
    {
        flag = 1;
        for (int i = 0; i < cnt; i++)
            printf(i == cnt - 1 ? "%d" : "%d ", road[i]);
        cout << endl;
        return;
    }
    for (int i = r + 1; i < num; i++)
    {
        road[cnt++] = f[i];
        bfs(i, sum + f[i]);
        cnt--;
        if (flag)
            break;
    }
    return;
}

int main()
{
    cin >> n >> m; //硬币总数n,待付款额m
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (t <= m)
        {
            f[num++] = t;
            sum += t;
        }
    }
    if (sum < m)
    {
        cout << "No Solution" << endl;
        return 0;
    }
    sort(f, f + num);
    bfs(-1, 0);
    if (!flag)
        cout << "No Solution" << endl;
    return 0;
}
